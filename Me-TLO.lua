-- Tests are ran against the following standard:
-- LVL 85 Male Troll
-- Location The Plane of Knowledge
-- Do not click any equipment for buffs or AAs
-- Do not cast any spells

-- @ToDo Create spell list just in case.
-- @ToDo SetUp should remove any buffs

local test = require 'TestSuite.mqTest'

---@type Mq
local mq = require 'mq'

---We're going to access the same TLO a lot - just saving keystokes here...
local Me = mq.TLO.Me

-- datatype:spawn members

test.spawn.AARank = function()
    test.equal(Me.AARank(), 3)
end

test.spawn.AATitle = function()
    test.equal(Me.AATitle(), '')
end

test.spawn.ActorDef = function()
    test.equal(Me.ActorDef(), 'TRM_ACTORDEF')
end

test.spawn.Address = function()
    test.is_nil(Me.Address())
end

test.spawn.AFK = function()
    if(Me.AFK()) then
        mq.cmd.afk()
    end
    test.is_false(Me.AFK())
    mq.cmd.afk()
end

test.spawn.Agressive = function()
    test.is_false(Me.Aggressive())
end

test.spawn.Animation = function()
    test.is_number(Me.Animation())
end

test.spawn.Anonymous = function()
    if(Me.Anonymous()) then
        mq.cmd.anon()
    end
    test.is_false(Me.Anonymous())
end

test.spawn.Assist = function()
    test.is_false(Me.Assist())
end

test.spawn.AssistName = function()
    test.equal(Me.AssistName(), '')
end

test.spawn.bAlwaysShowAura = function()
    test.is_false(Me.bAlwaysShowAura())
end

test.spawn.bBetaBuffed = function()
    test.is_false(Me.bBetaBuffed())
end

test.spawn.BearingToTarget = function()
    ---Issue with this member.  Always returns 0
    ---https://gitlab.com/macroquest/next/mqnext/-/issues/330
end

test.spawn.Binding = function()
    test.is_false(Me.Binding())
end

test.spawn.Blind = function()
    test.equal(Me.Blind(),0)
end

test.spawn.Body = function()
    test.equal(Me.Body(), 1)
end

test.broken.skip = true
test.broken.bShowHelm = function()
    test.is_true(Me.bShowHelm())
end

test.spawn.bStationary = function()
    test.is_false(Me.bStationary())
end

test.spawn.bTempPet = function()
    test.is_false(Me.bTempPet())
end

test.spawn.Buyer = function()
    test.is_false(Me.Buyer())
end

test.spawn.bWaitingForPort = function()
    test.is_false(Me.bWaitingForPort())
end

test.spawn.CachedBuff = function()
    mq.cmd.target()
    mq.cmd.cast(1)
    mq.delay('4s')
    test.equal(Me.CachedBuff('Gather Shadows').ID(), 522)
    mq.cmd.keypress('Esc')
    mq.cmd.removebuff('Gather Shadows')
end

test.spawn.CachedBuffCount = function()
    test.not_equal(Me.CachedBuffCount(), 0)
end

test.spawn.CanSplashLand = function()
    test.is_true(Me.CanSplashLand())
end

test.spawn.Casting = function()
    test.is_nil(Me.Casting())
end

test.spawn.CeilingHeightAtCurrLocation = function()
    test.is_number(Me.CeilingHeightAtCurrLocation())
end

test.spawn.Class = function()
    test.equal(Me.Class(), 5)
end

test.spawn.CleanName = function()
    test.is_string(Me.CleanName())
end

test.spawn.CollisionCounter = function()
    test.is_number(Me.CollisionCounter())
end

test.spawn.CombatSkillTicks = function()
    test.is_nil(Me.CombatSkillTicks())
end

test.spawn.ConColor = function()
    test.equal(Me.ConColor(), 'WHITE')
end

test.spawn.ContractorID = function()
    test.equal(Me.ContractorID(), 0)
end

test.spawn.CorpseDragCount = function()
    test.equal(Me.CorpseDragCount(), 0)
end

test.spawn.CurrentEndurance = function()
    test.equal(Me.CurrentEndurance(), 29423)
end

test.spawn.CurrentHps = function()
    test.equal(Me.CurrentHPs(), 34736)
end

test.spawn.CurrentMana = function()
    --- Casting spells during testing means we have to use some fuzzy logic
    test.almost_equal(Me.CurrentMana(), 29000, 2000)
end

test.spawn.D = function()
    test.is_number(Me.D())
end

test.spawn.Dead = function()
    test.is_false(Me.Dead())
end

test.spawn.Diety = function()
    test.equal(Me.Deity(), 203)
end

test.spawn.DisplayName = function()
    test.is_string(Me.DisplayName())
end

test.spawn.Distance = function()
    test.equal(Me.Distance(), 0)
end

test.spawn.Distance3D = function()
    test.equal(Me.Distance3D(), 0)
