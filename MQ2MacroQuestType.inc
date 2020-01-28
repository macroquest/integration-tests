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



| Error

| SyntaxError

| MQ2DataError

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

| Path

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



/return






${MacroQuest.Error}
${MacroQuest.SyntaxError}
${MacroQuest.MQ2DataError}
${MacroQuest.Path}






