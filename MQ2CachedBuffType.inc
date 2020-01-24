|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2CachedBuffType
 *
 ***|

| NOTES
| we will work with the second member of the group. Group.Member[1]
| we will work with the first indexed spell in the cachedbuff list *1
| if there is not a group, or the group member has no buffs, this test will be skipped



sub start_MQ2CachedBuffType()
	/echo
	OUT Testing::\awMQ2CachedBuffType\ax (\a-tGroup.Member.\ax)
	LOG
	LOG Testing::MQ2CachedBuffType


	| make sure we are in a group. if we are not. we skip this entire section of testing
		/if (!${Range.Between[1,5:${Group}]}) {
			/invoke ${out[skip, Group.]}
			OUT ....(\a-tMUST BE IN A GROUP\ax)
			/return FALSE
		}


	| target group member 1 to get the buffs cached
		/target id ${Group.Member[1].ID}
		/delay 2s ${Target.ID} == ${Group.Member[1].ID}

	| delay 1 second. i really have no idea how fast this thing works
		/delay 1s

	| clear target
		/squelch /target clear
		/delay 5

	| start checking the TLO
	| make sure the target has buffs to check
	| CachedBuffCount
		/if (!${Group.Member[1].CachedBuffCount}) {
			/invoke ${out[bad, CachedBuffCount, int, ${Group.Member[1].CachedBuffCount}]}
			OUT ....(\a-tGroup member 1 has no buffs. Skipping Remaining Tests\ax)
			/return FALSE
		} else {
			/invoke ${out[good, CachedBuffCount]}
		}

	| CasterName
		/if (!${Bool[${Group.Member[1].CachedBuff[*1].CasterName}]}) {
			/invoke ${out[inc, CasterName, string, ${Group.Member[1].CachedBuff[*1].CasterName}]}
			OUT ....(\a-tbuff *1 does not have a castername, manual validation required\ax)
			/return FALSE
		} else {
			/invoke ${out[good, CasterName]}
		}

| Count
| ${Group.Member[1].CachedBuff[*1].Count} ?????

	| Slot
		/if (!${Range.Between[1,72:${Group.Member[1].CachedBuff[*1].Slot}]}) {
			/invoke ${out[bad, Slot, int, ${${Group.Member[1].CachedBuff[*1].Slot}}]}
		} else {
			/invoke ${out[good, Slot]}
		}

	| SpellID
		/if (!${Bool[${Group.Member[1].CachedBuff[*1].SpellID}]}) {
			/invoke ${out[bad, SpellID, int, ${${Group.Member[1].CachedBuff[*1].SpellID}}]}
		} else {
			/invoke ${out[good, SpellID]}
		}

	| Duration
		/if (!${Bool[${Group.Member[1].CachedBuff[*1].Duration}]} && ${Group.Member[1].CachedBuff[*1].Duration} != -1) {
			/invoke ${out[bad, Duration, int, ${Group.Member[1].CachedBuff[*1].Duration}]}
		} else /if (${Group.Member[1].CachedBuff[*1].Duration} == -1) {
			/invoke ${out[inc, Duration, int>0, ${Group.Member[1].CachedBuff[*1].Duration}]}
			OUT ....(\a-tpermanent buff, duration of -1\ax)
		} else {
			/invoke ${out[good, Duration]}
		}


/return

