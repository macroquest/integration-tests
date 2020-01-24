|***
 * TestSuite.mac
 * MQ2FellowshipType.cpp
 * testing MQ2FellowshipType
 *
 ***|





sub start_MQ2FellowshipType()
	/echo
	OUT Testing::\awMQ2FellowshipType\ax (\a-tMe.Fellowship.\ax)
	LOG
	LOG Testing::MQ2FellowshipType

	| make sure we are a member of a fellowship. if we are not. we skip this entire section of testing
		/if (!${Range.Between[1,99999999999:${Me.Fellowship.ID}]}) {
			/invoke ${out[skip, NA, int > 0, ${Me.Fellowship.ID}]}
			OUT ...(\a-tNOT PART OF A FELLOWSHIP\ax)
			/return FALSE
		}

	| Leader
		/if (!${Bool[${Me.Fellowship.Leader}]}) {
			/invoke ${out[bad, Leader, string, ${Me.Fellowship.Leader}]}
		} else {
			/invoke ${out[good, Leader]}
		}

	| MotD
		/if (!${Bool[${Me.Fellowship.MotD}]}) {
			/invoke ${out[inc, MotD, string, ${Me.Fellowship.MotD}]}
			OUT ....(\a-tNo fellowship MoTD set, or this is broke\ax)
		} else {
			/invoke ${out[good, MotD]}
		}


	| Members
		/if (!${Range.Between[2,12:${Me.Fellowship.Members}]}) {
			/invoke ${out[bad, Members, int, ${Me.Fellowship.Members}]}
		} else {
			/invoke ${out[good, Members]}
		}


	| xMember
	| Me.Fellowship.Member[].??
	| lots oft hings to test with. we will use zone id as something simple
		/if (${Me.Fellowship.Member[${Me.Name}].Zone.ID} != ${Zone.ID}) {
			/invoke ${out[bad, Member, int, ${Me.Fellowship.Member[${Me.Name}].Zone.ID}]}
		} else {
			/invoke ${out[good, Member]}
		}


	| CampfireDuration
		/if (!${Range.Between[0,3600:${Me.Fellowship.CampfireDuration}]}) {
			/invoke ${out[bad, CampfireDuration, int, ${Me.Fellowship.CampfireDuration}]}
		} else {
			/invoke ${out[good, CampfireDuration]}
		}

	| CampfireY
		/if (!${Range.Between[-12999,12999:${Me.Fellowship.CampfireY}]}) {
			/invoke ${out[bad, CampfireY, int, ${Me.Fellowship.CampfireY}]}
		} else {
			/invoke ${out[good, CampfireY]}
		}

	| CampfireX
		/if (!${Range.Between[-12999,12999:${Me.Fellowship.CampfireX}]}) {
			/invoke ${out[bad, CampfireX, int, ${Me.Fellowship.CampfireX}]}
		} else {
			/invoke ${out[good, CampfireX]}
		}

	| CampfireZ
		/if (!${Range.Between[-12999,12999:${Me.Fellowship.CampfireZ}]}) {
			/invoke ${out[bad, CampfireZ, int, ${Me.Fellowship.CampfireZ}]}
		} else {
			/invoke ${out[good, CampfireZ]}
		}

	| CampfireZone
		/if (${Select[${Me.Fellowship.CampfireZone},NULL]}) {
			/invoke ${out[inc, CampfireZone, string, ${Me.Fellowship.CampfireZone}]}
			OUT ....(\a-tNo fellowship campfire set, or this is broke\ax)
		} else {
			/invoke ${out[good, CampfireZone]}
		}

	| Campfire
		/if (${Select[${Me.Fellowship.Campfire},FALSE]}) {
			/invoke ${out[inc, Campfire, string, ${Me.Fellowship.Campfire}]}
			OUT ....(\a-tNo fellowship campfire set, or this is broke\ax)
		} else {
			/invoke ${out[good, Campfire]}
		}


	| Me.Fellowship.Member[].??| Zone
		/if (${Me.Fellowship.Member[${Me.Name}].Zone.Name.NotEqual[${Zone.Name}]}) {
			/invoke ${out[bad, Zone, string, ${Me.Fellowship.Member[${Me.Name}].Zone}]}
		} else {
			/invoke ${out[good, Zone]}
		}

	| Level
		/if (${Me.Fellowship.Member[${Me.Name}].Level} != ${Me.Level}) {
			/invoke ${out[bad, Level, string, ${Me.Fellowship.Member[${Me.Name}].Level}]}
		} else {
			/invoke ${out[good, Level]}
		}

	| Class
		/if (${Me.Fellowship.Member[${Me.Name}].Class.Name.NotEqual[${Me.Class}]}) {
			/invoke ${out[bad, Class, string, ${Me.Fellowship.Member[${Me.Name}].Class}]}
		} else {
			/invoke ${out[good, Class]}
		}

	| LastOn
		/invoke ${out[skip, LastOn, string, ${Me.Fellowship.Member[${Me.Name}].LastOn}]}
		OUT ....(\a-tthis is fucking useless\ax)

	| Name
		/if (${Me.Fellowship.Member[${Me.Name}].Name.NotEqual[${Me.Name}]}) {
			/invoke ${out[bad, Name, string, ${Me.Fellowship.Member[${Me.Name}].Name}]}
		} else {
			/invoke ${out[good, Name]}
		}

/return
