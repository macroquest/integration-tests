|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2TargetBuffType
 *
 ***|






sub start_MQ2TargetBuffType()
	/echo
	OUT Testing::\awMQ2TargetBuffType\ax (\a-tTarget.Buff.\ax)
	LOG
	LOG Testing::MQ2TargetBuffType

	| we need a target to check for buffs
	/target id ${Me.ID}
	/delay 5

	/delay 5s ${Target.ID} == ${Me.ID}

	/declare x int local 0
	/declare foundBuff int local 0


	| find us a buff to test with
	/for x 1 to 42
		/if (${Bool[${Target.Buff[${x}]}]}) {
			/varset foundBuff ${x}
			/break
		}
	/next x

	| did we find something?
		/if (!${foundBuff}) {
			/invoke ${out[skip, Target.Buff]}
			OUT ....(\a-tYou have no buffs. skipping these tests\ax)
			/return FALSE
		}

	| Duration
		/if (${Target.Buff[${foundBuff}].Duration} == -1) {
			OUT ..Duration on ${Target.Buff[${foundBuff}]}:\a-wPermanent\ax
		} else /if (${Target.Buff[${foundBuff}].Duration} > 0) {
			OUT ..Duration on ${Target.Buff[${foundBuff}]}:\a-w${Target.Buff[${foundBuff}].Duration}\ax
		}
		OUT




| xIndex

	/squelch /target clear
	/delay 5

/return

