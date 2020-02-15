|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2DoubleType
 *
 ***|





sub start_MQ2DoubleType()
	/echo
	OUT Testing::\awMQ2DoubleType\ax (\a-tDouble.\ax)
	LOG
	LOG Testing::MQ2DoubleType

	/declare pi string local 3.1415926535

	OUT ..Test String \at${pi}\ax

	| Int
		/invoke ${out[echo, Int, int, ${Double[${pi}].Int}]}

	| Deci
		/invoke ${out[echo, Deci, int, ${Double[${pi}].Deci}]}

	| Centi
		/invoke ${out[echo, Centi, int, ${Double[${pi}].Centi}]}

	| Milli
		/invoke ${out[echo, Milli, int, ${Double[${pi}].Milli}]}

	| Precision
		/invoke ${out[echo, Precision[5], int, ${Double[${pi}].Precision[5]}]}


	| clear variable
	/deletevar pi


/return





