|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2CharacterType
 *
 ***|






sub start_MQ2MacroQuestType()
	/echo
	OUT Testing::\awMQ2MacroQuestType\ax (\a-tMacroQuest.\ax)
	LOG
	LOG Testing::MQ2MacroQuestType


	| BuildDate
		/if (!${Bool[${MacroQuest.BuildDate}]}) {
			/invoke ${out[bad, BuildDate, string, ${MacroQuest.BuildDate}]}
		} else {
			/invoke ${out[good, BuildDate]}
		}

	| Build
		/if (!${Bool[${MacroQuest.Build}]}) {
			/invoke ${out[bad, Build, string, ${MacroQuest.Build}]}
		} else {
			/invoke ${out[good, Build]}
		}

	| Path[]
	| Note. the echos on these are not escaped and will report funckaliscious characters. this is expected behavior.

	| null
		/invoke ${out[echo, null, string, ${MacroQuest.Path}]}
	| root
		/invoke ${out[echo, root, string, ${MacroQuest.Path[root]}]}
	| config
		/invoke ${out[echo, config, string, ${MacroQuest.Path[config]}]}
	| crashdumps
		/invoke ${out[echo, crashdumps, string, ${MacroQuest.Path[crashdumps]}]}
	| logs
		/invoke ${out[echo, logs, string, ${MacroQuest.Path[logs]}]}
	| mqini
		/invoke ${out[echo, mqini, string, ${MacroQuest.Path[mqini]}]}
	| macros
		/invoke ${out[echo, macros, string, ${MacroQuest.Path[macros]}]}
	| plugins
		/invoke ${out[echo, plugins, string, ${MacroQuest.Path[plugins]}]}
	| resources
		/invoke ${out[echo, resources, string, ${MacroQuest.Path[resources]}]}

	| Version
		/if (!${Bool[${MacroQuest.Version}]}) {
			/invoke ${out[bad, Version, string, ${MacroQuest.Version}]}
		} else {
			/invoke ${out[good, Version]}
		}

	| InternalName
		/if (!${Select[${MacroQuest.InternalName},Core]}) {
			/invoke ${out[bad, InternalName, "string (Core)", ${MacroQuest.InternalName}]}
		} else {
			/invoke ${out[good, InternalName]}
		}

	| Parser
		/if (!${Range.Between[1,2:${MacroQuest.Parser}]}) {
			/invoke ${out[bad, Parser, int, ${MacroQuest.Parser}]}
		} else {
			/invoke ${out[good, Parser]}
		}

	| Error
		/invoke ${out[skip, Error, ${MacroQuest.Error}]}
		OUT ...(\a-tSkipping cannot force Error with #warning in use.\ax)

	| SyntaxError
		/invoke ${out[skip, SyntaxError, ${MacroQuest.SyntaxError}]}
		OUT ...(\a-tSkipping cannot force SyntaxError with #warning in use.\ax)

	| MQ2DataError
		/invoke ${out[skip, MQ2DataError, ${MacroQuest.MQ2DataError}]}
		OUT ...(\a-tSkipping cannot force MQ2DataError with #warning in use.\ax)


/return


