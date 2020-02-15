|***
 * TestSuite.mac
 * MQ2RaidType.cpp
 * testing MQ2ArrayType
 *
 ***|



sub start_MQ2ArrayType()
	/echo
	OUT Testing::\awMQ2ArrayType\ax (\a-tarray!?.\ax)
	LOG
	LOG Testing::MQ2ArrayType

	OUT ..Using \atTLO\ax Array

	| Dimensions
		/if (!${Range.Between[0,100:${TLO.Dimensions}]}) {
			/invoke ${out[bad, Dimensions, int, ${TLO.Dimensions}]}
		} else {
			/invoke ${out[good, Dimensions]}
		}

	| Size
		/if (!${Range.Between[0,100:${TLO.Size}]}) {
			/invoke ${out[bad, Size, int, ${TLO.Size}]}
		} else {
			/invoke ${out[good, Size]}
		}

/return


