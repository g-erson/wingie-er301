/* ------------------------------------------------------------
author: "Meng Qi"
copyright: "(c)Meng Qi 2020"
license: "BSD"
name: "Wingie"
version: "2.0"
Code generated with Faust 2.31.1 (https://faust.grame.fr)
Compilation options: -lang cpp -es 1 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __DspWingie_H__
#define  __DspWingie_H__


#include <string.h>
#include <od/objects/Object.h>

#define FAUSTFLOAT float

#ifndef SWIGLUA

#ifndef __FAUST_301_BOILERPLATE__
#define __FAUST_301_BOILERPLATE__

class dsp {};

class ParametersSetter {
public:
  virtual void addParam(const char* label, FAUSTFLOAT* zone) = 0;
};

struct Meta {
  virtual void declare(const char* key, const char* value) {};
};

struct Soundfile {
  FAUSTFLOAT** fBuffers;
  int* fLength;   // length of each part
  int* fSR;       // sample rate of each part
  int* fOffset;   // offset of each part in the global buffer
  int fChannels;  // max number of channels of all concatenated files
};

class UI {
public:
  UI(ParametersSetter *_ps) {
    ps = _ps;
  }

  // -- widget's layouts
  virtual void openTabBox(const char* label) {}
  virtual void openHorizontalBox(const char* label) {}
  virtual void openVerticalBox(const char* label) {}
  virtual void closeBox() {}

  // -- active widgets
  virtual void addButton(const char* label, FAUSTFLOAT* zone) {
    ps->addParam(label, zone);
  }
  virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) {
    ps->addParam(label, zone);
  }
  virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {
    ps->addParam(label, zone);
  }
  virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {
    ps->addParam(label, zone);
  }
  virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) {
    ps->addParam(label, zone);
  }

  // -- passive widgets
  virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}
  virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) {}

  // -- soundfiles
  virtual void addSoundfile(const char* label, const char* filename, Soundfile** sf_zone) {}

  // -- metadata declarations
  virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) {}

private:
  ParametersSetter *ps;
};
#endif

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

static float DspWingie_faustpower2_f(float value) {
	return (value * value);
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS DspWingie
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class DspWingie : public dsp {
	
 private:
	
	FAUSTFLOAT fHslider0;
	float fRec0[2];
	FAUSTFLOAT fHslider1;
	int fSampleRate;
	float fConst0;
	float fConst2;
	FAUSTFLOAT fHslider2;
	float fVec0[2];
	float fRec4[2];
	float fConst3;
	float fConst4;
	float fRec3[2];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHbargraph0;
	float fConst5;
	float fConst6;
	FAUSTFLOAT fHslider4;
	float fVec1[2];
	int iRec5[2];
	FAUSTFLOAT fHslider5;
	float fVec2[2];
	float fConst7;
	float fRec2[2];
	float fConst8;
	FAUSTFLOAT fHslider6;
	float fRec6[2];
	float fConst9;
	FAUSTFLOAT fHslider7;
	FAUSTFLOAT fHslider8;
	float fRec1[3];
	float fConst10;
	FAUSTFLOAT fButton0;
	float fVec3[2];
	float fRec7[2];
	int iRec8[2];
	FAUSTFLOAT fHslider9;
	float fRec9[3];
	FAUSTFLOAT fButton1;
	float fVec4[2];
	float fRec10[2];
	int iRec11[2];
	float fRec12[3];
	FAUSTFLOAT fButton2;
	float fVec5[2];
	float fRec13[2];
	int iRec14[2];
	float fRec15[3];
	FAUSTFLOAT fButton3;
	float fVec6[2];
	float fRec16[2];
	int iRec17[2];
	float fRec18[3];
	FAUSTFLOAT fButton4;
	float fVec7[2];
	float fRec19[2];
	int iRec20[2];
	float fRec21[3];
	FAUSTFLOAT fButton5;
	float fVec8[2];
	float fRec22[2];
	int iRec23[2];
	FAUSTFLOAT fHslider10;
	float fRec24[3];
	FAUSTFLOAT fButton6;
	float fVec9[2];
	float fRec25[2];
	int iRec26[2];
	float fRec27[3];
	FAUSTFLOAT fButton7;
	float fVec10[2];
	float fRec28[2];
	int iRec29[2];
	float fRec30[3];
	FAUSTFLOAT fButton8;
	float fVec11[2];
	float fRec31[2];
	int iRec32[2];
	float fVec12[2];
	float fRec36[2];
	float fRec35[2];
	FAUSTFLOAT fHslider11;
	FAUSTFLOAT fHbargraph1;
	float fVec13[2];
	float fRec34[2];
	float fRec33[3];
	float fRec37[3];
	float fRec38[3];
	float fRec39[3];
	float fRec40[3];
	float fRec41[3];
	float fRec42[3];
	float fRec43[3];
	float fRec44[3];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.1");
		m->declare("author", "Meng Qi");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.1");
		m->declare("compile_options", "-lang cpp -es 1 -single -ftz 0");
		m->declare("copyright", "(c)Meng Qi 2020");
		m->declare("date", "2020-09-30");
		m->declare("editDate", "2021-12-03");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/asr:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "0.1");
		m->declare("er301_in1", "InL");
		m->declare("er301_in2", "InR");
		m->declare("er301_out1", "OutL");
		m->declare("er301_out2", "OutR");
		m->declare("filename", "Wingie.dsp");
		m->declare("filters.lib/dcblocker:author", "Julius O. Smith III");
		m->declare("filters.lib/dcblocker:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/dcblocker:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("filters.lib/zero:author", "Julius O. Smith III");
		m->declare("filters.lib/zero:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/zero:license", "MIT-style STK-4.3 license");
		m->declare("license", "BSD");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.3");
		m->declare("misceffects.lib/name", "Misc Effects Library");
		m->declare("misceffects.lib/version", "2.0");
		m->declare("name", "Wingie");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.1");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("version", "2.0");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	virtual int getInputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	virtual int getOutputRate(int channel) {
		int rate;
		switch ((channel)) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
		}
		return rate;
	}
	
	static void classInit(int sample_rate) {
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSampleRate)));
		float fConst1 = (1.0f / std::tan((12566.3711f / fConst0)));
		fConst2 = (1.0f / (fConst1 + 1.0f));
		fConst3 = std::exp((0.0f - (40.0f / fConst0)));
		fConst4 = (1.0f - fConst3);
		fConst5 = std::max<float>(1.0f, (0.00200000009f * fConst0));
		fConst6 = (1.0f / fConst5);
		fConst7 = (1.0f - fConst1);
		fConst8 = (1.0f / fConst0);
		fConst9 = (6.28318548f / fConst0);
		fConst10 = (1.0f / std::max<float>(1.0f, (0.25f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(1.0f);
		fHslider1 = FAUSTFLOAT(0.25f);
		fHslider2 = FAUSTFLOAT(0.25f);
		fHslider3 = FAUSTFLOAT(0.10000000000000001f);
		fHslider4 = FAUSTFLOAT(0.0f);
		fHslider5 = FAUSTFLOAT(0.5f);
		fHslider6 = FAUSTFLOAT(5.0f);
		fHslider7 = FAUSTFLOAT(0.0f);
		fHslider8 = FAUSTFLOAT(0.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(0.050000000000000003f);
		fButton1 = FAUSTFLOAT(0.0f);
		fButton2 = FAUSTFLOAT(0.0f);
		fButton3 = FAUSTFLOAT(0.0f);
		fButton4 = FAUSTFLOAT(0.0f);
		fButton5 = FAUSTFLOAT(0.0f);
		fHslider10 = FAUSTFLOAT(0.10000000000000001f);
		fButton6 = FAUSTFLOAT(0.0f);
		fButton7 = FAUSTFLOAT(0.0f);
		fButton8 = FAUSTFLOAT(0.0f);
		fHslider11 = FAUSTFLOAT(0.10000000000000001f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec0[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec4[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec5[l5] = 0;
		}
		for (int l6 = 0; (l6 < 2); l6 = (l6 + 1)) {
			fVec2[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fRec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec6[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 3); l9 = (l9 + 1)) {
			fRec1[l9] = 0.0f;
		}
		for (int l10 = 0; (l10 < 2); l10 = (l10 + 1)) {
			fVec3[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fRec7[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			iRec8[l12] = 0;
		}
		for (int l13 = 0; (l13 < 3); l13 = (l13 + 1)) {
			fRec9[l13] = 0.0f;
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fVec4[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fRec10[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			iRec11[l16] = 0;
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fRec12[l17] = 0.0f;
		}
		for (int l18 = 0; (l18 < 2); l18 = (l18 + 1)) {
			fVec5[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fRec13[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			iRec14[l20] = 0;
		}
		for (int l21 = 0; (l21 < 3); l21 = (l21 + 1)) {
			fRec15[l21] = 0.0f;
		}
		for (int l22 = 0; (l22 < 2); l22 = (l22 + 1)) {
			fVec6[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fRec16[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			iRec17[l24] = 0;
		}
		for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
			fRec18[l25] = 0.0f;
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fVec7[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fRec19[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			iRec20[l28] = 0;
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec21[l29] = 0.0f;
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fVec8[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fRec22[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			iRec23[l32] = 0;
		}
		for (int l33 = 0; (l33 < 3); l33 = (l33 + 1)) {
			fRec24[l33] = 0.0f;
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fVec9[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fRec25[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			iRec26[l36] = 0;
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec27[l37] = 0.0f;
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fVec10[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec28[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			iRec29[l40] = 0;
		}
		for (int l41 = 0; (l41 < 3); l41 = (l41 + 1)) {
			fRec30[l41] = 0.0f;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fVec11[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fRec31[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			iRec32[l44] = 0;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fVec12[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fRec36[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			fRec35[l47] = 0.0f;
		}
		for (int l48 = 0; (l48 < 2); l48 = (l48 + 1)) {
			fVec13[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fRec34[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 3); l50 = (l50 + 1)) {
			fRec33[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 3); l51 = (l51 + 1)) {
			fRec37[l51] = 0.0f;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec38[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 3); l53 = (l53 + 1)) {
			fRec39[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 3); l54 = (l54 + 1)) {
			fRec40[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 3); l55 = (l55 + 1)) {
			fRec41[l55] = 0.0f;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec42[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 3); l57 = (l57 + 1)) {
			fRec43[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 3); l58 = (l58 + 1)) {
			fRec44[l58] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual DspWingie* clone() {
		return new DspWingie();
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("Wingie");
		ui_interface->addHorizontalSlider("Decay", &fHslider6, 5.0f, 0.100000001f, 10.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("Freq", &fHslider7, 0.0f, 0.0f, 24000.0f, 1.0f);
		ui_interface->addHorizontalSlider("InGain", &fHslider2, 0.25f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("LeftThreshold", &fHslider3, 0.100000001f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("Mix", &fHslider0, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("Mode", &fHslider4, 0.0f, 0.0f, 3.0f, 1.0f);
		ui_interface->addHorizontalSlider("Note", &fHslider8, 0.0f, -1.0f, 1.0f, 1.0f);
		ui_interface->addHorizontalSlider("Note1", &fHslider9, 0.0500000007f, -1.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("Note2", &fHslider10, 0.100000001f, -1.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("OutGain", &fHslider1, 0.25f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("RightThreshold", &fHslider11, 0.100000001f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("env_mode_change_decay", &fHslider5, 0.5f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalBargraph("left_trig", &fHbargraph0, 0.0f, 1.0f);
		ui_interface->addButton("mute_0", &fButton0);
		ui_interface->addButton("mute_1", &fButton4);
		ui_interface->addButton("mute_2", &fButton3);
		ui_interface->addButton("mute_3", &fButton2);
		ui_interface->addButton("mute_4", &fButton1);
		ui_interface->addButton("mute_5", &fButton5);
		ui_interface->addButton("mute_6", &fButton6);
		ui_interface->addButton("mute_7", &fButton7);
		ui_interface->addButton("mute_8", &fButton8);
		ui_interface->addHorizontalBargraph("right_trig", &fHbargraph1, 0.0f, 1.0f);
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (0.00100000005f * float(fHslider0));
		float fSlow1 = (1.04712856f * DspWingie_faustpower2_f(float(fHslider1)));
		float fSlow2 = DspWingie_faustpower2_f(float(fHslider2));
		float fSlow3 = float(fHslider3);
		float fSlow4 = float(fHslider4);
		float fSlow5 = (fSlow4 + 1.0f);
		float fSlow6 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider5))));
		float fSlow7 = (0.00100000005f * float(fHslider6));
		int iSlow8 = (fSlow4 >= 2.0f);
		float fSlow9 = float(fHslider7);
		float fSlow10 = (fSlow9 * std::pow(2.0f, (10.0f * float(fHslider8))));
		int iSlow11 = (fSlow4 >= 3.0f);
		float fSlow12 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 62.0f : (0.999989986f * fSlow10)) : fSlow10), 16000.0f)));
		float fSlow13 = float(fButton0);
		int iSlow14 = (fSlow13 == 0.0f);
		int iSlow15 = (fSlow4 >= 1.0f);
		float fSlow16 = (fSlow9 * std::pow(2.0f, (10.0f * float(fHslider9))));
		float fSlow17 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 777.0f : (13.4443102f * fSlow10)) : (iSlow15 ? (5.0f * fSlow10) : (2.0f * fSlow16))), 16000.0f)));
		float fSlow18 = float(fButton1);
		int iSlow19 = (fSlow18 == 0.0f);
		float fSlow20 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 411.0f : (8.99991035f * fSlow10)) : (iSlow15 ? (4.0f * fSlow10) : fSlow16)), 16000.0f)));
		float fSlow21 = float(fButton2);
		int iSlow22 = (fSlow21 == 0.0f);
		float fSlow23 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 218.0f : (5.44438982f * fSlow10)) : (3.0f * fSlow10)), 16000.0f)));
		float fSlow24 = float(fButton3);
		int iSlow25 = (fSlow24 == 0.0f);
		float fSlow26 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 115.0f : (2.77775002f * fSlow10)) : (2.0f * fSlow10)), 16000.0f)));
		float fSlow27 = float(fButton4);
		int iSlow28 = (fSlow27 == 0.0f);
		float fSlow29 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 1500.0f : (18.7775898f * fSlow10)) : (iSlow15 ? (6.0f * fSlow10) : (3.0f * fSlow16))), 16000.0f)));
		float fSlow30 = float(fButton5);
		int iSlow31 = (fSlow30 == 0.0f);
		float fSlow32 = (fSlow9 * std::pow(2.0f, (10.0f * float(fHslider10))));
		float fSlow33 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 2800.0f : (24.9997501f * fSlow10)) : (iSlow15 ? (7.0f * fSlow10) : fSlow32)), 16000.0f)));
		float fSlow34 = float(fButton6);
		int iSlow35 = (fSlow34 == 0.0f);
		float fSlow36 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 5200.0f : (32.1107903f * fSlow10)) : (iSlow15 ? (8.0f * fSlow10) : (2.0f * fSlow32))), 16000.0f)));
		float fSlow37 = float(fButton7);
		int iSlow38 = (fSlow37 == 0.0f);
		float fSlow39 = std::cos((fConst9 * std::min<float>((iSlow8 ? (iSlow11 ? 11000.0f : (40.1107101f * fSlow10)) : (iSlow15 ? (9.0f * fSlow10) : (3.0f * fSlow32))), 16000.0f)));
		float fSlow40 = float(fButton8);
		int iSlow41 = (fSlow40 == 0.0f);
		float fSlow42 = float(fHslider11);
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec0[0] = (fSlow0 + (0.999000013f * fRec0[1]));
			float fTemp0 = float(input0[i]);
			fVec0[0] = fTemp0;
			fRec4[0] = ((fTemp0 + (0.995000005f * fRec4[1])) - fVec0[1]);
			float fTemp1 = std::fabs(fRec4[0]);
			fRec3[0] = std::max<float>(fTemp1, ((fConst3 * fRec3[1]) + (fConst4 * fTemp1)));
			fHbargraph0 = FAUSTFLOAT((fRec3[0] > fSlow3));
			float fTemp2 = fRec4[0];
			fVec1[0] = fSlow5;
			iRec5[0] = (((iRec5[1] + (iRec5[1] > 0)) * (fSlow5 <= fVec1[1])) + (fSlow5 > fVec1[1]));
			float fTemp3 = float(iRec5[0]);
			float fTemp4 = (1.0f - std::max<float>(0.0f, std::min<float>((fConst6 * fTemp3), ((fSlow6 * (fConst5 - fTemp3)) + 1.0f))));
			float fTemp5 = (fSlow2 * ((fTemp2 * fRec0[0]) * fTemp4));
			fVec2[0] = fTemp5;
			fRec2[0] = (fConst2 * ((fTemp5 + fVec2[1]) - (fConst7 * fRec2[1])));
			fRec6[0] = (fSlow7 + (0.999000013f * fRec6[1]));
			float fTemp6 = std::pow(0.00100000005f, (fConst8 / ((fRec6[0] * fTemp4) + 0.0500000007f)));
			float fTemp7 = (0.0f - (2.0f * fTemp6));
			float fTemp8 = DspWingie_faustpower2_f(fTemp6);
			fRec1[0] = (fRec2[0] - (((fRec1[1] * fTemp7) * fSlow12) + (fTemp8 * fRec1[2])));
			fVec3[0] = fSlow13;
			fRec7[0] = (fSlow13 + (fRec7[1] * float((fVec3[1] >= fSlow13))));
			iRec8[0] = (iSlow14 * (iRec8[1] + 1));
			float fTemp9 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec7[0]), 1.0f) - (fConst10 * float(iRec8[0]))))));
			fRec9[0] = (fRec2[0] - (((fTemp7 * fRec9[1]) * fSlow17) + (fTemp8 * fRec9[2])));
			fVec4[0] = fSlow18;
			fRec10[0] = (fSlow18 + (fRec10[1] * float((fVec4[1] >= fSlow18))));
			iRec11[0] = (iSlow19 * (iRec11[1] + 1));
			float fTemp10 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec10[0]), 1.0f) - (fConst10 * float(iRec11[0]))))));
			fRec12[0] = (fRec2[0] - (((fTemp7 * fRec12[1]) * fSlow20) + (fTemp8 * fRec12[2])));
			fVec5[0] = fSlow21;
			fRec13[0] = (fSlow21 + (fRec13[1] * float((fVec5[1] >= fSlow21))));
			iRec14[0] = (iSlow22 * (iRec14[1] + 1));
			float fTemp11 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec13[0]), 1.0f) - (fConst10 * float(iRec14[0]))))));
			fRec15[0] = (fRec2[0] - (((fTemp7 * fRec15[1]) * fSlow23) + (fTemp8 * fRec15[2])));
			fVec6[0] = fSlow24;
			fRec16[0] = (fSlow24 + (fRec16[1] * float((fVec6[1] >= fSlow24))));
			iRec17[0] = (iSlow25 * (iRec17[1] + 1));
			float fTemp12 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec16[0]), 1.0f) - (fConst10 * float(iRec17[0]))))));
			fRec18[0] = (fRec2[0] - (((fTemp7 * fRec18[1]) * fSlow26) + (fTemp8 * fRec18[2])));
			fVec7[0] = fSlow27;
			fRec19[0] = (fSlow27 + (fRec19[1] * float((fVec7[1] >= fSlow27))));
			iRec20[0] = (iSlow28 * (iRec20[1] + 1));
			float fTemp13 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec19[0]), 1.0f) - (fConst10 * float(iRec20[0]))))));
			fRec21[0] = (fRec2[0] - (((fTemp7 * fRec21[1]) * fSlow29) + (fTemp8 * fRec21[2])));
			fVec8[0] = fSlow30;
			fRec22[0] = (fSlow30 + (fRec22[1] * float((fVec8[1] >= fSlow30))));
			iRec23[0] = (iSlow31 * (iRec23[1] + 1));
			float fTemp14 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec22[0]), 1.0f) - (fConst10 * float(iRec23[0]))))));
			fRec24[0] = (fRec2[0] - (((fTemp7 * fRec24[1]) * fSlow33) + (fTemp8 * fRec24[2])));
			fVec9[0] = fSlow34;
			fRec25[0] = (fSlow34 + (fRec25[1] * float((fVec9[1] >= fSlow34))));
			iRec26[0] = (iSlow35 * (iRec26[1] + 1));
			float fTemp15 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec25[0]), 1.0f) - (fConst10 * float(iRec26[0]))))));
			fRec27[0] = (fRec2[0] - (((fTemp7 * fRec27[1]) * fSlow36) + (fTemp8 * fRec27[2])));
			fVec10[0] = fSlow37;
			fRec28[0] = (fSlow37 + (fRec28[1] * float((fVec10[1] >= fSlow37))));
			iRec29[0] = (iSlow38 * (iRec29[1] + 1));
			float fTemp16 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec28[0]), 1.0f) - (fConst10 * float(iRec29[0]))))));
			fRec30[0] = (fRec2[0] - (((fTemp7 * fRec30[1]) * fSlow39) + (fTemp8 * fRec30[2])));
			fVec11[0] = fSlow40;
			fRec31[0] = (fSlow40 + (fRec31[1] * float((fVec11[1] >= fSlow40))));
			iRec32[0] = (iSlow41 * (iRec32[1] + 1));
			float fTemp17 = DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst10 * fRec31[0]), 1.0f) - (fConst10 * float(iRec32[0]))))));
			float fTemp18 = std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow1 * (((fRec1[0] - fRec1[2]) * fTemp9) + (((fRec9[0] - fRec9[2]) * fTemp10) + (((fRec12[0] - fRec12[2]) * fTemp11) + (((fRec15[0] - fRec15[2]) * fTemp12) + (((fRec18[0] - fRec18[2]) * fTemp13) + (((((fRec21[0] - fRec21[2]) * fTemp14) + ((fRec24[0] - fRec24[2]) * fTemp15)) + ((fRec27[0] - fRec27[2]) * fTemp16)) + ((fRec30[0] - fRec30[2]) * fTemp17))))))))));
			float fTemp19 = (1.0f - fRec0[0]);
			output0[i] = FAUSTFLOAT((((fRec0[0] * fTemp18) * (1.0f - (0.333333343f * DspWingie_faustpower2_f(fTemp18)))) + ((fTemp2 * fTemp19) * fTemp4)));
			float fTemp20 = float(input1[i]);
			fVec12[0] = fTemp20;
			fRec36[0] = ((fTemp20 + (0.995000005f * fRec36[1])) - fVec12[1]);
			float fTemp21 = std::fabs(fRec36[0]);
			fRec35[0] = std::max<float>(fTemp21, ((fConst3 * fRec35[1]) + (fConst4 * fTemp21)));
			fHbargraph1 = FAUSTFLOAT((fRec35[0] > fSlow42));
			float fTemp22 = fRec36[0];
			float fTemp23 = (fSlow2 * ((fRec0[0] * fTemp22) * fTemp4));
			fVec13[0] = fTemp23;
			fRec34[0] = (0.0f - (fConst2 * ((fConst7 * fRec34[1]) - (fTemp23 + fVec13[1]))));
			fRec33[0] = (fRec34[0] - (((fTemp7 * fSlow12) * fRec33[1]) + (fTemp8 * fRec33[2])));
			fRec37[0] = (fRec34[0] - (((fTemp7 * fSlow26) * fRec37[1]) + (fTemp8 * fRec37[2])));
			fRec38[0] = (fRec34[0] - (((fTemp7 * fSlow23) * fRec38[1]) + (fTemp8 * fRec38[2])));
			fRec39[0] = (fRec34[0] - (((fTemp7 * fSlow20) * fRec39[1]) + (fTemp8 * fRec39[2])));
			fRec40[0] = (fRec34[0] - (((fTemp7 * fSlow17) * fRec40[1]) + (fTemp8 * fRec40[2])));
			fRec41[0] = (fRec34[0] - (((fTemp7 * fSlow29) * fRec41[1]) + (fTemp8 * fRec41[2])));
			fRec42[0] = (fRec34[0] - (((fTemp7 * fSlow33) * fRec42[1]) + (fTemp8 * fRec42[2])));
			fRec43[0] = (fRec34[0] - (((fTemp7 * fSlow36) * fRec43[1]) + (fTemp8 * fRec43[2])));
			fRec44[0] = (fRec34[0] - (((fTemp7 * fSlow39) * fRec44[1]) + (fTemp8 * fRec44[2])));
			float fTemp24 = std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow1 * (((((((((fTemp9 * (fRec33[0] - fRec33[2])) + (fTemp13 * (fRec37[0] - fRec37[2]))) + (fTemp12 * (fRec38[0] - fRec38[2]))) + (fTemp11 * (fRec39[0] - fRec39[2]))) + (fTemp10 * (fRec40[0] - fRec40[2]))) + (fTemp14 * (fRec41[0] - fRec41[2]))) + (fTemp15 * (fRec42[0] - fRec42[2]))) + (fTemp16 * (fRec43[0] - fRec43[2]))) + (fTemp17 * (fRec44[0] - fRec44[2]))))));
			output1[i] = FAUSTFLOAT((((fRec0[0] * fTemp24) * (1.0f - (0.333333343f * DspWingie_faustpower2_f(fTemp24)))) + ((fTemp22 * fTemp19) * fTemp4)));
			fRec0[1] = fRec0[0];
			fVec0[1] = fVec0[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fVec1[1] = fVec1[0];
			iRec5[1] = iRec5[0];
			fVec2[1] = fVec2[0];
			fRec2[1] = fRec2[0];
			fRec6[1] = fRec6[0];
			fRec1[2] = fRec1[1];
			fRec1[1] = fRec1[0];
			fVec3[1] = fVec3[0];
			fRec7[1] = fRec7[0];
			iRec8[1] = iRec8[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fVec4[1] = fVec4[0];
			fRec10[1] = fRec10[0];
			iRec11[1] = iRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fVec5[1] = fVec5[0];
			fRec13[1] = fRec13[0];
			iRec14[1] = iRec14[0];
			fRec15[2] = fRec15[1];
			fRec15[1] = fRec15[0];
			fVec6[1] = fVec6[0];
			fRec16[1] = fRec16[0];
			iRec17[1] = iRec17[0];
			fRec18[2] = fRec18[1];
			fRec18[1] = fRec18[0];
			fVec7[1] = fVec7[0];
			fRec19[1] = fRec19[0];
			iRec20[1] = iRec20[0];
			fRec21[2] = fRec21[1];
			fRec21[1] = fRec21[0];
			fVec8[1] = fVec8[0];
			fRec22[1] = fRec22[0];
			iRec23[1] = iRec23[0];
			fRec24[2] = fRec24[1];
			fRec24[1] = fRec24[0];
			fVec9[1] = fVec9[0];
			fRec25[1] = fRec25[0];
			iRec26[1] = iRec26[0];
			fRec27[2] = fRec27[1];
			fRec27[1] = fRec27[0];
			fVec10[1] = fVec10[0];
			fRec28[1] = fRec28[0];
			iRec29[1] = iRec29[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fVec11[1] = fVec11[0];
			fRec31[1] = fRec31[0];
			iRec32[1] = iRec32[0];
			fVec12[1] = fVec12[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fVec13[1] = fVec13[0];
			fRec34[1] = fRec34[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fRec39[2] = fRec39[1];
			fRec39[1] = fRec39[0];
			fRec40[2] = fRec40[1];
			fRec40[1] = fRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fRec42[2] = fRec42[1];
			fRec42[1] = fRec42[0];
			fRec43[2] = fRec43[1];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
		}
	}

};
#endif

class Wingie :
    public od::Object
#ifndef SWIGLUA
    , public ParametersSetter
#endif
{
public:
  Wingie();
  ~Wingie();

#ifndef SWIGLUA
  virtual void process();
  od::Inlet mInL{"InL"};
  od::Inlet mInR{"InR"};
  od::Outlet mOutL{"OutL"};
  od::Outlet mOutR{"OutR"};
  od::Parameter mDecay{"Decay"};
  od::Parameter mFreq{"Freq"};
  od::Parameter mInGain{"InGain"};
  od::Parameter mLeftThreshold{"LeftThreshold"};
  od::Parameter mMix{"Mix"};
  od::Parameter mMode{"Mode"};
  od::Parameter mNote{"Note"};
  od::Parameter mNote1{"Note1"};
  od::Parameter mNote2{"Note2"};
  od::Parameter mOutGain{"OutGain"};
  od::Parameter mRightThreshold{"RightThreshold"};
  od::Parameter menv_mode_change_decay{"env_mode_change_decay"};
  virtual void addParam(const char* label, FAUSTFLOAT* zone) {
    if (strcmp(label, "Decay") == 0) {
      ffDecay = zone;
    }
    if (strcmp(label, "Freq") == 0) {
      ffFreq = zone;
    }
    if (strcmp(label, "InGain") == 0) {
      ffInGain = zone;
    }
    if (strcmp(label, "LeftThreshold") == 0) {
      ffLeftThreshold = zone;
    }
    if (strcmp(label, "Mix") == 0) {
      ffMix = zone;
    }
    if (strcmp(label, "Mode") == 0) {
      ffMode = zone;
    }
    if (strcmp(label, "Note") == 0) {
      ffNote = zone;
    }
    if (strcmp(label, "Note1") == 0) {
      ffNote1 = zone;
    }
    if (strcmp(label, "Note2") == 0) {
      ffNote2 = zone;
    }
    if (strcmp(label, "OutGain") == 0) {
      ffOutGain = zone;
    }
    if (strcmp(label, "RightThreshold") == 0) {
      ffRightThreshold = zone;
    }
    if (strcmp(label, "env_mode_change_decay") == 0) {
      ffenv_mode_change_decay = zone;
    }
  }

private:
  FAUSTFLOAT* ffDecay;
  FAUSTFLOAT* ffFreq;
  FAUSTFLOAT* ffInGain;
  FAUSTFLOAT* ffLeftThreshold;
  FAUSTFLOAT* ffMix;
  FAUSTFLOAT* ffMode;
  FAUSTFLOAT* ffNote;
  FAUSTFLOAT* ffNote1;
  FAUSTFLOAT* ffNote2;
  FAUSTFLOAT* ffOutGain;
  FAUSTFLOAT* ffRightThreshold;
  FAUSTFLOAT* ffenv_mode_change_decay;
  DspWingie DSP;

#endif

};


#endif
