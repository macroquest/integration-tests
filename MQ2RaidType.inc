|***
 * TestSuite.mac
 * MQ2RaidType.cpp
 * testing MQ2RaidType
 *
 ***|



sub start_MQ2RaidType()
	/echo
	OUT Testing::\awMQ2RaidType\ax (\a-tRaid.\ax)
	LOG
	LOG Testing::MQ2RaidType

	| Invited
		/if (!${Window[ConfirmationDialogBox].Open}) {
			/invoke ${out[skip, Invited]}
			OUT ...(\a-thave someone invite you to a raid, do not accept and test\ax)
		} else /if (${Window[ConfirmationDialogbox].Child[CD_TextOutPut].Text.Find[invites you to join a raid]}) {
			/invoke ${out[good, Invited]}
			/nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
			/delay 5
		}

	| make sure we are part of a raid. if we are not. we skip this entire section of testing
| | Members
		/if (!${Range.Between[2,72:${Raid.Members}]}) {
			/invoke ${out[skip, Members, ${Raid.Members}]}
			OUT ...(\a-tTESTING REQUIRES RAID MEMBERSHIP\ax)
			OUT ...(\a-t..tester should be raid leader\ax)
			/return FALSE
		} else {
			/invoke ${out[good, Members]}
		}

	| LootType
		/if (!${Range.Between[1,4:${Raid.LootType}]}) {
			/invoke ${out[skip, LootType, int, ${Raid.LootType}]}
		} else {
			/invoke ${out[good, LootType]}
		}

	| Locked
		/if (!${Raid.Locked}) {
			/invoke ${out[skip, Locked]}
			OUT ...(\a-tlock the raid with raid tools and test again\ax)
		} else {
			/invoke ${out[good, Locked]}
		}


| Target


	| Leader
		/if (${Raid.Leader.ID} != ${Me.ID}) {
			/invoke ${out[skip, Leader, string, ${Raid.Leader}]}
		} else {
			/invoke ${out[good, Leader]}
		}

	| TotalLevels
		/if (!${Range.Between[72,${Math.Calc[${maxLevel} * 72]}:${Raid.TotalLevels}]}) {
			/invoke ${out[skip, TotalLevels, int, ${Raid.TotalLevels}]}
		} else {
			/invoke ${out[good, TotalLevels]}
		}

	| AverageLevel
		/if (!${Range.Between[1,${maxLevel}:${Raid.AverageLevel}]}) {
			/invoke ${out[skip, AverageLevel, int, ${Raid.AverageLevel}]}
		} else {
			/invoke ${out[good, AverageLevel]}
		}

| Looters


| Looter


	| MainAssist
		/if (${Raid.MainAssist.ID} != ${Me.ID}) {
			/invoke ${out[skip, MainAssist]}
			OUT ...(\a-tset yourself as MainAssist and test again\ax)
		} else {
			/invoke ${out[good, MainAssist]}
		}

	| MasterLooter
		/if (${Raid.MasterLooter.ID} != ${Me.ID}) {
			/invoke ${out[skip, MasterLooter]}
			OUT ...(\a-tset yourself as MasterLooter and test again\ax)
		} else {
			/invoke ${out[good, MasterLooter]}
		}


	/echo
	OUT Testing::\awMQ2RaidMemberType\ax (\a-tRaid.Member.\ax)
	LOG
	LOG Testing::RaidMemberType

	| xMember
	| Name
		/if (${Raid.Member[${Me.Name}].Name.NotEqual[${Me.Name}]}) {
			/invoke ${out[bad, Name, string, ${Raid.Member[${Me.Name}].Name}]}
		} else {
			/invoke ${out[good, Name]}
		}

	| Group
		/if (!${Range.Between[0,12:${Raid.Member[${Me.Name}].Group}]}) {
			/invoke ${out[bad, Group, int, ${Raid.Member[${Me.Name}].Group}]}
		} else {
			/invoke ${out[good, Group]}
		}

	| GroupLeader
		/if (!${Select[${Raid.Member[${Me.Name}].GroupLeader},TRUE,FALSE]}) {
			/invoke ${out[bad, GroupLeader, bool, ${Raid.Member[${Me.Name}].GroupLeader}]}
		} else {
			/invoke ${out[good, GroupLeader]}
		}

	| RaidLeader
		/if (!${Select[${Raid.Member[${Me.Name}].RaidLeader},TRUE,FALSE]}) {
			/invoke ${out[bad, RaidLeader, bool, ${Raid.Member[${Me.Name}].RaidLeader}]}
		} else {
			/invoke ${out[good, RaidLeader]}
		}

	| Looter
		/if (!${Select[${Raid.Member[${Me.Name}].Looter},TRUE,FALSE]}) {
			/invoke ${out[bad, Looter, bool, ${Raid.Member[${Me.Name}].Looter}]}
		} else {
			/invoke ${out[good, Looter]}
		}

	| Level
		/if (!${Range.Between[1,${maxLevel}:${Raid.Member[${Me.Name}].Level}]}) {
			/invoke ${out[bad, Level, string, ${Raid.Member[${Me.Name}].Level}}]}
		} else {
			/invoke ${out[good, Level]}
		}

	| Class
		/if (${Raid.Member[${Me.Name}].Class.Name.NotEqual[${Me.Class}]}) {
			/invoke ${out[bad, Class, string, ${Raid.Member[${Me.Name}].Class}]}
		} else {
			/invoke ${out[good, Class]}
		}

	| Spawn
		/if (${Raid.Member[${Me.Name}].Spawn.Type.NotEqual[${Me.Class}]}) {
			/invoke ${out[bad, Spawn, string, ${Raid.Member[${Me.Name}].Spawn.Type}]}
		} else {
			/invoke ${out[good, Spawn]}
		}

/return


