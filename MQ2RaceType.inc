|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2CharacterType
 *
 ***|






sub start_MQ2RaceType()
	/echo
	OUT Testing::\awMQ2RaceType\ax (\a-tMe.Race.\ax)
	LOG
	LOG Testing::MQ2RaceType

	/declare raceName string local Barbarian|Dark Elf|Drakkin|Dwarf|Erudite|Froglok|Gnome|Half-Elf|Halfling|High Elf|Human|Iksar|Ogre|Troll|Vah Shir|Wood Elf


	| ID
		/if (!${Range.Between[1,396:${Me.Race.ID}]}) {
			/invoke ${out[bad, ID, int, ${Me.Race.ID}]}
		} else {
			/invoke ${out[good, ID]}
		}

	| Name
		/if (!${raceName.Find[${Me.Race.Name}]}) {
			/invoke ${out[bad, Name, string, ${Me.Race.Name}]}
		} else {
			/invoke ${out[good, Name]}
		}


/return


