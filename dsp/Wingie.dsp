declare name        "Wingie";
declare version     "2.0";
declare author      "Meng Qi";
declare license     "BSD";
declare copyright   "(c)Meng Qi 2020";
declare date		"2020-09-30";
declare editDate    "2021-12-03";

//-----------------------------------------------
// Wingie
//-----------------------------------------------

import("stdfaust.lib"); 

nHarmonics = 9;
decay = hslider("Decay", 5, 0.1, 10, 0.01) : si.smoo;
output_gain = 1 : ba.lin2LogGain;

// Name the ins and outs of the `process` function for use in the er-301 object
declare er301_in1 "InL";
declare er301_in2 "InR";
declare er301_out1 "OutL";
declare er301_out2 "OutR";

// POLY_MODE 0
// STRING_MODE 1
// BAR_MODE 2
// CAVE_MODE 3

left_threshold = hslider("LeftThreshold", 0.1, 0, 1, 0.01);
right_threshold = hslider("RightThreshold", 0.1, 0, 1, 0.01);
amp_follower_decay = 0.025;

mode0 = hslider("LMode", 0, 0, 3, 1);
mode1 = hslider("RMode", 0, 0, 3, 1);
env_mode_change_decay = hslider("env_mode_change_decay", 0.5, 0, 1, 0.01);
env_mode_change = 1 - en.ar(0.002, env_mode_change_decay, mode0 != mode0' | mode1 != mode1');

resonator_input_gain = hslider("InGain", 0.25, 0, 1, 0.01) : ba.lin2LogGain;
resonator_output_gain = hslider("OutGain", 0.25, 0, 1, 0.01) : ba.lin2LogGain;
//hp_cutoff = hslider("hp_cutoff", 85, 35, 500, 0.1);

volume0 = hslider("LeftGain", 0.25, 0, 1, 0.01) : ba.lin2LogGain : si.smoo;
volume1 = hslider("RightGain", 0.25, 0, 1, 0.01) : ba.lin2LogGain : si.smoo;

mix0 = hslider("Mix", 1, 0, 1, 0.01) : si.smoo;

vol_wet0 = mix0;
vol_dry0 = (1 - mix0);
vol_wet1 = mix0;
vol_dry1 = (1 - mix0);

freq = hslider("Freq", 0, 0, 24000, 1);
vpo2hz(vpo) = freq * pow(2., 120 * vpo / 12);

note0 = hslider("Note", 0, -1, 1, 1) : vpo2hz;
note1 = hslider("Note1", 0.05, -1, 1, 0.01) : vpo2hz; //Only used in POLY mode (0)
note2 = hslider("Note2", 0.1, -1, 1, 0.01) : vpo2hz; //Only used in POLY mode (0);

env_mute(t) = 1 - en.asr(0.25, 1., 0.25, t);

bar_factor = 0.44444;
bar_ratios(freq, n) = freq * bar_factor * pow((n + 1) + 0.5, 2);
int_ratios(freq, n) = freq * (n + 1);

//odd_ratios(freq, n) = freq * (2 * n + 1);
//cymbal_808(n) = 130.812792, 193.957204, 235.501256, 333.053319, 344.076511, 392.438376, 509.742979, 581.871611, 706.503769, 999.16, 1032.222378, 1529.218338: ba.selectn(12, n); // chromatic
req(n) = 62, 115, 218, 411, 777, 1500, 2800, 5200, 11000 : ba.selectn(nHarmonics, n);

poly(n, a, b, c) = a, a * 2, a * 3, b, b * 2, b * 3, c, c * 2, c * 3 : ba.selectn(nHarmonics, n);

//bianzhong(n) = 212.3, 424.6, 530.8, 636.9, 1061.6, 1167.7, 2017.0, 2335.5, 2653.9, 3693 : ba.selectn(10, n);
//cymbal_808(n) = 205.3, 304.4, 369.6, 522.7, 540, 615.9, 800, 913.2, 1108.8, 1568.1 : ba.selectn(10, n); // original
//circular_membrane_ratios(n) = 1, 1.59, 2.14, 2.30, 2.65, 2.92, 3.16, 3.50, 3.60, 3.65 : ba.selectn(10, n);

f(note, note1, note2, n, s) = 
    poly(n, note, note1, note2),
    int_ratios(note, n),
    bar_ratios(note, n),
    req(n)
    : ba.selectn(4, s);

r(note, note1, note2, index, source) = pm.modeFilter(a, b, ba.lin2LogGain(c))
  with
{
  a = min(f(note, note1, note2, index, source), 16000);
  b = env_mode_change * decay + 0.05;
  c = env_mute(button("mute_%index"));
};

process = _,_
  : fi.dcblocker,
    fi.dcblocker
  : ( _ <: attach( _, _ : an.amp_follower(amp_follower_decay) : _ > left_threshold : hbargraph("left_trig", 0, 1))),
    ( _ <: attach(_, _ : an.amp_follower(amp_follower_decay) : _ > right_threshold : hbargraph("right_trig", 0, 1)))
  : (_ * env_mode_change), (_ * env_mode_change)
  <: (
      _ * resonator_input_gain : _ * vol_wet0 : fi.lowpass(1, 4000)
      <: sum(i, nHarmonics, r(note0, note1, note2, i, mode0)) * resonator_output_gain
    ),
    (
      _ * resonator_input_gain : _ * vol_wet1 : fi.lowpass(1, 4000)
      <: sum(i, nHarmonics, r(note0, note1, note2, i, mode1)) * resonator_output_gain
    ),
    _,
    _
  : ef.cubicnl(0.01, 0),
    ef.cubicnl(0.01, 0),
    _,
    _
  : _ * vol_wet0,
    _ * vol_wet1,
    _ * vol_dry0,
    _ * vol_dry1
  :> (_ * output_gain),
     (_ * output_gain)
      ;