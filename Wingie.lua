local lib = require "faustian.libfaustian"

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
  local left_thresh = self:addObject("LeftThreshold", app.ParameterAdapter())
  local right_thresh = self:addObject("RightThreshold", app.ParameterAdapter())
  local left_note = self:addObject("LeftNote", app.ParameterAdapter())
  local right_note = self:addObject("RightNote", app.ParameterAdapter())
  local left_mix = self:addObject("LeftMix", app.ParameterAdapter())
  local right_mix = self:addObject("RightMix", app.ParameterAdapter())
  local in_gain = self:addObject("InGain", app.ParameterAdapter())
  local out_gain = self:addObject("OutGain", app.ParameterAdapter())

  tie(wingie, "Decay", decay, "Out")
  self:addMonoBranch("decay", decay, "In", decay, "Out")

  tie(wingie, "LeftThreshold", left_thresh, "Out")
  self:addMonoBranch("left_thresh", left_thresh, "In", left_thresh, "Out")

  tie(wingie, "RightThreshold", right_thresh, "Out")
  self:addMonoBranch("right_thresh", right_thresh, "In", right_thresh, "Out")

  tie(wingie, "LeftMix", left_mix, "Out")
  self:addMonoBranch("left_mix", left_mix, "In", left_mix, "Out")

  tie(wingie, "RightMix", right_mix, "Out")
  self:addMonoBranch("right_mix", right_mix, "In", right_mix, "Out")

  tie(wingie, "LeftNote", left_note, "Out")
  self:addMonoBranch("left_note", left_note, "In", left_note, "Out")

  tie(wingie, "RightNote", right_note, "Out")
  self:addMonoBranch("right_note", right_note, "In", right_note, "Out")

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
    "delay",
    "left_thresh",
    "right_thresh",
    "left_mix",
    "right_mix",
    "left_note",
    "right_note",
  },
  collapsed = {},
}

function Wingie:onLoadViews(objects, branches)
  local controls = {}

  controls.bandwidth = GainBias {
    button = "delay",
    description = "delay",
    branch = branches.delay,
    gainbias = objects.Delay,
    range = objects.Delay,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,10]"),
    initialBias = 5,
  }

  controls.decay = GainBias {
    button = "L/ Thresh",
    description = "Left Thresh",
    branch = branches.left_thresh,
    gainbias = objects.LeftThreshold,
    range = objects.LeftThreshold,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.8,
  }

  controls.decay = GainBias {
    button = "R/ Thresh",
    description = "Right Thresh",
    branch = branches.right_thresh,
    gainbias = objects.RightThreshold,
    range = objects.RightThreshold,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.8,
  }

  controls.decay = GainBias {
    button = "L/ Mix",
    description = "Left Mix",
    branch = branches.left_mix,
    gainbias = objects.LeftMix,
    range = objects.LeftMix,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.8,
  }

  controls.decay = GainBias {
    button = "R/ Mix",
    description = "Right Mix",
    branch = branches.right_mix,
    gainbias = objects.RightMix,
    range = objects.RightMix,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.8,
  }

  controls.decay = GainBias {
    button = "L/ Note",
    description = "Left Note",
    branch = branches.left_note,
    gainbias = objects.LeftNote,
    range = objects.LeftNote,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.8,
  }

  controls.decay = GainBias {
    button = "R/ Note",
    description = "Right Note",
    branch = branches.right_note,
    gainbias = objects.RightNote,
    range = objects.RightNote,
    biasUnits = app.unitNone,
    biasMap = Encoder.getMap("[0,1]"),
    initialBias = 0.8,
  }

  return controls, views
end

return Wingie
