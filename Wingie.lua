local lib = require "friendsofwingie.libwingie"

local Class = require "Base.Class"
local Encoder = require "Encoder"
local Fader = require "Unit.ViewControl.Fader"
local GainBias = require "Unit.ViewControl.GainBias"
local Gate = require "Unit.ViewControl.Gate"
local Pitch = require "Unit.ViewControl.Pitch"
local Unit = require "Unit"

local Wingie = Class {}
Wingie:include(Unit)

-- POLY_MODE 0
-- STRING_MODE 1
-- BAR_MODE 2
-- CAVE_MODE 3

function Wingie:init(args)
  args.title = "Wingie"
  args.mnemonic = "WG"
  Unit.init(self, args)
end

function Wingie:addParameterAdapterBranch(name, obj, defaultGain)
  local pa = self:addObject(name, app.ParameterAdapter())
  tie(obj, name, pa, "Out")
  if defaultGain then
    pa:hardSet("Gain", defaultGain)
  end
  return self:addMonoBranch(name, pa, "In", pa, "Out")
end

function Wingie:onLoadGraph(channelCount)
  local wingie = self:addObject("wingie", lib.Wingie())

  local decay = self:addParameterAdapterBranch("Decay", wingie)
  local note = self:addParameterAdapterBranch("Note", wingie, 1)
  local note1 = self:addParameterAdapterBranch("Note1", wingie, 1)
  local note2 = self:addParameterAdapterBranch("Note2", wingie, 1)
  local mix = self:addParameterAdapterBranch("Mix",wingie)
  local freq = self:addParameterAdapterBranch("Freq",wingie)
  local mode = self:addParameterAdapterBranch("Mode",wingie)
  local in_gain = self:addParameterAdapterBranch("InGain",wingie)
  local out_gain = self:addParameterAdapterBranch("OutGain",wingie)

  connect(wingie, "OutL", self, "Out1")
  connect(self, "In1", wingie, "InL")

  if channelCount == 1 then
    connect(self, "In1", wingie, "InR")
  else
    connect(self, "In2", wingie, "InR")
    connect(wingie, "OutR", self, "Out2")
  end
end

local views = {
  expanded = {
    "freq",
    "mode",
    "note",
    "note1",
    "note2",
    "decay",
    "mix",
    "in_gain",
    "out_gain",
  },
  collapsed = {},
}

local function intMap(min, max)
  local map = app.LinearDialMap(min, max)
  map:setSteps(5, 1, 0.25, 0.25);
  map:setRounding(1)
  return map
end

function Wingie:onLoadViews(objects, branches)
  local controls = {}

  controls.decay = GainBias {
    button = "Decay",
    description = "decay",
    branch = branches.Decay,
    gainbias = objects.Decay,
    range = objects.Decay,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,10]"),
    initialBias = 5,
  }

  controls.mix = GainBias {
    button = "Mix",
    description = "Mix",
    branch = branches.Mix,
    gainbias = objects.Mix,
    range = objects.Mix,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 1,
  }

  controls.freq = GainBias {
    button      = "Freq",
    description = "Freq",
    branch      = branches.Freq,
    gainbias    = objects.Freq,
    range       = objects.Freq,
    biasMap     = Encoder.getMap("oscFreq"),
    biasUnits   = app.unitHertz,
    initialBias = 27.5,
    gainMap     = Encoder.getMap("freqGain"),
    scaling     = app.octaveScaling
  }
  
  controls.note = Pitch {
    button = "V/Oct",
    description = "V/Oct",
    branch = branches.Note,
    offset = objects.Note,
    range = objects.Note
  }

  controls.note1 = Pitch {
    button = "V/Oct 1",
    description = "V/Oct",
    branch = branches.Note1,
    offset = objects.Note1,
    range = objects.Note1
  }

  controls.note2 = Pitch {
    button = "V/Oct 2",
    description = "V/Oct",
    branch = branches.Note2,
    offset = objects.Note2,
    range = objects.Note2
  }

  controls.mode = GainBias {
    button = "Mode",
    description = "Mode",
    branch = branches.Mode,
    gainbias = objects.Mode,
    range = objects.Mode,
    biasUnits = app.unitNone,
    biasMap = intMap(0,3),
    biasPrecision = 0,
    initialBias = 0,
  }

  controls.in_gain = GainBias {
    button = "In Gain",
    description = "In Gain",
    branch = branches.InGain,
    gainbias = objects.InGain,
    range = objects.InGain,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.1,
  }

  controls.out_gain = GainBias {
    button = "Out Gain",
    description = "Out Gain",
    branch = branches.OutGain,
    gainbias = objects.OutGain,
    range = objects.OutGain,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.7,
  }

  return controls, views
end

return Wingie
