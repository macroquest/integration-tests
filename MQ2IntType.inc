|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2IntType
 *
 ***|





sub start_MQ2IntType()
	/echo
	OUT Testing::\awMQ2IntType\ax (\a-tInt.\ax)
	LOG
	LOG Testing::MQ2IntType

	/declare pi string local 3.1415926535

	OUT ..Test String \at${pi}\ax

	| Float
		/if (${Int[${pi}].Float} != 3.00) {
			/invoke ${out[bad, Float, int, ${Int[${pi}].Float}]}
		} else {
			/invoke ${out[good, Float]}
		}

	| Double
		/if (${Int[${pi}].Double} != 3.00) {
			/invoke ${out[bad, Double, int, ${Int[${pi}].Double}]}
		} else {
			/invoke ${out[good, Double]}
		}

	| Hex
		/if (${Int[${pi}].Hex.NotEqual[0x3]}) {
			/invoke ${out[bad, Hex, int, ${Int[${pi}].Hex}]}
		} else {
			/invoke ${out[good, Hex]}
		}

	| Reverse
		/if (${Int[${pi}].Reverse} != 50331648) {
			/invoke ${out[bad, Reverse, int, ${Int[${pi}].Reverse}]}
		} else {
			/invoke ${out[good, Reverse]}
		}

	| LowPart
		/if (${Int[${pi}].LowPart} != 3) {
			/invoke ${out[bad, LowPart, int, ${Int[${pi}].LowPart}]}
		} else {
			/invoke ${out[good, LowPart]}
		}

	| HighPart
		/if (${Int[${pi}].HighPart} != 0) {
			/invoke ${out[bad, HighPart, int, ${Int[${pi}].HighPart}]}
		} else {
			/invoke ${out[good, HighPart]}
		}

	| clear variable
	/deletevar pi


/return


