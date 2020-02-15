|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2StringType
 *
 ***|






sub start_MQ2StringType()
	/echo
	OUT Testing::\awMQ2StringType\ax (\a-tstring?!?\ax)
	LOG
	LOG Testing::MQ2StringType

	| Length
		/if (${myString.Length} != 16) {
			/invoke ${out[bad, Length, int, ${myString.Length}]}
		} else {
			/invoke ${out[good, Length]}
		}

	| Equal
		/if (${myString.Equal[MyStringMYSTRING]}) {
			/invoke ${out[good, Equal]}
		} else {
			/invoke ${out[bad, Equal, bool, ${myString.Equal[MyStringMYSTRING]}]}
		}

	| EqualCS
		/if (${myString.EqualCS[MyStringMYSTRING]}) {
			/invoke ${out[good, EqualCS]}
		} else {
			/invoke ${out[bad, EqualCS, bool, ${myString.Equal[MyStringMYSTRING]}]}
		}

	| NotEqual
		/if (${myString.NotEqual[MyStringMYSTRING]}) {
			/invoke ${out[bad, NotEqual, bool, ${myString.NotEqual[MyStringMYSTRING]}]}
		} else {
			/invoke ${out[good, NotEqual]}
		}

	| NotEqualCS
		/if (${myString.NotEqualCS[MyStringMYSTRING]}) {
			/invoke ${out[bad, NotEqualCS, bool, ${myString.NotEqualCS[MyStringMYSTRING]}]}
		} else {
			/invoke ${out[good, NotEqualCS]}
		}

	| Count
		/if (${myString.Count[t]} != 1) {
			/invoke ${out[bad, Count, int, ${myString.Count[t]}]}
		} else {
			/invoke ${out[good, Count]}
		}

	| Upper
		/invoke ${out[echo, Upper, string, ${myString.Upper}]}

	| Lower
		/invoke ${out[echo, Lower, string, ${myString.Lower}]}

	| Left
		/if (${myString.Left[2].NotEqual[My]}) {
			/invoke ${out[bad, Left, string, ${myString.Left[2]}]}
		} else {
			/invoke ${out[good, Left]}
		}

	| Right
		/if (${myString.Right[2].NotEqual[NG]}) {
			/invoke ${out[bad, Right, string, ${myString.Right[2]}]}
		} else {
			/invoke ${out[good, Right]}
		}

	| Replace
		/invoke ${out[echo, Replace, string, ${myString.Replace[String,Line]}]}

	| Mid
		/if (${myString.Mid[3,6].NotEqual[string]}) {
			/invoke ${out[bad, Mid, string, ${myString.Mid[3,6]}]}
		} else {
			/invoke ${out[good, Mid]}
		}

	| Compare
		/if (${myString.Compare[MyStringMYSTRING]}) {
			/invoke ${out[bad, Compare, int, ${myString.Compare[MyStringMYSTRING]}]}
		} else {
			/invoke ${out[good, Compare]}
		}

	| CompareCS
		/if (${myString.CompareCS[MyStringMYSTRING]}) {
			/invoke ${out[bad, CompareCS, int, ${myString.CompareCS[MyStringMYSTRING]}]}
		} else {
			/invoke ${out[good, CompareCS]}
		}

	| Find
		/if (${myString.Find[String]} != 3) {
			/invoke ${out[bad, Find, int, ${myString.Find[String]}]}
		} else {
			/invoke ${out[good, Find]}
		}

	| Arg
		/if (${myString.Arg[1,S].NotEqual[My]}) {
			/invoke ${out[bad, Arg, string, ${myString.Arg[1,S]}]}
		} else {
			/invoke ${out[good, Arg]}
		}

	| Token
		/if (${myString.Token[1,S].NotEqual[My]}) {
			/invoke ${out[bad, Token, string, ${myString.Token[1,S]}]}
		} else {
			/invoke ${out[good, Token]}
		}


/return



