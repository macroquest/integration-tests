|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2FloatType
 *
 ***|





sub start_MQ2FloatType()
	/echo
	OUT Testing::\awMQ2FloatType\ax (\a-tFloat.\ax)
	LOG
	LOG Testing::MQ2FloatType

	/declare pi string local 3.1415926535

	OUT ..Test String \at${pi}\ax

	| Int
		/if (${Float[${pi}].Int} != 3) {
			/invoke ${out[bad, Int, int, ${Float[${pi}].Int}]}
		} else {
			/invoke ${out[good, Int]}
		}

	| Deci
		/if (${Float[${pi}].Deci} != 3.1) {
			/invoke ${out[bad, Deci, int, ${Float[${pi}].Deci}]}
		} else {
			/invoke ${out[good, Deci]}
		}

	| Centi
		/if (${Float[${pi}].Centi} != 3.14) {
			/invoke ${out[bad, Centi, int, ${Float[${pi}].Centi}]}
		} else {
			/invoke ${out[good, Centi]}
		}

	| Milli
		/if (${Float[${pi}].Milli} != 3.142) {
			/invoke ${out[bad, Milli, int, ${Float[${pi}].Milli}]}
		} else {
			/invoke ${out[good, Milli]}
		}

	| Precision
		/if (${Float[${pi}].Precision[5]} != 3.14159) {
			/invoke ${out[bad, Precision[5], int, ${Float[${pi}].Precision[5]}]}
		} else {
			/invoke ${out[good, Precision[5]]}
		}

	| Raw
		/if (${Float[${pi}].Raw} != 1078530010) {
			/invoke ${out[bad, Raw, int, ${Float[${pi}].Raw}]}
		} else {
			/invoke ${out[good, Raw]}
		}

	| clear variable
	/deletevar pi


/return

