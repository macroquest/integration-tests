|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2ClassType
 *
 ***|






sub start_MQ2ClassType()
	/echo
	OUT Testing::\awMQ2ClassType\ax (\a-tMe.Class.\ax)
	LOG
	LOG Testing::MQ2ClassType




	| ID
		/if (!${Range.Between[1,16:${Me.Class.ID}]}) {
			/invoke ${out[bad, ID, int, ${Me.Class.ID}]}
		} else {
			/invoke ${out[good, ID]}
		}

	| Name
		/declare _clsname string local Berzerker,Bard,Beastlord,Cleric,Druid,Enchanter,Magician,Monk,Necromancer,Paladin,Ranger,Rogue,Shadowknight,Shaman,Warrior,Wizard
		/if (!${_clsname.Find[${Me.Class.Name}]}) {
			/invoke ${out[bad, Name, int, ${Me.Class.Name}]}
		} else {
			/invoke ${out[good, Name]}
		}


	| ShortName
		/declare _clsShortName string local BER,BRD,BST,CLR,DRU,ENC,MAG,MON,NEC,PAL,RNG,SHD,SHM,WAR,WIZ
		/if (!${_clsShortName.Find[${Me.Class.ShortName}]}) {
			/invoke ${out[bad, ShortName, int, ${Me.Class.ShortName}]}
		} else {
			/invoke ${out[good, ShortName]}
		}

	| CanCast
		/if (!${Me.Class.CanCast}) {
			/invoke ${out[inc, CanCast, bool, ${Me.Class.CanCast}]}
			OUT ....(\a-ttest with a CanCast class\ax)
		} else {
			/invoke ${out[good, CanCast]}
		}

	| PureCaster
		/if (!${Me.Class.PureCaster}) {
			/invoke ${out[inc, PureCaster, bool, ${Me.Class.PureCaster}]}
			OUT ....(\a-ttest with a PureCaster class\ax)
		} else {
			/invoke ${out[good, PureCaster]}
		}

	| PetClasss
		/if (!${Me.Class.PetClass}) {
			/invoke ${out[inc, PetClasss, bool, ${Me.Class.PetClass}]}
			OUT ....(\a-ttest with a PetClass class\ax)
		} else {
			/invoke ${out[good, PetClass]}
		}

	| DruidType
		/if (!${Me.Class.DruidType}) {
			/invoke ${out[inc, ClericType, bool, ${Me.Class.DruidType}]}
			OUT ....(\a-ttest with a DruidType class\ax)
		} else {
			/invoke ${out[good, DruidType]}
		}

	| ShamanType
		/if (!${Me.Class.ShamanType}) {
			/invoke ${out[inc, ShamanType, bool, ${Me.Class.ShamanType}]}
			OUT ....(\a-ttest with a ShamanType class\ax)
		} else {
			/invoke ${out[good, ShamanType]}
		}

	| NecromancerType
		/if (!${Me.Class.NecromancerType}) {
			/invoke ${out[inc, NecromancerType, bool, ${Me.Class.NecromancerType}]}
			OUT ....(\a-ttest with a NecromancerType class\ax)
		} else {
			/invoke ${out[good, NecromancerType]}
		}

	| ClericType
		/if (!${Me.Class.ClericType}) {
			/invoke ${out[inc, ClericType, bool, ${Me.Class.ClericType}]}
			OUT ....(\a-ttest with a class\ax)
		} else {
			/invoke ${out[good, ClericType]}
		}


	| HealerType
		/if (!${Me.Class.HealerType}) {
			/invoke ${out[inc, HealerType, bool, ${Me.Class.HealerType}]}
			OUT ....(\a-ttest with a HealerType class\ax)
		} else {
			/invoke ${out[good, HealerType]}
		}

	| MercType
		/invoke ${out[skip, MercType, bool, NA]}
		OUT ....(\a-twill be tested under spawn\ax)



/return
