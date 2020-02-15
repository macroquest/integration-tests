|***
 * TestSuite.mac
 * MQ2RaidType.cpp
 * testing MQ2BodyType
 *
 ***|



sub start_MQ2BodyType()
	/echo
	OUT Testing::\awMQ2BodyType\ax (\a-tTarget.Body\ax)
	LOG
	LOG Testing::MQ2BodyType

	| we use self target for validation
	| body type ID for self (PC) should return 1 and the name is Humanoid

	/target id ${Me.ID}
	/delay 1s


	| ID
		/if (${Target.Body.ID} != 1) {
			/invoke ${out[bad, ID, int, ${Target.Body.ID}]}
		} else {
			/invoke ${out[good, ID]}
		}

	| Name
		/if (${Target.Body.Name.NotEqual[Humanoid]}) {
			/invoke ${out[bad, Name, string, ${Target.Body.Name}]}
		} else {
			/invoke ${out[good, Name]}
		}

	| remove target
	/squelch /target clear
	/delay 1s

/return





