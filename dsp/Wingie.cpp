#include "Wingie.h"
#include <od/config.h>
#include <hal/ops.h>
Wingie::Wingie() : DSP()
{
  UI uiParams(this);

  addInput(mInL);
  addInput(mInR);
  addOutput(mOutL);
  addOutput(mOutR);
  addParameter(mDecay);
  addParameter(mFreq);
  addParameter(mInGain);
  addParameter(mLeftThreshold);
  addParameter(mMix);
  addParameter(mMode);
  addParameter(mNote);
  addParameter(mNote1);
  addParameter(mNote2);
  addParameter(mOutGain);
  addParameter(mRightThreshold);
  addParameter(menv_mode_change_decay);
  DSP.init(globalConfig.sampleRate);
  DSP.buildUserInterface(&uiParams);
}
Wingie::~Wingie()
{ }
void Wingie::process()
{
  FAUSTFLOAT* inputs[] = { mInL.buffer(), mInR.buffer() };
  FAUSTFLOAT* outputs[] = { mOutL.buffer(), mOutR.buffer() };
  *ffDecay = CLAMP(mDecay.target(), 0.1, 10);
  *ffFreq = CLAMP(mFreq.target(), 0, 24000);
  *ffInGain = CLAMP(mInGain.target(), 0, 1);
  *ffLeftThreshold = CLAMP(mLeftThreshold.target(), 0, 1);
  *ffMix = CLAMP(mMix.target(), 0, 1);
  *ffMode = CLAMP(mMode.target(), 0, 3);
  *ffNote = CLAMP(mNote.target(), -1, 1);
  *ffNote1 = CLAMP(mNote1.target(), -1, 1);
  *ffNote2 = CLAMP(mNote2.target(), -1, 1);
  *ffOutGain = CLAMP(mOutGain.target(), 0, 1);
  *ffRightThreshold = CLAMP(mRightThreshold.target(), 0, 1);
  *ffenv_mode_change_decay = CLAMP(menv_mode_change_decay.target(), 0, 1);
  DSP.compute(FRAMELENGTH, inputs, outputs);
}

