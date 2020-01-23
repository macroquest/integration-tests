|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2CharacterType
 *
 ***|






sub start_MQ2GroupType()
	/echo
	OUT Testing::\awMQ2GroupType\ax (\a-tGroup.\ax)
	LOG
	LOG Testing::MQ2GroupType


	| make sure we are in a group. if we are not. we skip this entire section of testing
		/if (!${Range.Between[1,5:${Group}]}) {
			/invoke ${out[skip, Group.]}
			OUT ....(\a-tMUST BE IN A GROUP\ax)
			/return FALSE
		}

	| Members
		/if (!${Range.Between[1,6:${Group.Members}]}) {
			/invoke ${out[bad, Members, int, ${Group.Members}]}
		} else {
			/invoke ${out[good, Members]}
		}

	| Leader
		/if (${Select[${Group.Leader},NULL]}) {
			/invoke ${out[inc, Leader, string, ${Group.Leader}]}
			OUT ....(\a-tNo group leader set, or this is broke\ax)
		} else {
			/invoke ${out[good, Leader]}
		}

	| GroupSize
		/if (!${Range.Between[1,6:${Group.GroupSize}]}) {
			/invoke ${out[bad, GroupSize, int, ${Group.GroupSize}]}
		} else {
			/invoke ${out[good, GroupSize]}
		}

	| MainTank
		/if (${Select[${Group.MainTank},NULL]}) {
			/invoke ${out[inc, MainTank, string, ${Group.MainTank}]}
			OUT ....(\a-tNo group MainTank set, or this is broke\ax)
		} else {
			/invoke ${out[good, MainTank]}
		}

	| MainAssist
		/if (${Select[${Group.MainAssist},NULL]}) {
			/invoke ${out[inc, Leader, string, ${Group.MainAssist}]}
			OUT ....(\a-tNo group MainAssist set, or this is broke\ax)
		} else {
			/invoke ${out[good, MainAssist]}
		}

	| Puller
		/if (${Select[${Group.Puller},NULL]}) {
			/invoke ${out[inc, Puller, string, ${Group.Puller}]}
			OUT ....(\a-tNo group Puller set, or this is broke\ax)
		} else {
			/invoke ${out[good, Puller]}
		}

	| MarkNpc
		/if (${Select[${Group.MarkNpc},NULL]}) {
			/invoke ${out[inc, MarkNpc, string, ${Group.MarkNpc}]}
			OUT ....(\a-tNo group MarkNpc set, or this is broke\ax)
		} else {
			/invoke ${out[good, MarkNpc]}
		}

	| MasterLooter
		/if (${Select[${Group.MasterLooter},NULL]}) {
			/invoke ${out[inc, MasterLooter, string, ${Group.MasterLooter}]}
			OUT ....(\a-tNo group MasterLooter set, or this is broke\ax)
		} else {
			/invoke ${out[good, MasterLooter]}
		}

	| AnyoneMissing
		/if (!${Select[${Group.AnyoneMissing},TRUE,FALSE]}) {
			/invoke ${out[bad, AnyoneMissing, bool, ${Group.AnyoneMissing}]}
		} else {
			/invoke ${out[good, AnyoneMissing]}
		}

	| Present
		/if (!${Range.Between[1,5:${Group.Present}]}) {
			/invoke ${out[bad, Present, int, ${Group.Present}]}
		} else {
			/invoke ${out[good, Present]}
		}

	| MercenaryCount
		/if (!${Range.Between[0,3:${Group.MercenaryCount}]}) {
			/invoke ${out[bad, MercenaryCount, int, ${Group.MercenaryCount}]}
		} else {
			/invoke ${out[good, MercenaryCount]}
		}

	| TankMercCount
		/if (!${Range.Between[0,3:${Group.TankMercCount}]}) {
			/invoke ${out[bad, TankMercCount, int, ${Group.TankMercCount}]}
		} else {
			/invoke ${out[good, TankMercCount]}
		}

	| HealerMercCount
		/if (!${Range.Between[0,3:${Group.HealerMercCount}]}) {
			/invoke ${out[bad, HealerMercCount, int, ${Group.HealerMercCount}]}
		} else {
			/invoke ${out[good, HealerMercCount]}
		}

	| MeleeMercCount
		/if (!${Range.Between[0,3:${Group.MeleeMercCount}]}) {
			/invoke ${out[bad, MeleeMercCount, int, ${Group.MeleeMercCount}]}
		} else {
			/invoke ${out[good, MeleeMercCount]}
		}

	| AvgHPs
		/if (!${Range.Between[1,100:${Group.AvgHPs}]}) {
			/invoke ${out[bad, AvgHPs, int, ${Group.AvgHPs}]}
		} else {
			/invoke ${out[good, AvgHPs]}
		}

	| Injured
		/invoke ${out[skip, Injured[##], int, ${Group.Injured}]}
		OUT ....(\a-not testable outside a combat environment\ax)

	| XCleric (Cleric)
		/if (${Select[${Group.Cleric},NULL]}) {
			/invoke ${out[inc, Cleric, string, ${Group.Cleric}]}
			OUT ....(\a-tNo cleric in group, or this is broke\ax)
		} else {
			/invoke ${out[good, Cleric]}
		}

	| MouseOver
		| what the fuck?



/return




sub start_MQ2GroupMemberType()
	/echo
	OUT Testing::\awMQ2GroupMemberType\ax (\a-tGroup.Member[].\ax)
	LOG
	LOG Testing::MQ2GroupMemberType






| Name
| Leader
| Spawn
| Level
| MainTank
| MainAssist
| MarkNpc
| MasterLooter
| Puller
| Mercenary
| Type
| PctAggro
| xIndex
| Offline
| Present
| OtherZone




/return
