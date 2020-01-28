|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2TimeType
 *
 ***|






sub start_MQ2TimeType()
	/echo
	OUT Testing::\awMQ2TimeType\ax (\a-tTime.\ax)
	LOG
	LOG Testing::MQ2TimeType



	| Hour (24 hour)
		/if (!${Range.Between[0,24:${Time.Hour}]}) {
			/invoke ${out[bad, Hour, int, ${Time.Hour}]}
		} else {
			/invoke ${out[good, Hour]}
		}

	| Hour12
		/if (!${Range.Between[1,12:${Time.Hour12}]}) {
			/invoke ${out[bad, Hour12, int, ${Time.Hour12}]}
		} else {
			/invoke ${out[good, Hour12]}
		}

	| Minute
		/if (!${Range.Between[1,60:${Time.Minute}]}) {
			/invoke ${out[bad, Minute, int, ${Time.Minute}]}
		} else {
			/invoke ${out[good, Minute]}
		}

	| Second
		/if (!${Range.Between[1,60:${Time.Second}]}) {
			/invoke ${out[bad, Second, int, ${Time.Second}]}
		} else {
			/invoke ${out[good, Second]}
		}

	| DayOfWeek
		/if (!${Range.Between[1,7:${Time.DayOfWeek}]}) {
			/invoke ${out[bad, DayOfWeek, int, ${Time.DayOfWeek}]}
		} else {
			/invoke ${out[good, DayOfWeek]}
		}

	| Day
		/if (!${Range.Between[1,32:${Time.Day}]}) {
			/invoke ${out[bad, Day, int, ${Time.Day}]}
		} else {
			/invoke ${out[good, Day]}
		}

	| Month
		/if (!${Range.Between[1,12:${Time.Month}]}) {
			/invoke ${out[bad, Month, int, ${Time.Month}]}
		} else {
			/invoke ${out[good, Month]}
		}

	| Year
		/if (!${Range.Between[2020,2030:${Time.Year}]}) {
			/invoke ${out[bad, Year, int, ${Time.Year}]}
		} else {
			/invoke ${out[good, Year]}
		}

	| Time12
		/invoke ${out[skip, Time12, string, ${Time.Time12}]}
		OUT ....(\a-tlook at a clock\ax::\a-w${Time.Time12}\ax)

	| Time24
		/invoke ${out[skip, Time24, string, ${Time.Time24}]}
		OUT ....(\a-tlook at a clock\ax::\a-w${Time.Time24}\ax)

	| Date
		/invoke ${out[skip, Date, string, ${Time.Date}]}
		OUT ....(\a-tlook at a calendar\ax::\a-w${Time.Date}\ax)


	| Night
		| /if (!${Range.Between[2020,2030:${Time.Night}]}) {
		| 	/invoke ${out[bad, Night, bool, ${Time.Night}]}
		| } else {
		| 	/invoke ${out[good, Night]}
		| }


	| SecondsSinceMidnight
		/if (!${Range.Between[1,86399:${Time.SecondsSinceMidnight}]}) {
			/invoke ${out[bad, SecondsSinceMidnight, int, ${Time.SecondsSinceMidnight}]}
		} else {
			/invoke ${out[good, SecondsSinceMidnight]}
		}

/return