end

test.spawn.DistanceN = function()
    test.equal(Me.DistanceN(), 0)
end

test.spawn.DistancePredict = function()
    test.equal(Me.DistancePredict(), 0)
end

test.spawn.DistanceU = function()
    test.equal(Me.DistanceU(), 0)
end

test.spawn.DistanceW = function()
    test.equal(Me.DistanceW(), 0)
end

test.spawn.DistanceX = function()
    test.equal(Me.DistanceX(), 0)
end

test.spawn.DistanceY = function()
    test.equal(Me.DistanceY(), 0)
end

test.spawn.DistanceZ = function()
    test.equal(Me.DistanceZ(), 0)
end

test.spawn.DraggingPlayer = function()
    test.is_false(Me.DraggingPlayer())
end

test.spawn.DragName = function()
    test.is_nil(Me.DragNames())
end

test.spawn.Ducking = function()
    test.is_false(Me.Ducking())
end

test.spawn.E = function()
    test.is_number(Me.E())
end

test.spawn.EQLoc = function()
    test.equal(Me.EQLoc(), string.match(Me.EQLoc(), "^%D?%d+%.%d+,%D+%d+%.%d+,%D+%d+%.%d+"))
end

test.spawn.Equipment = function()
    test.is_nil(Me.Equipment())
end

test.spawn.FD = function()
    test.equal(Me.FD(), 0)
end

test.spawn.FeetWet = function()
    test.is_false(Me.FeetWet())
end

test.spawn.Feigning = function()
    test.is_false(Me.Feigning())
end

test.spawn.Fleeing = function()
    --This member is better suited for mobs, and  has inconsitent output for characters.
    test.is_boolean(Me.Fleeing())
end

test.spawn.FloorZ = function()
    test.is_number(Me.FloorZ())
end

test.spawn.following = function()
    test.is_nil(Me.Following())
end

test.spawn.Gender = function()
    test.equal(Me.Gender(), 'male')
end

test.spawn.GM = function()
    test.is_false(Me.GM())
end

test.spawn.GMRank = function()
    test.equal(Me.GMRank(), 0)
end

test.spawn.GroupLeader = function()
    test.is_false(Me.GroupLeader())
end

test.spawn.Guild = function()
    test.is_nil(Me.Guild())
end

test.spawn.GuildStatus = function()
    test.is_nil(Me.GuildStatus())
end

test.spawn.Heading = function()
    test.almost_equal(Me.Heading(), 180, 180)
end

test.spawn.HeadingTo = function()
    test.equal(Me.HeadingTo(), 90)
end

test.spawn.HeadingToLoc = function()
    test.almost_equal(Me.HeadingToLoc(0,0)(), 180, 180)
end

test.spawn.Height = function()
    test.is_number(Me.Height())
end

test.spawn.Holding = function()
    test.is_true(Me.Holding())
end

test.spawn.HoldingAnimation = function()
    test.equal(Me.HoldingAnimation(), 3)
end

test.spawn.Hovering = function()
    test.is_false(Me.Hovering())
end

test.spawn.ID = function()
    test.is_number(Me.ID())
end

test.spawn.InPvPArea = function()
    test.equal(Me.InPvPArea(), 0)
end

test.spawn.Invis = function()
    test.is_false(Me.Invis())
end

test.spawn.Invited = function()
    test.is_false(Me.Invited())
end

test.spawn.Inviter = function()
    test.equal(Me.Inviter(), '')
end

test.spawn.IsBeserk = function()
    test.equal(Me.IsBerserk(), 0)
end

test.spawn.IsPassenger = function()
    test.equal(Me.IsPassenger(), 0)
end

test.spawn.IsSummoned = function()
    test.is_false(Me.IsSummoned())
end

test.spawn.LastCastNum = function()
    test.equal(Me.LastCastNum(), 0)
end

test.spawn.LastCastTime = function()
    test.is_number(Me.LastCastTime())
end

test.spawn.Levitating = function()
    test.is_false(Me.Levitating())
end

test.spawn.LFG = function()
    test.is_false(Me.LFG())
end

test.spawn.Light = function()
    test.equal(Me.Light(), 'LS')
end

test.spawn.LineOfSight = function()
    test.is_true(Me.LineOfSight())
end

test.spawn.Linkdead = function()
    test.is_false(Me.Linkdead())
end

test.spawn.Loc = function()
    test.equal(Me.Loc(), string.match(Me.Loc(), "^%D?%d+%.%d+,%D+%d+%.%d+"))
end

test.spawn.LocXY = function()
    test.equal(Me.LocYX(), string.match(Me.LocYX(), "^%D?%d+,%D+%d+"))
end

test.spawn.LocXYZ = function()
    test.equal(Me.LocYXZ(), string.match(Me.LocYXZ(), "^%D?%d+%.%d+,%D+%d+%.%d+,%D+%d+%.%d+"))
