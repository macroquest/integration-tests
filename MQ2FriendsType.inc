|***
 * TestSuite.mac
 * MQ2RaidType.cpp
 * testing MQ2RaidType
 *
 ***|



sub start_MQ2FriendsType()
	/echo
	OUT Testing::\awMQ2FriendsType\ax (\a-tFriends.\ax)
	LOG
	LOG Testing::MQ2FriendsType

	| Friend[#]
		| do i have friends?
		/if (!${Bool[${Friends.Friend[1]}]}) {
			/invoke ${out[skip, Friend}
			OUT ...(\a-tTESTING REQUIRES FRIENDS\ax)
			OUT ...(\a-ti don't think this test script can help you there\ax)
			/return FALSE
		} else {
			/invoke ${out[good, Friend[#]]}
		}

	| Friend[name]
		/if (!${Bool[${Friends.Friend[${Friends.Friend[1]}]}]}) {
			/invoke ${out[bad, Friend[name], string, ${Friends.Friend[${Friends.Friend[1]}]}]}
		} else {
			/invoke ${out[good, Friend[name]]}
		}

/return





