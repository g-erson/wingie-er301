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
  addParameter(mInGain);
  addParameter(mLeftMix);
  addParameter(mOutGain);
  addParameter(mRightMix);
  addParameter(mDecay);
  addParameter(mEnvModeDecay);
  addParameter(mLeftMode);
  addParameter(mLeftNote);
  addParameter(mpoly_note_0);
  addParameter(mpoly_note_1);
  addParameter(mpoly_note_2);
  addParameter(mDecay);
  addParameter(mEnvModeDecay);
  addParameter(mRightMode);
  addParameter(mRightNote);
  addParameter(mpoly_note_0);
  addParameter(mpoly_note_1);
  addParameter(mpoly_note_2);
  DSP.init(globalConfig.sampleRate);
  DSP.buildUserInterface(&uiParams);
}
Wingie::~Wingie()
{ }
void Wingie::process()
{
  FAUSTFLOAT* inputs[] = { mInL.buffer(), mInR.buffer() };
  FAUSTFLOAT* outputs[] = { mOutL.buffer(), mOutR.buffer() };
  *ffInGain = CLAMP(mInGain.target(), 0, 1);
  *ffLeftMix = CLAMP(mLeftMix.target(), 0, 1);
  *ffOutGain = CLAMP(mOutGain.target(), 0, 1);
  *ffRightMix = CLAMP(mRightMix.target(), 0, 1);
  *ffDecay = CLAMP(mDecay.target(), 0.1, 10);
  *ffEnvModeDecay = CLAMP(mEnvModeDecay.target(), 0, 1);
  *ffLeftMode = CLAMP(mLeftMode.target(), 0, 4);
  *ffLeftNote = CLAMP(mLeftNote.target(), 12, 96);
  *ffpoly_note_0 = CLAMP(mpoly_note_0.target(), 24, 96);
  *ffpoly_note_1 = CLAMP(mpoly_note_1.target(), 24, 96);
  *ffpoly_note_2 = CLAMP(mpoly_note_2.target(), 24, 96);
  *ffDecay = CLAMP(mDecay.target(), 0.1, 10);
  *ffEnvModeDecay = CLAMP(mEnvModeDecay.target(), 0, 1);
  *ffRightMode = CLAMP(mRightMode.target(), 0, 4);
  *ffRightNote = CLAMP(mRightNote.target(), 12, 96);
  *ffpoly_note_0 = CLAMP(mpoly_note_0.target(), 24, 96);
  *ffpoly_note_1 = CLAMP(mpoly_note_1.target(), 24, 96);
  *ffpoly_note_2 = CLAMP(mpoly_note_2.target(), 24, 96);
  DSP.compute(FRAMELENGTH, inputs, outputs);
}

