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





	| Locked
		/if (!${Raid.Locked}) {
			/invoke ${out[skip, Locked]}
			OUT ...(\a-tlock the raid with raid tools and test again\ax)
		} else {
			/invoke ${out[good, Locked]}
		}


| xMember


| Member


| Target


	| Leader
		/if (${Raid.Leader.ID} != ${Me.ID}) {
			/invoke ${out[skip, Leader, string, ${Raid.Leader}]}
		} else {
			/invoke ${out[good, Leader]}
		}

	| TotalLevels
		/if (!${Range.Between[72,8280:${Raid.TotalLevels}]}) {
			/invoke ${out[skip, TotalLevels, int, ${Raid.TotalLevels}]}
		} else {
			/invoke ${out[good, TotalLevels]}
		}

	| AverageLevel
		/if (!${Range.Between[1,115:${Raid.AverageLevel}]}) {
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









/return



${Raid.TotalLevels}
${Raid.Leader}
${Raid.Member[1]}
${Raid.MainAssist}
${Raid.Invited}
