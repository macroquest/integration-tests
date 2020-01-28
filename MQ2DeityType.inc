|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2TargetBuffType
 *
 ***|






sub start_MQ2DeityType()
	/echo
	OUT Testing::\awMQ2DeityType\ax (\a-tMe.Deity.\ax)
	LOG
	LOG Testing::MQ2DeityType

	/declare deityName string local Agnostic|Veeshan|Tunare|The Tribunal|Solusek Ro|Rodcet Nife|Rallos Zek|Quellious|Quellious|Prexus|Mithaniel Marr|Karana|Innoruuk|Erolissi Marr|Cazic-Thule|Bristlebane|Brell Serilis|Bertoxxulous
	/declare deityTeam string local good|none|evil


	| ID
		/if (!${Range.Between[1,396:${Me.Deity.ID}]}) {
			/invoke ${out[bad, ID, int, ${Me.Deity.ID}]}
		} else {
			/invoke ${out[good, ID]}
		}

	| Name
		/if (!${deityName.Find[${Me.Deity.Name}]}) {
			/invoke ${out[bad, Name, string, ${Me.Deity.Name}]}
		} else {
			/invoke ${out[good, Name]}
		}

	| Team
		/if (!${deityTeam.Find[${Me.Deity.Team}]}) {
			/invoke ${out[bad, Team, string, ${Me.Deity.Team}]}
		} else {
			/invoke ${out[good, Team]}
		}


/return







${Me.Deity.ID}
${Me.Deity.Team}
${Me.Deity.Name}





