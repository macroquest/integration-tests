|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2WorldLocationType
 *
 ***|






sub start_MQ2WorldLocationType()
	/echo
	OUT Testing::\awMQ2WorldLocationType\ax (\a-tMe.Zone. / Zone.\ax)
	LOG
	LOG Testing::MQ2WorldLocationType


	| this is causing a ctd. cannot test right now.
/return



	| Zone.ID
		/if (!${Range.Between[0,999999:${Zone.ID}]}) {
			/invoke ${out[skip, ID, int, ${Zone.ID}]}
		} else {
			/invoke ${out[good, ID]}
		}

	| Zone
		/if (${Zone.Length} <= 4) {
			/invoke ${out[skip, Zone, string, ${Zone}]}
		} else {
			/invoke ${out[good, Zone]}
		}

	| Y

	| X

	| Z

	| Heading




/return


${Zone}