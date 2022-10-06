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
	int fSampleRate;
	float fConst0;
	float fConst2;
	float fConst3;
	FAUSTFLOAT fHslider1;
	FAUSTFLOAT fHslider2;
	float fRec2[2];
	float fVec0[2];
	float fRec1[2];
	float fConst4;
	FAUSTFLOAT fHslider3;
	float fRec3[2];
	float fConst5;
	float fConst6;
	FAUSTFLOAT fButton0;
	float fVec1[2];
	int iRec4[2];
	FAUSTFLOAT fHslider4;
	float fConst7;
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fVslider0;
	FAUSTFLOAT fHslider6;
	float fRec0[3];
	float fConst8;
	FAUSTFLOAT fButton1;
	float fVec2[2];
	float fRec5[2];
	int iRec6[2];
	float fRec7[3];
	FAUSTFLOAT fButton2;
	float fVec3[2];
	float fRec8[2];
	int iRec9[2];
	FAUSTFLOAT fVslider1;
	float fRec10[3];
	FAUSTFLOAT fButton3;
	float fVec4[2];
	float fRec11[2];
	int iRec12[2];
	float fRec13[3];
	FAUSTFLOAT fButton4;
	float fVec5[2];
	float fRec14[2];
	int iRec15[2];
	float fRec16[3];
	FAUSTFLOAT fButton5;
	float fVec6[2];
	float fRec17[2];
	int iRec18[2];
	float fRec19[3];
	FAUSTFLOAT fButton6;
	float fVec7[2];
	float fRec20[2];
	int iRec21[2];
	FAUSTFLOAT fVslider2;
	float fRec22[3];
	FAUSTFLOAT fButton7;
	float fVec8[2];
	float fRec23[2];
	int iRec24[2];
	float fRec25[3];
	FAUSTFLOAT fButton8;
	float fVec9[2];
	float fRec26[2];
	int iRec27[2];
	float fRec28[3];
	FAUSTFLOAT fButton9;
	float fVec10[2];
	float fRec29[2];
	int iRec30[2];
	FAUSTFLOAT fHslider7;
	float fRec33[2];
	float fVec11[2];
	float fRec32[2];
	FAUSTFLOAT fHslider8;
	float fRec34[2];
	FAUSTFLOAT fButton10;
	float fVec12[2];
	int iRec35[2];
	FAUSTFLOAT fHslider9;
	FAUSTFLOAT fHslider10;
	FAUSTFLOAT fVslider3;
	FAUSTFLOAT fHslider11;
	float fRec31[3];
	FAUSTFLOAT fButton11;
	float fVec13[2];
	float fRec36[2];
	int iRec37[2];
	float fRec38[3];
	FAUSTFLOAT fButton12;
	float fVec14[2];
	float fRec39[2];
	int iRec40[2];
	FAUSTFLOAT fVslider4;
	float fRec41[3];
	FAUSTFLOAT fButton13;
	float fVec15[2];
	float fRec42[2];
	int iRec43[2];
	float fRec44[3];
	FAUSTFLOAT fButton14;
	float fVec16[2];
	float fRec45[2];
	int iRec46[2];
	FAUSTFLOAT fVslider5;
	float fRec47[3];
	FAUSTFLOAT fButton15;
	float fVec17[2];
	float fRec48[2];
	int iRec49[2];
	float fRec50[3];
	FAUSTFLOAT fButton16;
	float fVec18[2];
	float fRec51[2];
	int iRec52[2];
	float fRec53[3];
	FAUSTFLOAT fButton17;
	float fVec19[2];
	float fRec54[2];
	int iRec55[2];
	float fRec56[3];
	FAUSTFLOAT fButton18;
	float fVec20[2];
	float fRec57[2];
	int iRec58[2];
	float fRec59[3];
	FAUSTFLOAT fButton19;
	float fVec21[2];
	float fRec60[2];
	int iRec61[2];
	
 public:
	
	void metadata(Meta* m) { 
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
		fConst3 = (1.0f - fConst1);
		fConst4 = (1.0f / fConst0);
		fConst5 = std::max<float>(1.0f, (0.00200000009f * fConst0));
		fConst6 = (1.0f / fConst5);
		fConst7 = (6.28318548f / fConst0);
		fConst8 = (1.0f / std::max<float>(1.0f, (0.25f * fConst0)));
	}
	
	virtual void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(0.5f);
		fHslider1 = FAUSTFLOAT(0.5f);
		fHslider2 = FAUSTFLOAT(1.0f);
		fHslider3 = FAUSTFLOAT(5.0f);
		fButton0 = FAUSTFLOAT(0.0f);
		fHslider4 = FAUSTFLOAT(0.050000000000000003f);
		fHslider5 = FAUSTFLOAT(0.0f);
		fVslider0 = FAUSTFLOAT(36.0f);
		fHslider6 = FAUSTFLOAT(36.0f);
		fButton1 = FAUSTFLOAT(0.0f);
		fButton2 = FAUSTFLOAT(0.0f);
		fVslider1 = FAUSTFLOAT(36.0f);
		fButton3 = FAUSTFLOAT(0.0f);
		fButton4 = FAUSTFLOAT(0.0f);
		fButton5 = FAUSTFLOAT(0.0f);
		fButton6 = FAUSTFLOAT(0.0f);
		fVslider2 = FAUSTFLOAT(36.0f);
		fButton7 = FAUSTFLOAT(0.0f);
		fButton8 = FAUSTFLOAT(0.0f);
		fButton9 = FAUSTFLOAT(0.0f);
		fHslider7 = FAUSTFLOAT(1.0f);
		fHslider8 = FAUSTFLOAT(5.0f);
		fButton10 = FAUSTFLOAT(0.0f);
		fHslider9 = FAUSTFLOAT(0.050000000000000003f);
		fHslider10 = FAUSTFLOAT(0.0f);
		fVslider3 = FAUSTFLOAT(36.0f);
		fHslider11 = FAUSTFLOAT(36.0f);
		fButton11 = FAUSTFLOAT(0.0f);
		fButton12 = FAUSTFLOAT(0.0f);
		fVslider4 = FAUSTFLOAT(36.0f);
		fButton13 = FAUSTFLOAT(0.0f);
		fButton14 = FAUSTFLOAT(0.0f);
		fVslider5 = FAUSTFLOAT(36.0f);
		fButton15 = FAUSTFLOAT(0.0f);
		fButton16 = FAUSTFLOAT(0.0f);
		fButton17 = FAUSTFLOAT(0.0f);
		fButton18 = FAUSTFLOAT(0.0f);
		fButton19 = FAUSTFLOAT(0.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec2[l0] = 0.0f;
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fVec0[l1] = 0.0f;
		}
		for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
			fRec1[l2] = 0.0f;
		}
		for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
			fRec3[l3] = 0.0f;
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
		}
		for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
			iRec4[l5] = 0;
		}
		for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
			fRec0[l6] = 0.0f;
		}
		for (int l7 = 0; (l7 < 2); l7 = (l7 + 1)) {
			fVec2[l7] = 0.0f;
		}
		for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
			fRec5[l8] = 0.0f;
		}
		for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
			iRec6[l9] = 0;
		}
		for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
			fRec7[l10] = 0.0f;
		}
		for (int l11 = 0; (l11 < 2); l11 = (l11 + 1)) {
			fVec3[l11] = 0.0f;
		}
		for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
			fRec8[l12] = 0.0f;
		}
		for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
			iRec9[l13] = 0;
		}
		for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
			fRec10[l14] = 0.0f;
		}
		for (int l15 = 0; (l15 < 2); l15 = (l15 + 1)) {
			fVec4[l15] = 0.0f;
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fRec11[l16] = 0.0f;
		}
		for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
			iRec12[l17] = 0;
		}
		for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
			fRec13[l18] = 0.0f;
		}
		for (int l19 = 0; (l19 < 2); l19 = (l19 + 1)) {
			fVec5[l19] = 0.0f;
		}
		for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
			fRec14[l20] = 0.0f;
		}
		for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
			iRec15[l21] = 0;
		}
		for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
			fRec16[l22] = 0.0f;
		}
		for (int l23 = 0; (l23 < 2); l23 = (l23 + 1)) {
			fVec6[l23] = 0.0f;
		}
		for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
			fRec17[l24] = 0.0f;
		}
		for (int l25 = 0; (l25 < 2); l25 = (l25 + 1)) {
			iRec18[l25] = 0;
		}
		for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
			fRec19[l26] = 0.0f;
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fVec7[l27] = 0.0f;
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec20[l28] = 0.0f;
		}
		for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
			iRec21[l29] = 0;
		}
		for (int l30 = 0; (l30 < 3); l30 = (l30 + 1)) {
			fRec22[l30] = 0.0f;
		}
		for (int l31 = 0; (l31 < 2); l31 = (l31 + 1)) {
			fVec8[l31] = 0.0f;
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec23[l32] = 0.0f;
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			iRec24[l33] = 0;
		}
		for (int l34 = 0; (l34 < 3); l34 = (l34 + 1)) {
			fRec25[l34] = 0.0f;
		}
		for (int l35 = 0; (l35 < 2); l35 = (l35 + 1)) {
			fVec9[l35] = 0.0f;
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec26[l36] = 0.0f;
		}
		for (int l37 = 0; (l37 < 2); l37 = (l37 + 1)) {
			iRec27[l37] = 0;
		}
		for (int l38 = 0; (l38 < 3); l38 = (l38 + 1)) {
			fRec28[l38] = 0.0f;
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fVec10[l39] = 0.0f;
		}
		for (int l40 = 0; (l40 < 2); l40 = (l40 + 1)) {
			fRec29[l40] = 0.0f;
		}
		for (int l41 = 0; (l41 < 2); l41 = (l41 + 1)) {
			iRec30[l41] = 0;
		}
		for (int l42 = 0; (l42 < 2); l42 = (l42 + 1)) {
			fRec33[l42] = 0.0f;
		}
		for (int l43 = 0; (l43 < 2); l43 = (l43 + 1)) {
			fVec11[l43] = 0.0f;
		}
		for (int l44 = 0; (l44 < 2); l44 = (l44 + 1)) {
			fRec32[l44] = 0.0f;
		}
		for (int l45 = 0; (l45 < 2); l45 = (l45 + 1)) {
			fRec34[l45] = 0.0f;
		}
		for (int l46 = 0; (l46 < 2); l46 = (l46 + 1)) {
			fVec12[l46] = 0.0f;
		}
		for (int l47 = 0; (l47 < 2); l47 = (l47 + 1)) {
			iRec35[l47] = 0;
		}
		for (int l48 = 0; (l48 < 3); l48 = (l48 + 1)) {
			fRec31[l48] = 0.0f;
		}
		for (int l49 = 0; (l49 < 2); l49 = (l49 + 1)) {
			fVec13[l49] = 0.0f;
		}
		for (int l50 = 0; (l50 < 2); l50 = (l50 + 1)) {
			fRec36[l50] = 0.0f;
		}
		for (int l51 = 0; (l51 < 2); l51 = (l51 + 1)) {
			iRec37[l51] = 0;
		}
		for (int l52 = 0; (l52 < 3); l52 = (l52 + 1)) {
			fRec38[l52] = 0.0f;
		}
		for (int l53 = 0; (l53 < 2); l53 = (l53 + 1)) {
			fVec14[l53] = 0.0f;
		}
		for (int l54 = 0; (l54 < 2); l54 = (l54 + 1)) {
			fRec39[l54] = 0.0f;
		}
		for (int l55 = 0; (l55 < 2); l55 = (l55 + 1)) {
			iRec40[l55] = 0;
		}
		for (int l56 = 0; (l56 < 3); l56 = (l56 + 1)) {
			fRec41[l56] = 0.0f;
		}
		for (int l57 = 0; (l57 < 2); l57 = (l57 + 1)) {
			fVec15[l57] = 0.0f;
		}
		for (int l58 = 0; (l58 < 2); l58 = (l58 + 1)) {
			fRec42[l58] = 0.0f;
		}
		for (int l59 = 0; (l59 < 2); l59 = (l59 + 1)) {
			iRec43[l59] = 0;
		}
		for (int l60 = 0; (l60 < 3); l60 = (l60 + 1)) {
			fRec44[l60] = 0.0f;
		}
		for (int l61 = 0; (l61 < 2); l61 = (l61 + 1)) {
			fVec16[l61] = 0.0f;
		}
		for (int l62 = 0; (l62 < 2); l62 = (l62 + 1)) {
			fRec45[l62] = 0.0f;
		}
		for (int l63 = 0; (l63 < 2); l63 = (l63 + 1)) {
			iRec46[l63] = 0;
		}
		for (int l64 = 0; (l64 < 3); l64 = (l64 + 1)) {
			fRec47[l64] = 0.0f;
		}
		for (int l65 = 0; (l65 < 2); l65 = (l65 + 1)) {
			fVec17[l65] = 0.0f;
		}
		for (int l66 = 0; (l66 < 2); l66 = (l66 + 1)) {
			fRec48[l66] = 0.0f;
		}
		for (int l67 = 0; (l67 < 2); l67 = (l67 + 1)) {
			iRec49[l67] = 0;
		}
		for (int l68 = 0; (l68 < 3); l68 = (l68 + 1)) {
			fRec50[l68] = 0.0f;
		}
		for (int l69 = 0; (l69 < 2); l69 = (l69 + 1)) {
			fVec18[l69] = 0.0f;
		}
		for (int l70 = 0; (l70 < 2); l70 = (l70 + 1)) {
			fRec51[l70] = 0.0f;
		}
		for (int l71 = 0; (l71 < 2); l71 = (l71 + 1)) {
			iRec52[l71] = 0;
		}
		for (int l72 = 0; (l72 < 3); l72 = (l72 + 1)) {
			fRec53[l72] = 0.0f;
		}
		for (int l73 = 0; (l73 < 2); l73 = (l73 + 1)) {
			fVec19[l73] = 0.0f;
		}
		for (int l74 = 0; (l74 < 2); l74 = (l74 + 1)) {
			fRec54[l74] = 0.0f;
		}
		for (int l75 = 0; (l75 < 2); l75 = (l75 + 1)) {
			iRec55[l75] = 0;
		}
		for (int l76 = 0; (l76 < 3); l76 = (l76 + 1)) {
			fRec56[l76] = 0.0f;
		}
		for (int l77 = 0; (l77 < 2); l77 = (l77 + 1)) {
			fVec20[l77] = 0.0f;
		}
		for (int l78 = 0; (l78 < 2); l78 = (l78 + 1)) {
			fRec57[l78] = 0.0f;
		}
		for (int l79 = 0; (l79 < 2); l79 = (l79 + 1)) {
			iRec58[l79] = 0;
		}
		for (int l80 = 0; (l80 < 3); l80 = (l80 + 1)) {
			fRec59[l80] = 0.0f;
		}
		for (int l81 = 0; (l81 < 2); l81 = (l81 + 1)) {
			fVec21[l81] = 0.0f;
		}
		for (int l82 = 0; (l82 < 2); l82 = (l82 + 1)) {
			fRec60[l82] = 0.0f;
		}
		for (int l83 = 0; (l83 < 2); l83 = (l83 + 1)) {
			iRec61[l83] = 0;
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
		ui_interface->addHorizontalSlider("InGain", &fHslider1, 0.5f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("LeftMix", &fHslider2, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("OutGain", &fHslider0, 0.5f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("RightMix", &fHslider7, 1.0f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->openHorizontalBox("left");
		ui_interface->addHorizontalSlider("Decay", &fHslider3, 5.0f, 0.100000001f, 10.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("EnvModeDecay", &fHslider4, 0.0500000007f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("LeftMode", &fHslider5, 0.0f, 0.0f, 4.0f, 1.0f);
		ui_interface->addHorizontalSlider("LeftNote", &fHslider6, 36.0f, 12.0f, 96.0f, 1.0f);
		ui_interface->addButton("mode_changed", &fButton0);
		ui_interface->addButton("mute_0", &fButton2);
		ui_interface->addButton("mute_1", &fButton1);
		ui_interface->addButton("mute_2", &fButton4);
		ui_interface->addButton("mute_3", &fButton3);
		ui_interface->addButton("mute_4", &fButton6);
		ui_interface->addButton("mute_5", &fButton5);
		ui_interface->addButton("mute_6", &fButton7);
		ui_interface->addButton("mute_7", &fButton8);
		ui_interface->addButton("mute_8", &fButton9);
		ui_interface->addVerticalSlider("poly_note_0", &fVslider0, 36.0f, 24.0f, 96.0f, 1.0f);
		ui_interface->addVerticalSlider("poly_note_1", &fVslider1, 36.0f, 24.0f, 96.0f, 1.0f);
		ui_interface->addVerticalSlider("poly_note_2", &fVslider2, 36.0f, 24.0f, 96.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->openHorizontalBox("right");
		ui_interface->addHorizontalSlider("Decay", &fHslider8, 5.0f, 0.100000001f, 10.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("EnvModeDecay", &fHslider9, 0.0500000007f, 0.0f, 1.0f, 0.00999999978f);
		ui_interface->addHorizontalSlider("RightMode", &fHslider10, 0.0f, 0.0f, 4.0f, 1.0f);
		ui_interface->addHorizontalSlider("RightNote", &fHslider11, 36.0f, 12.0f, 96.0f, 1.0f);
		ui_interface->addButton("mode_changed", &fButton10);
		ui_interface->addButton("mute_0", &fButton16);
		ui_interface->addButton("mute_1", &fButton15);
		ui_interface->addButton("mute_2", &fButton17);
		ui_interface->addButton("mute_3", &fButton18);
		ui_interface->addButton("mute_4", &fButton12);
		ui_interface->addButton("mute_5", &fButton11);
		ui_interface->addButton("mute_6", &fButton14);
		ui_interface->addButton("mute_7", &fButton13);
		ui_interface->addButton("mute_8", &fButton19);
		ui_interface->addVerticalSlider("poly_note_0", &fVslider5, 36.0f, 24.0f, 96.0f, 1.0f);
		ui_interface->addVerticalSlider("poly_note_1", &fVslider3, 36.0f, 24.0f, 96.0f, 1.0f);
		ui_interface->addVerticalSlider("poly_note_2", &fVslider4, 36.0f, 24.0f, 96.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = (1.04712856f * DspWingie_faustpower2_f(float(fHslider0)));
		float fSlow1 = DspWingie_faustpower2_f(float(fHslider1));
		float fSlow2 = (0.00100000005f * float(fHslider2));
		float fSlow3 = (0.00100000005f * float(fHslider3));
		float fSlow4 = float(fButton0);
		float fSlow5 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider4))));
		float fSlow6 = float(fHslider5);
		int iSlow7 = (fSlow6 >= 2.0f);
		int iSlow8 = (fSlow6 >= 1.0f);
		float fSlow9 = std::pow(2.0f, (0.0833333358f * (float(fVslider0) + -69.0f)));
		float fSlow10 = std::pow(2.0f, (0.0833333358f * (float(fHslider6) + -69.0f)));
		int iSlow11 = (fSlow6 >= 3.0f);
		float fSlow12 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 115.0f : (1222.20996f * fSlow10)) : (iSlow8 ? (880.0f * fSlow10) : (880.0f * fSlow9))), 16000.0f)));
		float fSlow13 = float(fButton1);
		int iSlow14 = (fSlow13 == 0.0f);
		float fSlow15 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 62.0f : (439.995605f * fSlow10)) : (iSlow8 ? (440.0f * fSlow10) : (440.0f * fSlow9))), 16000.0f)));
		float fSlow16 = float(fButton2);
		int iSlow17 = (fSlow16 == 0.0f);
		float fSlow18 = std::pow(2.0f, (0.0833333358f * (float(fVslider1) + -69.0f)));
		float fSlow19 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 411.0f : (3959.96045f * fSlow10)) : (iSlow8 ? (1760.0f * fSlow10) : (440.0f * fSlow18))), 16000.0f)));
		float fSlow20 = float(fButton3);
		int iSlow21 = (fSlow20 == 0.0f);
		float fSlow22 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 218.0f : (2395.53149f * fSlow10)) : (iSlow8 ? (1320.0f * fSlow10) : (1320.0f * fSlow9))), 16000.0f)));
		float fSlow23 = float(fButton4);
		int iSlow24 = (fSlow23 == 0.0f);
		float fSlow25 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 1500.0f : (8262.13965f * fSlow10)) : (iSlow8 ? (2640.0f * fSlow10) : (1320.0f * fSlow18))), 16000.0f)));
		float fSlow26 = float(fButton5);
		int iSlow27 = (fSlow26 == 0.0f);
		float fSlow28 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 777.0f : (5915.49658f * fSlow10)) : (iSlow8 ? (2200.0f * fSlow10) : (880.0f * fSlow18))), 16000.0f)));
		float fSlow29 = float(fButton6);
		int iSlow30 = (fSlow29 == 0.0f);
		float fSlow31 = std::pow(2.0f, (0.0833333358f * (float(fVslider2) + -69.0f)));
		float fSlow32 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 2800.0f : (10999.8896f * fSlow10)) : (iSlow8 ? (3080.0f * fSlow10) : (440.0f * fSlow31))), 16000.0f)));
		float fSlow33 = float(fButton7);
		int iSlow34 = (fSlow33 == 0.0f);
		float fSlow35 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 5200.0f : (14128.748f * fSlow10)) : (iSlow8 ? (3520.0f * fSlow10) : (880.0f * fSlow31))), 16000.0f)));
		float fSlow36 = float(fButton8);
		int iSlow37 = (fSlow36 == 0.0f);
		float fSlow38 = std::cos((fConst7 * std::min<float>((iSlow7 ? (iSlow11 ? 11000.0f : (17648.7129f * fSlow10)) : (iSlow8 ? (3960.0f * fSlow10) : (1320.0f * fSlow31))), 16000.0f)));
		float fSlow39 = float(fButton9);
		int iSlow40 = (fSlow39 == 0.0f);
		float fSlow41 = (0.00100000005f * float(fHslider7));
		float fSlow42 = (0.00100000005f * float(fHslider8));
		float fSlow43 = float(fButton10);
		float fSlow44 = (1.0f / std::max<float>(1.0f, (fConst0 * float(fHslider9))));
		float fSlow45 = float(fHslider10);
		int iSlow46 = (fSlow45 >= 2.0f);
		int iSlow47 = (fSlow45 >= 1.0f);
		float fSlow48 = std::pow(2.0f, (0.0833333358f * (float(fVslider3) + -69.0f)));
		float fSlow49 = std::pow(2.0f, (0.0833333358f * (float(fHslider11) + -69.0f)));
		int iSlow50 = (fSlow45 >= 3.0f);
		float fSlow51 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 1500.0f : (8262.13965f * fSlow49)) : (iSlow47 ? (2640.0f * fSlow49) : (1320.0f * fSlow48))), 16000.0f)));
		float fSlow52 = float(fButton11);
		int iSlow53 = (fSlow52 == 0.0f);
		float fSlow54 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 777.0f : (5915.49658f * fSlow49)) : (iSlow47 ? (2200.0f * fSlow49) : (880.0f * fSlow48))), 16000.0f)));
		float fSlow55 = float(fButton12);
		int iSlow56 = (fSlow55 == 0.0f);
		float fSlow57 = std::pow(2.0f, (0.0833333358f * (float(fVslider4) + -69.0f)));
		float fSlow58 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 5200.0f : (14128.748f * fSlow49)) : (iSlow47 ? (3520.0f * fSlow49) : (880.0f * fSlow57))), 16000.0f)));
		float fSlow59 = float(fButton13);
		int iSlow60 = (fSlow59 == 0.0f);
		float fSlow61 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 2800.0f : (10999.8896f * fSlow49)) : (iSlow47 ? (3080.0f * fSlow49) : (440.0f * fSlow57))), 16000.0f)));
		float fSlow62 = float(fButton14);
		int iSlow63 = (fSlow62 == 0.0f);
		float fSlow64 = std::pow(2.0f, (0.0833333358f * (float(fVslider5) + -69.0f)));
		float fSlow65 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 115.0f : (1222.20996f * fSlow49)) : (iSlow47 ? (880.0f * fSlow49) : (880.0f * fSlow64))), 16000.0f)));
		float fSlow66 = float(fButton15);
		int iSlow67 = (fSlow66 == 0.0f);
		float fSlow68 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 62.0f : (439.995605f * fSlow49)) : (iSlow47 ? (440.0f * fSlow49) : (440.0f * fSlow64))), 16000.0f)));
		float fSlow69 = float(fButton16);
		int iSlow70 = (fSlow69 == 0.0f);
		float fSlow71 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 218.0f : (2395.53149f * fSlow49)) : (iSlow47 ? (1320.0f * fSlow49) : (1320.0f * fSlow64))), 16000.0f)));
		float fSlow72 = float(fButton17);
		int iSlow73 = (fSlow72 == 0.0f);
		float fSlow74 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 411.0f : (3959.96045f * fSlow49)) : (iSlow47 ? (1760.0f * fSlow49) : (440.0f * fSlow48))), 16000.0f)));
		float fSlow75 = float(fButton18);
		int iSlow76 = (fSlow75 == 0.0f);
		float fSlow77 = std::cos((fConst7 * std::min<float>((iSlow46 ? (iSlow50 ? 11000.0f : (17648.7129f * fSlow49)) : (iSlow47 ? (3960.0f * fSlow49) : (1320.0f * fSlow57))), 16000.0f)));
		float fSlow78 = float(fButton19);
		int iSlow79 = (fSlow78 == 0.0f);
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec2[0] = (fSlow2 + (0.999000013f * fRec2[1]));
			float fTemp0 = (fSlow1 * (float(input0[i]) * fRec2[0]));
			fVec0[0] = fTemp0;
			fRec1[0] = (0.0f - (fConst2 * ((fConst3 * fRec1[1]) - (fTemp0 + fVec0[1]))));
			fRec3[0] = (fSlow3 + (0.999000013f * fRec3[1]));
			fVec1[0] = fSlow4;
			iRec4[0] = (((iRec4[1] + (iRec4[1] > 0)) * (fSlow4 <= fVec1[1])) + (fSlow4 > fVec1[1]));
			float fTemp1 = float(iRec4[0]);
			float fTemp2 = std::pow(0.00100000005f, (fConst4 / ((fRec3[0] * (1.0f - std::max<float>(0.0f, std::min<float>((fConst6 * fTemp1), (1.0f - (fSlow5 * (fTemp1 - fConst5))))))) + 0.0500000007f)));
			float fTemp3 = (0.0f - (2.0f * fTemp2));
			float fTemp4 = DspWingie_faustpower2_f(fTemp2);
			fRec0[0] = (fRec1[0] - (((fTemp3 * fRec0[1]) * fSlow12) + (fTemp4 * fRec0[2])));
			fVec2[0] = fSlow13;
			fRec5[0] = (fSlow13 + (fRec5[1] * float((fVec2[1] >= fSlow13))));
			iRec6[0] = (iSlow14 * (iRec6[1] + 1));
			fRec7[0] = (fRec1[0] - (((fRec7[1] * fTemp3) * fSlow15) + (fTemp4 * fRec7[2])));
			fVec3[0] = fSlow16;
			fRec8[0] = (fSlow16 + (fRec8[1] * float((fVec3[1] >= fSlow16))));
			iRec9[0] = (iSlow17 * (iRec9[1] + 1));
			fRec10[0] = (fRec1[0] - (((fTemp3 * fRec10[1]) * fSlow19) + (fTemp4 * fRec10[2])));
			fVec4[0] = fSlow20;
			fRec11[0] = (fSlow20 + (fRec11[1] * float((fVec4[1] >= fSlow20))));
			iRec12[0] = (iSlow21 * (iRec12[1] + 1));
			fRec13[0] = (fRec1[0] - (((fTemp3 * fRec13[1]) * fSlow22) + (fTemp4 * fRec13[2])));
			fVec5[0] = fSlow23;
			fRec14[0] = (fSlow23 + (fRec14[1] * float((fVec5[1] >= fSlow23))));
			iRec15[0] = (iSlow24 * (iRec15[1] + 1));
			fRec16[0] = (fRec1[0] - (((fTemp3 * fRec16[1]) * fSlow25) + (fTemp4 * fRec16[2])));
			fVec6[0] = fSlow26;
			fRec17[0] = (fSlow26 + (fRec17[1] * float((fVec6[1] >= fSlow26))));
			iRec18[0] = (iSlow27 * (iRec18[1] + 1));
			fRec19[0] = (fRec1[0] - (((fTemp3 * fRec19[1]) * fSlow28) + (fTemp4 * fRec19[2])));
			fVec7[0] = fSlow29;
			fRec20[0] = (fSlow29 + (fRec20[1] * float((fVec7[1] >= fSlow29))));
			iRec21[0] = (iSlow30 * (iRec21[1] + 1));
			fRec22[0] = (fRec1[0] - (((fTemp3 * fRec22[1]) * fSlow32) + (fTemp4 * fRec22[2])));
			fVec8[0] = fSlow33;
			fRec23[0] = (fSlow33 + (fRec23[1] * float((fVec8[1] >= fSlow33))));
			iRec24[0] = (iSlow34 * (iRec24[1] + 1));
			fRec25[0] = (fRec1[0] - (((fTemp3 * fRec25[1]) * fSlow35) + (fTemp4 * fRec25[2])));
			fVec9[0] = fSlow36;
			fRec26[0] = (fSlow36 + (fRec26[1] * float((fVec9[1] >= fSlow36))));
			iRec27[0] = (iSlow37 * (iRec27[1] + 1));
			fRec28[0] = (fRec1[0] - (((fTemp3 * fRec28[1]) * fSlow38) + (fTemp4 * fRec28[2])));
			fVec10[0] = fSlow39;
			fRec29[0] = (fSlow39 + (fRec29[1] * float((fVec10[1] >= fSlow39))));
			iRec30[0] = (iSlow40 * (iRec30[1] + 1));
			float fTemp5 = std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow0 * ((((fRec0[0] - fRec0[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec5[0]), 1.0f) - (fConst8 * float(iRec6[0]))))))) + (((fRec7[0] - fRec7[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec8[0]), 1.0f) - (fConst8 * float(iRec9[0]))))))) + (((fRec10[0] - fRec10[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec11[0]), 1.0f) - (fConst8 * float(iRec12[0]))))))) + (((fRec13[0] - fRec13[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec14[0]), 1.0f) - (fConst8 * float(iRec15[0]))))))) + (((fRec16[0] - fRec16[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec17[0]), 1.0f) - (fConst8 * float(iRec18[0]))))))) + (((fRec19[0] - fRec19[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec20[0]), 1.0f) - (fConst8 * float(iRec21[0]))))))) + (((fRec22[0] - fRec22[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec23[0]), 1.0f) - (fConst8 * float(iRec24[0]))))))) + ((fRec25[0] - fRec25[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec26[0]), 1.0f) - (fConst8 * float(iRec27[0])))))))))))))) + ((fRec28[0] - fRec28[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec29[0]), 1.0f) - (fConst8 * float(iRec30[0])))))))))));
			output0[i] = FAUSTFLOAT((fTemp5 * (1.0f - (0.333333343f * DspWingie_faustpower2_f(fTemp5)))));
			fRec33[0] = (fSlow41 + (0.999000013f * fRec33[1]));
			float fTemp6 = (fSlow1 * (float(input1[i]) * fRec33[0]));
			fVec11[0] = fTemp6;
			fRec32[0] = (0.0f - (fConst2 * ((fConst3 * fRec32[1]) - (fTemp6 + fVec11[1]))));
			fRec34[0] = (fSlow42 + (0.999000013f * fRec34[1]));
			fVec12[0] = fSlow43;
			iRec35[0] = (((iRec35[1] + (iRec35[1] > 0)) * (fSlow43 <= fVec12[1])) + (fSlow43 > fVec12[1]));
			float fTemp7 = float(iRec35[0]);
			float fTemp8 = std::pow(0.00100000005f, (fConst4 / ((fRec34[0] * (1.0f - std::max<float>(0.0f, std::min<float>((fConst6 * fTemp7), ((fSlow44 * (fConst5 - fTemp7)) + 1.0f))))) + 0.0500000007f)));
			float fTemp9 = (0.0f - (2.0f * fTemp8));
			float fTemp10 = DspWingie_faustpower2_f(fTemp8);
			fRec31[0] = (fRec32[0] - (((fTemp9 * fRec31[1]) * fSlow51) + (fTemp10 * fRec31[2])));
			fVec13[0] = fSlow52;
			fRec36[0] = (fSlow52 + (fRec36[1] * float((fVec13[1] >= fSlow52))));
			iRec37[0] = (iSlow53 * (iRec37[1] + 1));
			fRec38[0] = (fRec32[0] - (((fTemp9 * fRec38[1]) * fSlow54) + (fTemp10 * fRec38[2])));
			fVec14[0] = fSlow55;
			fRec39[0] = (fSlow55 + (fRec39[1] * float((fVec14[1] >= fSlow55))));
			iRec40[0] = (iSlow56 * (iRec40[1] + 1));
			fRec41[0] = (fRec32[0] - (((fTemp9 * fRec41[1]) * fSlow58) + (fTemp10 * fRec41[2])));
			fVec15[0] = fSlow59;
			fRec42[0] = (fSlow59 + (fRec42[1] * float((fVec15[1] >= fSlow59))));
			iRec43[0] = (iSlow60 * (iRec43[1] + 1));
			fRec44[0] = (fRec32[0] - (((fTemp9 * fRec44[1]) * fSlow61) + (fTemp10 * fRec44[2])));
			fVec16[0] = fSlow62;
			fRec45[0] = (fSlow62 + (fRec45[1] * float((fVec16[1] >= fSlow62))));
			iRec46[0] = (iSlow63 * (iRec46[1] + 1));
			fRec47[0] = (fRec32[0] - (((fTemp9 * fRec47[1]) * fSlow65) + (fTemp10 * fRec47[2])));
			fVec17[0] = fSlow66;
			fRec48[0] = (fSlow66 + (fRec48[1] * float((fVec17[1] >= fSlow66))));
			iRec49[0] = (iSlow67 * (iRec49[1] + 1));
			fRec50[0] = (fRec32[0] - (((fRec50[1] * fTemp9) * fSlow68) + (fTemp10 * fRec50[2])));
			fVec18[0] = fSlow69;
			fRec51[0] = (fSlow69 + (fRec51[1] * float((fVec18[1] >= fSlow69))));
			iRec52[0] = (iSlow70 * (iRec52[1] + 1));
			fRec53[0] = (fRec32[0] - (((fTemp9 * fRec53[1]) * fSlow71) + (fTemp10 * fRec53[2])));
			fVec19[0] = fSlow72;
			fRec54[0] = (fSlow72 + (fRec54[1] * float((fVec19[1] >= fSlow72))));
			iRec55[0] = (iSlow73 * (iRec55[1] + 1));
			fRec56[0] = (fRec32[0] - (((fTemp9 * fRec56[1]) * fSlow74) + (fTemp10 * fRec56[2])));
			fVec20[0] = fSlow75;
			fRec57[0] = (fSlow75 + (fRec57[1] * float((fVec20[1] >= fSlow75))));
			iRec58[0] = (iSlow76 * (iRec58[1] + 1));
			fRec59[0] = (fRec32[0] - (((fTemp9 * fRec59[1]) * fSlow77) + (fTemp10 * fRec59[2])));
			fVec21[0] = fSlow78;
			fRec60[0] = (fSlow78 + (fRec60[1] * float((fVec21[1] >= fSlow78))));
			iRec61[0] = (iSlow79 * (iRec61[1] + 1));
			float fTemp11 = std::max<float>(-1.0f, std::min<float>(1.0f, (fSlow0 * (((fRec31[0] - fRec31[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec36[0]), 1.0f) - (fConst8 * float(iRec37[0]))))))) + (((fRec38[0] - fRec38[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec39[0]), 1.0f) - (fConst8 * float(iRec40[0]))))))) + (((fRec41[0] - fRec41[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec42[0]), 1.0f) - (fConst8 * float(iRec43[0]))))))) + (((fRec44[0] - fRec44[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec45[0]), 1.0f) - (fConst8 * float(iRec46[0]))))))) + ((((fRec47[0] - fRec47[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec48[0]), 1.0f) - (fConst8 * float(iRec49[0]))))))) + (((fRec50[0] - fRec50[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec51[0]), 1.0f) - (fConst8 * float(iRec52[0]))))))) + (((fRec53[0] - fRec53[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec54[0]), 1.0f) - (fConst8 * float(iRec55[0]))))))) + ((fRec56[0] - fRec56[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec57[0]), 1.0f) - (fConst8 * float(iRec58[0])))))))))) + ((fRec59[0] - fRec59[2]) * DspWingie_faustpower2_f((1.0f - std::max<float>(0.0f, (std::min<float>((fConst8 * fRec60[0]), 1.0f) - (fConst8 * float(iRec61[0])))))))))))))));
			output1[i] = FAUSTFLOAT((fTemp11 * (1.0f - (0.333333343f * DspWingie_faustpower2_f(fTemp11)))));
			fRec2[1] = fRec2[0];
			fVec0[1] = fVec0[0];
			fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fVec1[1] = fVec1[0];
			iRec4[1] = iRec4[0];
			fRec0[2] = fRec0[1];
			fRec0[1] = fRec0[0];
			fVec2[1] = fVec2[0];
			fRec5[1] = fRec5[0];
			iRec6[1] = iRec6[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec3[1] = fVec3[0];
			fRec8[1] = fRec8[0];
			iRec9[1] = iRec9[0];
			fRec10[2] = fRec10[1];
			fRec10[1] = fRec10[0];
			fVec4[1] = fVec4[0];
			fRec11[1] = fRec11[0];
			iRec12[1] = iRec12[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fVec5[1] = fVec5[0];
			fRec14[1] = fRec14[0];
			iRec15[1] = iRec15[0];
			fRec16[2] = fRec16[1];
			fRec16[1] = fRec16[0];
			fVec6[1] = fVec6[0];
			fRec17[1] = fRec17[0];
			iRec18[1] = iRec18[0];
			fRec19[2] = fRec19[1];
			fRec19[1] = fRec19[0];
			fVec7[1] = fVec7[0];
			fRec20[1] = fRec20[0];
			iRec21[1] = iRec21[0];
			fRec22[2] = fRec22[1];
			fRec22[1] = fRec22[0];
			fVec8[1] = fVec8[0];
			fRec23[1] = fRec23[0];
			iRec24[1] = iRec24[0];
			fRec25[2] = fRec25[1];
			fRec25[1] = fRec25[0];
			fVec9[1] = fVec9[0];
			fRec26[1] = fRec26[0];
			iRec27[1] = iRec27[0];
			fRec28[2] = fRec28[1];
			fRec28[1] = fRec28[0];
			fVec10[1] = fVec10[0];
			fRec29[1] = fRec29[0];
			iRec30[1] = iRec30[0];
			fRec33[1] = fRec33[0];
			fVec11[1] = fVec11[0];
			fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fVec12[1] = fVec12[0];
			iRec35[1] = iRec35[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fVec13[1] = fVec13[0];
			fRec36[1] = fRec36[0];
			iRec37[1] = iRec37[0];
			fRec38[2] = fRec38[1];
			fRec38[1] = fRec38[0];
			fVec14[1] = fVec14[0];
			fRec39[1] = fRec39[0];
			iRec40[1] = iRec40[0];
			fRec41[2] = fRec41[1];
			fRec41[1] = fRec41[0];
			fVec15[1] = fVec15[0];
			fRec42[1] = fRec42[0];
			iRec43[1] = iRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fVec16[1] = fVec16[0];
			fRec45[1] = fRec45[0];
			iRec46[1] = iRec46[0];
			fRec47[2] = fRec47[1];
			fRec47[1] = fRec47[0];
			fVec17[1] = fVec17[0];
			fRec48[1] = fRec48[0];
			iRec49[1] = iRec49[0];
			fRec50[2] = fRec50[1];
			fRec50[1] = fRec50[0];
			fVec18[1] = fVec18[0];
			fRec51[1] = fRec51[0];
			iRec52[1] = iRec52[0];
			fRec53[2] = fRec53[1];
			fRec53[1] = fRec53[0];
			fVec19[1] = fVec19[0];
			fRec54[1] = fRec54[0];
			iRec55[1] = iRec55[0];
			fRec56[2] = fRec56[1];
			fRec56[1] = fRec56[0];
			fVec20[1] = fVec20[0];
			fRec57[1] = fRec57[0];
			iRec58[1] = iRec58[0];
			fRec59[2] = fRec59[1];
			fRec59[1] = fRec59[0];
			fVec21[1] = fVec21[0];
			fRec60[1] = fRec60[0];
			iRec61[1] = iRec61[0];
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
  od::Parameter mInGain{"InGain"};
  od::Parameter mLeftMix{"LeftMix"};
  od::Parameter mOutGain{"OutGain"};
  od::Parameter mRightMix{"RightMix"};
  od::Parameter mDecay{"Decay"};
  od::Parameter mEnvModeDecay{"EnvModeDecay"};
  od::Parameter mLeftMode{"LeftMode"};
  od::Parameter mLeftNote{"LeftNote"};
  od::Parameter mRightMode{"RightMode"};
  od::Parameter mRightNote{"RightNote"};
  od::Parameter mpoly_note_0{"poly_note_0"};
  od::Parameter mpoly_note_1{"poly_note_1"};
  od::Parameter mpoly_note_2{"poly_note_2"};
  virtual void addParam(const char* label, FAUSTFLOAT* zone) {
    if (strcmp(label, "InGain") == 0) {
      ffInGain = zone;
    }
    if (strcmp(label, "LeftMix") == 0) {
      ffLeftMix = zone;
    }
    if (strcmp(label, "OutGain") == 0) {
      ffOutGain = zone;
    }
    if (strcmp(label, "RightMix") == 0) {
      ffRightMix = zone;
    }
    if (strcmp(label, "Decay") == 0) {
      ffDecay = zone;
    }
    if (strcmp(label, "EnvModeDecay") == 0) {
      ffEnvModeDecay = zone;
    }
    if (strcmp(label, "LeftMode") == 0) {
      ffLeftMode = zone;
    }
    if (strcmp(label, "LeftNote") == 0) {
      ffLeftNote = zone;
    }
    if (strcmp(label, "poly_note_0") == 0) {
      ffpoly_note_0 = zone;
    }
    if (strcmp(label, "poly_note_1") == 0) {
      ffpoly_note_1 = zone;
    }
    if (strcmp(label, "poly_note_2") == 0) {
      ffpoly_note_2 = zone;
    }
    if (strcmp(label, "Decay") == 0) {
      ffDecay = zone;
    }
    if (strcmp(label, "EnvModeDecay") == 0) {
      ffEnvModeDecay = zone;
    }
    if (strcmp(label, "RightMode") == 0) {
      ffRightMode = zone;
    }
    if (strcmp(label, "RightNote") == 0) {
      ffRightNote = zone;
    }
    if (strcmp(label, "poly_note_0") == 0) {
      ffpoly_note_0 = zone;
    }
    if (strcmp(label, "poly_note_1") == 0) {
      ffpoly_note_1 = zone;
    }
    if (strcmp(label, "poly_note_2") == 0) {
      ffpoly_note_2 = zone;
    }
  }

private:
  FAUSTFLOAT* ffInGain;
  FAUSTFLOAT* ffLeftMix;
  FAUSTFLOAT* ffOutGain;
  FAUSTFLOAT* ffRightMix;
  FAUSTFLOAT* ffDecay;
  FAUSTFLOAT* ffEnvModeDecay;
  FAUSTFLOAT* ffLeftMode;
  FAUSTFLOAT* ffLeftNote;
  FAUSTFLOAT* ffRightMode;
  FAUSTFLOAT* ffRightNote;
  FAUSTFLOAT* ffpoly_note_0;
  FAUSTFLOAT* ffpoly_note_1;
  FAUSTFLOAT* ffpoly_note_2;
  DspWingie DSP;

#endif

};


#endif
