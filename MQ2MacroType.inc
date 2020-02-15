|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2MacroType
 *
 ***|


sub start_MQ2MacroType()
	/echo
	OUT Testing::\awMQ2MacroType\ax (\a-tMacro.\ax)
	LOG
	LOG Testing::MQ2MacroType

	| Macro.Name
		/if (${Macro.Name.NotEqual[testsuite\test.mac]}) {
			/invoke ${out[bad, Name, string, ${Macro.Name}]}
		} else {
			/invoke ${out[good, Name]}
		}

	| Macro.RunTime
		/if (!${Range.Between[0,999999:${Macro.RunTime}]}) {
			/invoke ${out[bad, RunTime, int, ${Macro.RunTime}]}
		} else {
			/invoke ${out[good, RunTime]}
		}

	| Macro.Paused
		/if (${Macro.Paused}) {
			/invoke ${out[bad, Paused]}
		} else {
			/invoke ${out[good, Paused]}
		}

	| Macro.Return
		/call test_return_string
		/if (${Macro.Return.NotEqual[MyStringMYSTRING]}) {
			/invoke ${out[bad, Return, string, ${Macro.Return}]}
		} else {
			/invoke ${out[good, Return]}
		}

	| Macro.IsTLO
		/if (${Macro.IsTLO[Name]}) {
			/invoke ${out[bad, IsTLO, bool, ${Macro.IsTLO[Name]}]}
		} else {
			/invoke ${out[good, IsTLO]}
		}

	| Macro.IsOuterVariable
		/if (!${Macro.IsOuterVariable[myString]}) {
			/invoke ${out[bad, IsOuterVariable, bool, ${Macro.IsOuterVariable[myString]}]}
		} else {
			/invoke ${out[good, IsOuterVariable]}
		}

	| Macro.StackSize
		/if (${Macro.StackSize} != 3) {
			/invoke ${out[bad, StackSize, int, ${Macro.StackSize}]}
		} else {
			/invoke ${out[good, StackSize]}
		}

	| Macro.Params
	  | need to find out it works
		/if (${Macro.Params} != 1) {
			/invoke ${out[bad, Params, 1, ${Macro.Params}]}
		} else {
			/invoke ${out[good, Params]}
		}

	| Macro.CurLine
		/if (!${Range.Between[0,999999:${Macro.CurLine}]}) {
			/invoke ${out[bad, CurLine, int, ${Macro.CurLine}]}
		} else {
			/invoke ${out[good, CurLine]}
		}

	| Macro.CurSub
		/if (${Macro.CurSub.NotEqual[start_MQ2MacroType()]}) {
			/invoke ${out[bad, CurSub, string, ${Macro.CurSub}]}
		} else {
			/invoke ${out[good, CurSub]}
		}

	| Macro.CurCommand
		/invoke ${out[skip, CurCommand, xxx, xxx]}

	| Macro.MemUse
		/if (!${Range.Between[1,999999:${Macro.MemUse}]}) {
			/invoke ${out[bad, MemUse, int, ${Macro.MemUse}]}
		} else {
			/invoke ${out[good, MemUse]}
		}

/return

