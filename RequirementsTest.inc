|***
 * TestSuite.mac
 * testing initial functions/commands used to do all testing for the suite
 *
 *
 ***|




	|** Color Display
		\a-y: 0x999900 (dark yellow)
		\ay: 0xFFFF00 (yellow)
		\a-o: 0x996600 (dark orange)
		\ao: 0xFF9900 (orange)
		\a-g: 0x009900 (dark green)
		\ag: 0x00FF00 (green)
		\a-u: 0x000099 (dark blue)
		\au: 0x0000FF (blue)
		\a-r: 0x990000 (dark red)
		\ar: 0xFF0000 (red)
		\a-t: 0x009999 (dark teal)
		\at: 0x00FFFF (teal)
		\ab: 0x000000 (black)
		\a-m: 0x990099 (dark magenta)
		\am: 0xFF00FF (magenta)
		\a-p: 0x660099 (dark purple)
		\ap: 0x9900FF (purple)
		\a-w: 0x999999 (dark white)
		\aw: 0xFFFFFF (white)
		\ax: (reset)
		\a#XXXXXX: (arbitrary color)
	**|




sub start_RequirementsTest()

	| initial reuse variables
		/declare _count int local 0
		/declare _tmpInt int local 0


	| test an echo
		/echo Starting basic requirements tests
		/mqlog Starting basic requirements tests
		/echo


	| test a /delay
		/echo ..delaying 2 seconds (/delay 2s)

			| test /squelch
				/squelch /echo if you can read this, squelch is broken.

		/echo ..you should notice a 2 second dealy
		/delay 2s
		/echo


	| test colors
		/echo Color test
		/echo ..a-y dark yellow \a-y0x999900\ax
		/echo ..ay yellow \ay0xFFFF00\ax
		/echo ..a-o dark orange \a-o0x996600\ax
		/echo ..ao orange \ao0xFF9900\ax
		/echo ..a-g dark green \a-g0x009900\ax
		/echo ..ag green \ag0x00FF00\ax
		/echo ..a-u dark blue \a-u0x000099\ax
		/echo ..au blue \au0x0000FF\ax
		/echo ..a-r dark red \a-r0x990000\ax
		/echo ..ar red \ar0xFF0000\ax
		/echo ..a-t dark teal \a-t0x009999\ax
		/echo ..at teal \at0x00FFFF\ax
		/echo ..ab black \ab0x000000\ax
		/echo ..a-m dark magenta \a-m0x990099\ax
		/echo ..am magenta \am0xFF00FF\ax
		/echo ..a-p dark purple \a-p0x660099\ax
		/echo ..ap purple\ap0x9900FF\ax
		/echo ..a-w dark white \a-w0x999999\ax
		/echo ..aw white \aw0xFFFFFF\ax
		/echo ..ax reset to default XXXXXX\
		/echo


	| test a /varset. set _tmpInt to 42
		/varset _tmpInt 42
		/if (${_tmpInt} != 42) {
			/mqlog ../varset .. FAIL.. expect:42 got:${_tmpInt}
			/echo ..\aw/varset\ax .. \arBAD\ax
			/echo ....expect: \at42\ax ....got: \at${_tmpInt}\ax
		} else {
			/echo ../varset ..  \agpass\ax
			/mqlog ../varset .. GOOD
		}
		/delay 1


	| test /varcalc
	| add 2 numbers if they are corret good,
		/varset _tmpInt 0
		/varcalc _tmpInt ${_tmpInt} + 10
		/if (${_tmpInt} != 10) {
			/mqlog ../varcalc .. FAIL.. expect:10 got:${_tmpInt}
			/echo ..\aw/varcalc\ax .. \arBAD\ax
			/echo ....expect: \at10\ax ....got: \at${_tmpInt}\ax
		} else {
			/echo ../varcalc .. \agpass\ax
			/mqlog ../varcalc .. GOOD
		}
		/delay 1


	| testing the number 42 falls between 1 to 100
		/if (!${Range.Between[1,100:42]}) {
			/mqlog ..Range.Between .. FAIL.. expect:TRUE got:${Range.Between[1,100:42]}
			/echo ..\awRange.Between\ax .. \arBAD\ax
			/echo ....expect: \atTRUE\ax ....got: \at${Range.Between[1,100:42]}\ax
		} else {
			/echo ..Range.Between .. \agpass\ax
			/mqlog ..Range.Between .. GOOD
		}
		/delay 1
		/echo


	| testing a for/next loop.
	| increment the loop 5 times. if we make it through all good
		/echo testing a loop for 5 counts
		/mqlog testing a loop for 5 counts
		/for _count 1 to 5
			/echo .. loop: \ag${_count}\ax
			/mqlog .. loop: ${_count}


		/next _count
		/echo end of loop test. should stop at \a-w5\ax
		/mqlog end of loop test. should stop at \a-w5\ax
		/delay 1
		/echo


	| testing a for/next loop break.
	| increment the loop 5 times. break the loop on the 3d iteration
		/echo testing a loop for 5 counts, breaking on the third
		/mqlog testing a loop for 5 counts, breaking on the third
		/for _count 1 to 5
			/echo .. loop: \ag${_count}\ax
			/mqlog .. loop: ${_count}
			/if (${_count} == 3) {
				/break
			}
		/next _count
		/echo end of loop test. should stop at \a-w3\ax
		/mqlog end of loop test. should stop at \a-w3\ax
		/delay 1
		/echo


	| testing a for/next loop continue.
	| increment the loop 5 times. skip the 3d iteration
		/echo testing a loop for 5 counts, skipping the third
		/mqlog testing a loop for 5 counts, skipping the third
		/for _count 1 to 5
			/if (${_count} == 3) {
				/continue
			}
			/echo .. loop: \ag${_count}\ax
			/mqlog .. loop: ${_count}

		/next _count
		/echo end of loop test. should stop at \a-w5\ax skipping \a-w3\ax
		/mqlog end of loop test. should stop at \a-w5\ax skipping \a-w3\ax
		/delay 1
		/echo


	| array test
		/echo testing array:
		/echo ..[1] red, green, blue
		/echo ..[2] white, black, grey

		/declare _arraytest[2] string local
		/varset _arraytest[1] |red|green|blue
		/varset _arraytest[2] |white|black|grey

		/echo ..[1,2] = ${_arraytest[1].Arg[2,|]}
		/echo ..[2,3] = ${_arraytest[2].Arg[3,|]}
		/delay 1


	| testing an invoke to return a simple string
		| /invoke




/return