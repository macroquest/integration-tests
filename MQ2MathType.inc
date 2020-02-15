|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2MathType
 *
 ***|





sub start_MQ2MathType()
	/echo
	OUT Testing::\awMQ2MathType\ax (\a-tMath.\ax)
	LOG
	LOG Testing::MQ2MathType



	| test intiger 49
	/declare num int local 49
	OUT ..Test number \at${num}\ax




	| Abs
		/if (${Math.Abs[${num}]} != 49.00) {
			/invoke ${out[bad, Abs[${num}], int, ${Math.Abs[${num}]}]}
		} else {
			/invoke ${out[good, Abs[${num}]]}
		}

	| Rand
		/if (!${Range.Between[1,${num}:${Math.Rand[${num}]}]}) {
			/invoke ${out[bad, Rand[${num}], int, ${Math.Rand[${num}]}]}
		} else {
			/invoke ${out[good, Rand[${num}]]}
		}

	| Sqrt
		/if (${Math.Sqrt[${num}]} != 7) {
			/invoke ${out[bad, Sqrt[${num}], int, ${Math.Sqrt[${num}]}]}
		} else {
			/invoke ${out[good, Sqrt[${num}]]}
		}

	| Calc
		/if (${Math.Calc[${num}+1]} != 50) {
			/invoke ${out[bad, Calc[${num}+1], int, ${Math.Calc[${num}+1]}]}
		} else {
			/invoke ${out[good, Calc[${num}+1]]}
		}

	| Sin
		/if (${Math.Sin[${num}]} != .75) {
			/invoke ${out[bad, Sin[${num}], int, ${Math.Sin[${num}]}]}
		} else {
			/invoke ${out[good, Sin[${num}]]}
		}

	| Cos
		/if (${Math.Cos[${num}]} != .66) {
			/invoke ${out[bad, Cos[${num}], int, ${Math.Cos[${num}]}]}
		} else {
			/invoke ${out[good, Cos[${num}]]}
		}

	| Tan
		/if (${Math.Tan[${num}]} != 1.15) {
			/invoke ${out[bad, Tan[${num}], int, ${Math.Tan[${num}]}]}
		} else {
			/invoke ${out[good, Tan[${num}]]}
		}

	| Asin
		/if (${Math.Asin[1]} != 90.00) {
			/invoke ${out[bad, Asin[1], int, ${Math.Asin[1]}]}
		} else {
			/invoke ${out[good, Asin[1]]}
		}

	| Acos
		/if (${Math.Acos[-1]} != 180.00) {
			/invoke ${out[bad, Acos[-1], int, ${Math.Acos[-1]}]}
		} else {
			/invoke ${out[good, Acos[-1]]}
		}

	| Atan
		/if (${Math.Atan[${num}]} != 88.83) {
			/invoke ${out[bad, Atan[${num}], int, ${Math.Atan[${num}]}]}
		} else {
			/invoke ${out[good, Atan[${num}]]}
		}

	| Not
		/if (${Math.Not[${num}]} != -50) {
			/invoke ${out[bad, Not[${num}], int, ${Math.Not[${num}]}]}
		} else {
			/invoke ${out[good, Not[${num}]]}
		}

	| Hex
		/if (${Math.Hex[${num}].NotEqual[0x31]}) {
			/invoke ${out[bad, Hex[${num}], string, ${Math.Hex[${num}]}]}
		} else {
			/invoke ${out[good, Hex[${num}]]}
		}

	| Dec
		/if (${Math.Dec[${num}]} != 73) {
			/invoke ${out[bad, Dec[${num}], int, ${Math.Dec[${num}]}]}
		} else {
			/invoke ${out[good, Dec[${num}]]}
		}

	| Clamp
		/if (${Math.Clamp[99,1,49]} != 49) {
			/invoke ${out[bad, Clamp[99 1 49], int, ${Math.Clamp[99,1,49]}]}
		} else {
			/invoke ${out[good, Clamp[99 1 49]]}
		}



	| Distance
	| we will assume Spawn[].Distance/X/Y/Z are all functioning properly for this
	| and that there is another spawn in the zone

		| get us another spawn
		/if (${NearestSpawn[2, NPC].ID}) {
			/declare spawnID int local ${NearestSpawn[2, NPC].ID}
			| set the spawn position
			/declare spawnY float local ${Spawn[id ${spawnID}].Y}
			/declare spawnX float local ${Spawn[id ${spawnID}].X}
			/declare spawnZ float local ${Spawn[id ${spawnID}].Z}
			/declare spawnDis float local ${Spawn[id ${spawnID}].Distance}

			/echo [${Me.Y},${Me.X},${Me.Z}:${Spawn[id ${spawnID}].Y},${Spawn[id ${spawnID}].X},${Spawn[id ${spawnID}].Z}]
			/echo (${Math.Distance[${Me.Y},${Me.X},${Me.Z}:${Spawn[id ${spawnID}].Y},${Spawn[id ${spawnID}].X},${Spawn[id ${spawnID}].Z}]} != ${Spawn[id ${spawnID}].Distance}) {

			| calculate the distance and validate
			/if (${Math.Distance[${Me.Y},${Me.X},${Me.Z}:${Spawn[id ${spawnID}].Y},${Spawn[id ${spawnID}].X},${Spawn[id ${spawnID}].Z}]} != ${Spawn[id ${spawnID}].Distance}) {
				/invoke ${out[bad, Distance, int, ${Math.Distance[${Me.Y},${Me.X},${Me.Z}:${Spawn[id ${spawnID}].Y},${Spawn[id ${spawnID}].X},${Spawn[id ${spawnID}].Z}]}]}
			} else {
				/invoke ${out[good, Distance]}
			}



	} else {
		OUT ....(\a-tCannot test, no spawns\ax)
		OUT ....(\a-twhere are you anyway?\ax)
	}




	/deletevar num



/return




${Math.Acos[49]}














	/declare pi string local 3.1415926535

	OUT ..Test String \at${pi}\ax

	| Float
		/if (${Int[${pi}].Float} != 3.00) {
			/invoke ${out[bad, Float, int, ${Int[${pi}].Float}]}
		} else {
			/invoke ${out[good, Float]}
		}

	| Double
		/if (${Int[${pi}].Double} != 3.00) {
			/invoke ${out[bad, Double, int, ${Int[${pi}].Double}]}
		} else {
			/invoke ${out[good, Double]}
		}

	| Hex
		/if (${Int[${pi}].Hex.NotEqual[0x3]}) {
			/invoke ${out[bad, Hex, int, ${Int[${pi}].Hex}]}
		} else {
			/invoke ${out[good, Hex]}
		}

	| Reverse
		/if (${Int[${pi}].Reverse} != 50331648) {
			/invoke ${out[bad, Reverse, int, ${Int[${pi}].Reverse}]}
		} else {
			/invoke ${out[good, Reverse]}
		}

	| LowPart
		/if (${Int[${pi}].LowPart} != 3) {
			/invoke ${out[bad, LowPart, int, ${Int[${pi}].LowPart}]}
		} else {
			/invoke ${out[good, LowPart]}
		}

	| HighPart
		/if (${Int[${pi}].HighPart} != 0) {
			/invoke ${out[bad, HighPart, int, ${Int[${pi}].HighPart}]}
		} else {
			/invoke ${out[good, HighPart]}
		}

	| clear variable
	/deletevar pi


/return


