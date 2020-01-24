|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2BandolierType
 *
 ***|






sub start_MQ2BandolierType()
	/echo
	OUT Testing::\awMQ2BandolierType\ax (\a-tMe.Bandolier.\ax)
	LOG
	LOG Testing::MQ2BandolierType


	| Index
		/if (!${Me.Bandolier[test1].Index}) {
			OUT ....(\a-tRequired to test. 1 bandolier named: \a-wtest1\ax)
			OUT ....(\a-tput something in each slot for the test\ax)
			/delay 2s
			/return
		} else /if (${Me.Bandolier[test1].Index}) {
			/declare _index int local ${Me.Bandolier[test1].Index}
		}

	| Activate
		/invoke ${Me.Bandolier[test1].Activate}

	| active
		/if (!${Me.Bandolier[test1].Active}) {
			/invoke ${out[bad, Active, bool, ${Me.Bandolier[test1].Active}]}
		} else {
			/invoke ${out[good, Active]}
		}

	| Name
		/if (!${Me.Bandolier[${_index}].Name.Equal[test1]}) {
			/invoke ${out[bad, Name, bool, ${Me.Bandolier[12].Name.Equal[test1]}]}
		} else {
			/invoke ${out[good, Name]}
		}

	| Item[1]
		/if (!${Bool[${Me.Bandolier[${_index}].Item[1]}]}) {
			/invoke ${out[bad, Item[1], string, ${Me.Bandolier[${_index}].Item[1]}]}
		} else {
			/invoke ${out[good, Item[1]]}
		}

	| Item[2]
		/if (!${Bool[${Me.Bandolier[${_index}].Item[2]}]}) {
			/invoke ${out[bad, Item[2], string, ${Me.Bandolier[${_index}].Item[2]}]}
		} else {
			/invoke ${out[good, Item[2]]}
		}

	| Item[3]
		/if (!${Bool[${Me.Bandolier[${_index}].Item[3]}]}) {
			/invoke ${out[bad, Item[3], string, ${Me.Bandolier[${_index}].Item[3]}]}
		} else {
			/invoke ${out[good, Item[3]]}
		}

	| Item[4]
		/if (!${Bool[${Me.Bandolier[${_index}].Item[4]}]}) {
			/invoke ${out[bad, Item[3], string, ${Me.Bandolier[${_index}].Item[4]}]}
		} else {
			/invoke ${out[good, Item[3]]}
		}

/return


