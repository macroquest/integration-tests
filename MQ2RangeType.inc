|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2RangeType
 *
 ***|





sub start_MQ2RangeType()
	/echo
	OUT Testing::\awMQ2RangeType\ax (\a-tRange.\ax)
	LOG
	LOG Testing::MQ2RangeType



	| Inside (high,low:# not inclusive of high/low)
		/if (!${Range.Inside[1,50:41]}) {
			/invoke ${out[bad, Inside, bool, ${Range.Inside[1,50:41]}]}
		} else {
			/invoke ${out[good, Inside]}
		}

	| Between (high,low,# inclusive of high/low)
		/if (!${Range.Between[1,50:41]}) {
			/invoke ${out[bad, Between, bool, ${Range.Between[1,50:41]}]}
		} else {
			/invoke ${out[good, Between]}
		}


/return