end

test.spawn.Look = function()
    test.almost_equal(Me.Look(), 0, 128)
end

test.spawn.Mark = function()
    test.is_nil(Me.Mark())
end

test.spawn.Master = function()
    test.is_nil(Me.Master())
end

test.spawn.maxEndurance = function()
    test.almost_equal(Me.MaxEndurance(), 29243, 2000)
end

test.spawn.MaxHPs = function()
    test.almost_equal(Me.MaxHPs(), 34736, 2500)
end

test.spawn.MaxMana = function()
    test.almost_equal(Me.MaxMana(), 29912, 2000)
end

test.spawn.MaxRange = function()
    test.equal(Me.MaxRange(), 16)
end

test.spawn.MaxRangeTo = function()
    test.equal(Me.MaxRangeTo(), 16)
end

test.spawn.MercID = function()
    test.equal(Me.MercID(), 0)
end

test.spawn.Mount = function()
    test.is_nil(Me.Mount())
end

test.spawn.Moving = function()
    test.is_false(Me.Moving())
end

test.spawn.MQLoc = function()
    test.equal(Me.MQLoc(), string.match(Me.MQLoc(), "^%D?%d+%.%d+,%D+%d+%.%d+,%D+%d+%.%d+"))
end

test.spawn.N = function()
    test.is_number(Me.N())
end

test.spawn.Named = function()
    test.is_false(Me.Named())
end

test.spawn.NearestSpawn = function()
    test.equal(Me.NearestSpawn('radius 0 pc')(), Me.CleanName())
end

test.broken.Next = function()
    --https://gitlab.com/macroquest/next/mqnext/-/issues/336
end

test.spawn.Owner = function()
    test.is_nil(Me.Owner())
end

test.spawn.PctEndurance = function()
    test.equal(Me.PctEndurance(), 100)
end

test.spawn.PctHPs = function()
    test.equal(Me.PctHPs(), 100)
end

test.spawn.PctMana = function()
    test.almost_equal(Me.PctMana(), 100, 5)
end

test.spawn.Pet = function()
    test.equal(Me.Pet(), 'NO PET')
end

test.spawn.PlayerState = function()
    test.equal(Me.PlayerState(), 64)
end

test.spawn.Prev = function()
    test.is_string(Me.Prev())
end

test.spawn.Primary = function()
    test.equal(Me.Primary(), 11801)
end

test.spawn.pTouchSwitch = function()
    test.equal(Me.pTouchingSwitch(), 0)
end

test.spawn.Race = function()
    test.equal(Me.Race(), 9)
end

test.spawn.Roleplaying = function()
    test.is_false(Me.Roleplaying())
end

test.spawn.S = function()
    test.is_number(Me.S())
end

test.spawn.Secondary = function()
    test.equal(Me.Secondary(), 11706)
end

test.spawn.SeeInvis = function()
    test.is_nil(Me.SeeInvis())
end

test.spawn.Sitting = function()
    test.is_false(Me.Sitting())
end

test.spawn.Sneaking = function()
    test.is_false(Me.Sneaking())
end

test.spawn.SpawnStatus = function()
    test.is_nil(Me.SpawnStatus())
end

test.spawn.Speed = function()
    test.equal(Me.Speed(), 0)
end

test.spawn.Standing = function()
    test.is_true(Me.Standing())
end

test.spawn.StandState = function()
    test.equal(Me.StandState(), 100)
end

test.spawn.State = function()
    test.equal(Me.State(), 'STAND')
end

test.spawn.Stuck = function()
    test.is_false(Me.Stuck())
end

test.spawn.Stunned = function()
    test.is_false(Me.Stunned())
end

test.spawn.Suffix = function()
    test.equal(Me.Suffix(), '')
end

test.spawn.Surname = function()
    test.equal(Me.Surname(), '')
end

test.spawn.Targetable = function()
    test.is_true(Me.Targetable())
end

test.spawn.TargetOfTarget = function()
    test.is_nil(Me.TargetOfTarget())
end

test.spawn.TimeBeenDead = function()
    test.is_number(Me.TimeBeenDead())
end

test.spawn.Title = function()
    test.equal(Me.Title(), '')
end

test.spawn.Trader = function()
    test.is_false(Me.Trader())
end

test.spawn.Type = function()
    test.equal(Me.Type(), 'PC')
end

test.spawn.U = function()
    test.is_number(Me.U())
end

test.spawn.Underwater = function()
    test.is_false(Me.Underwater())
end

test.spawn.W = function()
    test.is_number(Me.W())
end

test.spawn.WarCry = function()
    test.is_number(Me.WarCry())
end

test.spawn.X = function()
    test.is_number(Me.X())
end

test.spawn.Y = function()
    test.is_number(Me.X())
end

test.spawn.Z = function()
    test.is_number(Me.Z())
end

-- datatype:character members

-- datatype:target members

test.summary()
