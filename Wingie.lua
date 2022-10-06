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

function Wingie:init(args)
  args.title = "Wingie"
  args.mnemonic = "WG"
  Unit.init(self, args)
end

function Wingie:onLoadGraph(channelCount)
  local wingie = self:addObject("wingie", lib.Wingie())

  local decay = self:addObject("Decay", app.ParameterAdapter())
  local left_note = self:addObject("LeftNote", app.ParameterAdapter())
  local right_note = self:addObject("RightNote", app.ParameterAdapter())
  local left_mix = self:addObject("LeftMix", app.ParameterAdapter())
  local right_mix = self:addObject("RightMix", app.ParameterAdapter())
  local left_mode = self:addObject("LeftMode", app.ParameterAdapter())
  local right_mode = self:addObject("RightMode", app.ParameterAdapter())
  local in_gain = self:addObject("InGain", app.ParameterAdapter())
  local out_gain = self:addObject("OutGain", app.ParameterAdapter())

  tie(wingie, "Decay", decay, "Out")
  self:addMonoBranch("decay", decay, "In", decay, "Out")

  tie(wingie, "LeftMix", left_mix, "Out")
  self:addMonoBranch("left_mix", left_mix, "In", left_mix, "Out")

  tie(wingie, "RightMix", right_mix, "Out")
  self:addMonoBranch("right_mix", right_mix, "In", right_mix, "Out")

  tie(wingie, "LeftNote", left_note, "Out")
  self:addMonoBranch("left_note", left_note, "In", left_note, "Out")

  tie(wingie, "RightNote", right_note, "Out")
  self:addMonoBranch("right_note", right_note, "In", right_note, "Out")

  tie(wingie, "InGain", in_gain, "Out")
  self:addMonoBranch("in_gain", in_gain, "In", in_gain, "Out")

  tie(wingie, "OutGain", out_gain, "Out")
  self:addMonoBranch("out_gain", out_gain, "In", out_gain, "Out")

  tie(wingie, "LeftMode", left_mode, "Out")
  self:addMonoBranch("left_mode", left_mode, "In", left_mode, "Out")

  tie(wingie, "RightMode", right_mode, "Out")
  self:addMonoBranch("right_mode", right_mode, "In", right_mode, "Out")

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
    "decay",
    "left_note",
    "right_note",
    "left_mode",
    "right_mode",
    "left_mix",
    "right_mix",
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
    branch = branches.decay,
    gainbias = objects.Decay,
    range = objects.Decay,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,10]"),
    initialBias = 5,
  }

  controls.left_mix = GainBias {
    button = "L Mix",
    description = "Left Mix",
    branch = branches.left_mix,
    gainbias = objects.LeftMix,
    range = objects.LeftMix,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 1,
  }

  controls.right_mix = GainBias {
    button = "R Mix",
    description = "Right Mix",
    branch = branches.right_mix,
    gainbias = objects.RightMix,
    range = objects.RightMix,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 1,
  }

  controls.left_note = GainBias {
    button = "L Pitch",
    description = "Left Pitch",
    branch = branches.left_note,
    gainbias = objects.LeftNote,
    range = objects.LeftNote,
    biasUnits = app.unitNone,
    biasMap = intMap(12,96),
    biasPrecision = 0,
    initialBias = 36,
  }

  controls.right_note = GainBias {
    button = "R Pitch",
    description = "Right Pitch",
    branch = branches.right_note,
    gainbias = objects.RightNote,
    range = objects.RightNote,
    biasUnits = app.unitNone,
    biasMap = intMap(12,96),
    biasPrecision = 0,
    initialBias = 36,
  }

  controls.left_mode = GainBias {
    button = "L Mode",
    description = "Left Mode",
    branch = branches.left_mode,
    gainbias = objects.LeftMode,
    range = objects.LeftMode,
    biasUnits = app.unitNone,
    biasMap = intMap(0,4),
    biasPrecision = 0,
    initialBias = 0,
  }

  controls.right_mode = GainBias {
    button = "R Mode",
    description = "Right Mode",
    branch = branches.right_mode,
    gainbias = objects.RightMode,
    range = objects.RightMode,
    biasUnits = app.unitNone,
    biasMap = intMap(0,4),
    biasPrecision = 0,
    initialBias = 0,
  }

  controls.in_gain = GainBias {
    button = "In Gain",
    description = "In Gain",
    branch = branches.in_gain,
    gainbias = objects.InGain,
    range = objects.InGain,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.5,
  }

  controls.out_gain = GainBias {
    button = "Out Gain",
    description = "Out Gain",
    branch = branches.out_gain,
    gainbias = objects.OutGain,
    range = objects.OutGain,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.5,
  }

  return controls, views
end

return Wingie
