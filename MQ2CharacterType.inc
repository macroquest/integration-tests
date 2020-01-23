|***
 * TestSuite.mac
 * MQ2DataTypes.cpp
 * testing MQ2CharacterType
 *
 ***|






sub start_MQ2CharacterType()
	/echo
	OUT Testing::\awMQ2CharacterType\ax (\a-tMe.\ax)
	LOG
	LOG Testing::MQ2CharacterType

	| reuse variables
		/declare _count int local 0
		/declare _countArray int local 0
		/declare _MemberList string local
		/declare _tmpMember string local
		/declare _tmpSwitch bool local FALSE
		/declare _tmpString string local


	| STR, STA, AGI, DEX, WIS, INT, CHA
		/varset _MemberList |STR|STA|AGI|DEX|WIS|INT|CHA
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,99999:${Me.${_tmpMember}}]}) {
				/invoke ${out[bad, ${_tmpMember}, int, ${Me.${_tmpMember}}]}
			} else {
				/invoke ${out[good, ${_tmpMember}]}
			}
		/next _count


	| LCK
		/if (!${Range.Between[0,99999:${Me.LCK}]}) {
			/invoke ${out[bad, LCK, int, ${Me.LCK}]}
		} else {
			/invoke ${out[good, ${Me.LCK}]}
		}


	| BaseSTR, BaseSTA, BaseAGI, BaseDEX, BaseWIS, BaseINT, BaseCHA
		/varset _MemberList |BaseSTR|BaseSTA|BaseAGI|BaseDEX|BaseWIS|BaseINT|BaseCHA
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,300:${Me.${_tmpMember}}]}) {
				/invoke ${out[bad, ${_tmpMember}, int, ${Me.${_tmpMember}}]}
			} else {
				/invoke ${out[good, ${_tmpMember}]}
			}
		/next _count


	| svMagic, svFire, svCold, svPoison, svDisease, svCorruption, svPrismatic, svChromatic
		/varset _MemberList |svMagic|svFire|svCold|svPoison|svDisease|svCorruption|svPrismatic|svChromatic
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,9999:${Me.${_tmpMember}}]}) {
				/invoke ${out[bad, ${_tmpMember}, int, ${Me.${_tmpMember}}]}
			} else {
				/invoke ${out[good, ${_tmpMember}]}
			}
		/next _count


	| HeroicINTBonus, HeroicWISBonus, HeroicAGIBonus, HeroicDEXBonus, HeroicSTABonus, HeroicCHABonus, HeroicSTRBonus
		/varset _MemberList |HeroicINTBonus|HeroicWISBonus|HeroicAGIBonus|HeroicDEXBonus|HeroicSTABonus|HeroicCHABonus|HeroicSTRBonus
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[0,9999:${Me.${_tmpMember}}]}) {
				/invoke ${out[bad, ${_tmpMember}, int, ${Me.${_tmpMember}}]}
			} else {
				/invoke ${out[good, ${_tmpMember}]}
			}
		/next _count


	| Me.CurrentWeight
		/if (!${Range.Between[1,999999:${Me.CurrentWeight}]}) {
			/invoke ${out[bad, CurrentWeight, int, ${Me.CurrentWeight}]}
		} else {
			/invoke ${out[good, CurrentWeight]}
		}


	| Me.Name
		/if (!${Range.Between[4,24:${Me.Name.Length}]}) {
			/invoke ${out[bad, Name, int, ${Me.Name.Length}]}
		} else {
			/invoke ${out[good, Name]}
		}


	| Me.Origin
		/varset _tmpSwitch FALSE
		/declare _origin[3] string local
		/varset _origin[1] |Northern Felwithe|Southern Felwithe|Crescent Reach|Halas|South Kaladim|Erudin Palace|Ak'Anon|Surefall Glade|The Grater Faydark|Riverdale
		/varset _origin[2] |West Freeport|East Freeport|Cabilis East|Cabilis West|Oggok|Grobb|Shar Vahl|The Rathe Mountains|South Qeynos|North Qeynos|
		/varset _origin[3] |Neriak - Commons|Neriak - Third Gate

		/for _countArray 1 to ${_origin.Size}
			/for _count 1 to ${_origin[${_countArray}].Count[|]}
				/if (${Zone[${Me.Origin}].ID} == ${Zone[${_origin[${_countArray}].Arg[${_count},|]}].ID}) {
					/varset _tmpSwitch TRUE
					/break
				}

			/next _count
		/if (${_tmpSwitch}) /break
		/next _countArray

		/if (!${_tmpSwitch}) {
			/invoke ${out[bad, Origin, string, ${Me.Origin}]}
		} else {
			/invoke ${out[good, Origin]}
		}
		/deletevar _origin


	| Me.SubscriptionDays
		/if (!${Range.Between[-1,365:${Me.SubscriptionDays}]}) {
			/invoke ${out[bad, SubscriptionDays, int, ${Me.SubscriptionDays}]}
		} else {
			/invoke ${out[good, SubscriptionDays]}
		}


	| Me.Subscription
		/if (!${Select[${Me.Subscription},FREE,SILVER,GOLD]}) {
			/invoke ${out[bad, Subscription, "string (FREE|SILVER|GOLD)", ${Me.Subscription}]}
		} else {
			/invoke ${out[good, Subscription]}
		}


	| Me.Exp
	| exp is returning an int of ##### eg 42862 or 42.862% to the end user screen
		/if (!${Range.Between[1,99999:${Me.Exp}]}) {
			/invoke ${out[bad, Exp, int, ${Me.Exp}]}
		} else {
			/invoke ${out[good, Exp]}
		}


	| Me.PctExp
		/if (!${Range.Between[1,100:${Me.PctExp}]}) {
			/invoke ${out[bad, PctExp, int, ${Me.PctExp}]}
		} else {
			/invoke ${out[good, PctExp]}
		}


	| Me.PctExpToAA
		/if (!${Range.Between[0,100:${Me.PctExpToAA}]}) {
			/invoke ${out[bad, PctExpToAA, int, ${Me.PctExpToAA}]}
		} else {
			/invoke ${out[good, PctExpToAA]}
		}


	| Me.PctAAExp
		/if (!${Range.Between[0,100:${Me.PctAAExp}]}) {
			/invoke ${out[bad, PctAAExp, int, ${Me.PctAAExp}]}
		} else {
			/invoke ${out[good, PctAAExp]}
		}


	| Me.Vitality
		/if (!${Range.Between[0,100:${Me.Vitality}]}) {
			/invoke ${out[bad, Vitality, int, ${Me.Vitality}]}
		} else {
			/invoke ${out[good, Vitality]}
		}


	| Me.PctVitality
		/if (!${Range.Between[0,100:${Me.PctVitality}]}) {
			/invoke ${out[bad, PctVitality, int, ${Me.PctVitality}]}
		} else {
			/invoke ${out[good, PctVitality]}
		}


	| Me.AAVitality
		/if (!${Range.Between[0,100:${Me.AAVitality}]}) {
			/invoke ${out[bad, AAVitality, int, ${Me.AAVitality}]}
		} else {
			/invoke ${out[good, Vitality]}
		}


	| Me.PctAAVitality
		/if (!${Range.Between[0,100:${Me.PctAAVitality}]}) {
			/invoke ${out[bad, PctAAVitality, int, ${Me.PctAAVitality}]}
		} else {
			/invoke ${out[good, PctAAVitality]}
		}


	| Me.Spawn


	| Me.CurrentHPs
		/if (!${Range.Between[0,999999:${Me.CurrentHPs}]}) {
			/invoke ${out[bad, CurrentHPs, int, ${Me.CurrentHPs}]}
		} else {
			/invoke ${out[good, CurrentHPs]}
		}


	| Me.MaxHPs
		/if (!${Range.Between[0,999999:${Me.MaxHPs}]}) {
			/invoke ${out[bad, MaxHPs, int, ${Me.MaxHPs}]}
		} else {
			/invoke ${out[good, MaxHPs]}
		}


	| Me.PctHPs
		/if (!${Range.Between[0,100:${Me.PctHPs}]}) {
			/invoke ${out[bad, PctHPs, int, ${Me.PctHPs}]}
		} else {
			/invoke ${out[good, PctHPs]}
		}


	| Me.CurrentMana
		/if (!${Range.Between[0,999999:${Me.CurrentMana}]}) {
			/invoke ${out[bad, CurrentMana, int, ${Me.CurrentMana}]}
		} else {
			/invoke ${out[good, CurrentMana]}
		}


	| Me.MaxMana
		/if (!${Range.Between[0,999999:${Me.MaxMana}]}) {
			/invoke ${out[bad, MaxMana, int, ${Me.MaxMana}]}
		} else {
			/invoke ${out[good, MaxMana]}
		}


	| Me.PctMana
		/if (!${Range.Between[0,100:${Me.PctMana}]}) {
			/invoke ${out[bad, PctMana, int, ${Me.PctMana}]}
		} else {
			/invoke ${out[good, PctMana]}
		}


	| Me.CountBuffs
		/if (!${Range.Between[0,42:${Me.CountBuffs}]}) {
			/invoke ${out[bad, CountBuffs, int, ${Me.CountBuffs}]}
		} else {
			/invoke ${out[good, CountBuffs]}
		}


	| Me.CountSongs
		/if (!${Range.Between[0,30:${Me.CountSongs}]}) {
			/invoke ${out[bad, CountSongs, int, ${Me.CountSongs}]}
		} else {
			/invoke ${out[good, CountSongs]}
		}


	| Me.BlockedPetBuff

	| Me.BlockedBuff

	| Me.Buff

	| Me.Song



	| test bonus foci
		/declare _focus[4] string local
		/varset _focus[1] |HPRegen|ManaRegen|HPBonus|ManaBonus|CombatEffectsBonus|ShieldingBonus|SpellShieldBonus|AvoidanceBonus|AccuracyBonus
		/varset _focus[2] |StunResistBonus|StrikeThroughBonus|DoTShieldBonus|AttackBonus|HPRegenBonus|ManaRegenBonus|DamageShieldBonus
		/varset _focus[3] |DamageShieldMitigationBonus|HealAmountBonus|SpellDamageBonus|ClairvoyanceBonus|EnduranceRegenBonus|AttackSpeed
		/varset _focus[4] |CurrentEndurance|MaxEndurance|PctEndurance|EnduranceRegen

		/for _countArray 1 to ${_focus.Size}
			/for _count 1 to ${_focus[${_countArray}].Count[|]}
				/if (!${Range.Between[0,999999:${Me.${_focus[${_countArray}].Arg[${_count},|]}}]}) {
					/invoke ${out[bad, ${_focus[${_countArray}].Arg[${_count},|]}, int, ${Me.${_focus[${_countArray}].Arg[${_count},|]}}]}
				} else {
					/invoke ${out[good, ${_focus[${_countArray}].Arg[${_count},|]}]}
				}
			/next _count
		/next _countArray
		/deletevar _focus



	| Me.GukEarned
	| Me.MMEarned
	| Me.RujEarned
	| Me.TakEarned
	| Me.MirEarned
	| Me.LDoNPoints



	| Me.Inventory


	| Me.Bank
		/varset _tmpSwitch FALSE
		/for _count 1 to 30
			/varset _tmpString ${Me.Bank[${_count}]}
			/if (${Bool[${Me.Bank[${_count}]}]}) {
				/varset _tmpSwitch TRUE
				/break
			}
		/next _count

		/if (!${_tmpSwitch}) {
			/invoke ${out[inc, Bank, string, ${_tmpString}]}
			OUT ....(\a-tunable to test, nothing found in bank\ax)
		} else {
			/invoke ${out[good, Bank]}
		}


	| Cash, Platinum, Gold, Silver, Copper
		/varset _MemberList |Cash|Platinum|Gold|Silver|Copper
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}
			/if (!${Range.Between[0,999999999999:${Me.${_tmpMember}}]}) {
				/invoke ${out[bad, ${_tmpMember}, int, ${Me.${_tmpMember}}]}
			} else {
				/invoke ${out[good, ${_tmpMember}]}
			}
		/next _count


	| CashBank, PlatinumBank, GoldBank, CursorSilver, CopperBank
		/varset _MemberList |CashBank|PlatinumBank|GoldBank|SilverBank|CopperBank
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[0,999999999999:${Me.${_tmpMember}}]}) {
				/invoke ${out[bad, ${_tmpMember}, int, ${Me.${_tmpMember}}]}
			} else {
				/invoke ${out[good, ${_tmpMember}]}
			}
		/next _count


	| Me.PlatinumShared
		/if (!${Range.Between[0,999999999999:${Me.PlatinumShared}]}) {
			/invoke ${out[bad, PlatinumShared, int, ${Me.PlatinumShared}]}
		} else {
			/invoke ${out[good, PlatinumShared]}
		}


	| Me.CursorPlatinum
	| Me.CursorGold
	| Me.CursorSilver
	| Me.CursorCopper

	| Me.AltCurrency
		/declare _altCurrency[6] string local
		/varset _altCurrency[1] |Doubloons|Orux|Phosphenes|Phosphites|Faycites|Chronobines|Commemoratives|Nobles|Fists|RadiantCrystals
		/varset _altCurrency[2] |EbonCrystals|Krono|CursorKrono|EnergyCrystals|PiecesofEight|SilverTokens|GoldTokens|McKenzie|Bayle
		/varset _altCurrency[3] |Reclamation|Brellium|Motes|RebellionChits|DiamondCoins|BronzeFiats|Voucher|VeliumShards|CrystallizedFear
		/varset _altCurrency[4] |ShadowStones|DreadStones|MarksOfValor|MedalsOfHeroism|RemnantOfTranquility|BifurcatedCoin|AdoptiveCoin
		/varset _altCurrency[5] |SathirsTradeGems|AncientSebilisianCoins|BathezidTradeGems|AncientDraconicCoin|FetterredIfritCoins
		/varset _altCurrency[6] |EntwinedDjinnCoins|CrystallizedLuck

		/for _countArray 1 to ${_altCurrency.Size}
			/for _count 1 to ${_altCurrency[${_countArray}].Count[|]}
				/if (!${Range.Between[0,999999999999:${Me.${_altCurrency[${_countArray}].Arg[${_count},|]}}]}) {
					/invoke ${out[bad, ${_altCurrency[${_countArray}].Arg[${_count},|]}, int, ${Me.${_altCurrency[${_countArray}].Arg[${_count},|]}}]}
				} else {
					/invoke ${out[good, ${_altCurrency[${_countArray}].Arg[${_count},|]}]}
				}
			/next _count
		/next _countArray
		/deletevar _altCurrency


	| Me.AAExp
		/if (!${Range.Between[0,99999:${Me.AAExp}]}) {
			/invoke ${out[bad, AAExp, int, ${Me.AAExp}]}
		} else {
			/invoke ${out[good, AAExp]}
		}

	| Me.AAPoints
		/if (!${Range.Between[0,99999:${Me.AAPoints}]}) {
			/invoke ${out[bad, AAPoints, int, ${Me.AAPoints}]}
		} else {
			/invoke ${out[good, AAPoints]}
		}


	| Me.Combat
		/declare _combatactive bool local FALSE
		/declare _combatinactive bool local FALSE
		/squelch /target clear
		/attack off
		/if (!${Me.Combat}) {
			/varse _combatinactive TRUE
		}
		/attack on
		/if (${Me.Combat}) {
			/varse _combatactive TRUE
		}
		/attack off
		/if (!${_combatinactive} || !${_combatactive}) {
			/invoke ${out[bad, Combat, bool, ${Me.Combat}]}
			OUT ....(\a-tcheck targeting\ax)
		} else {
			/invoke ${out[good, Combat]}
		}
		/deletevar _combatactive
		/deletevar _combatinactive


	| Me.Grouped
		/if (${Select[${Me.Grouped},NULL]}) {
			/invoke ${out[inc, Grouped, int, ${Me.Grouped}]}
			OUT ....(\a-tcannot test, not grouped\ax)
		} else {
			/invoke ${out[good, Grouped]}
		}

	| Me.GroupList


	| Me.GroupSize
		/if (${Select[${Me.Grouped},NULL]}) {
			/invoke ${out[inc, Grouped, int, ${Me.Grouped}]}
			OUT ....(\a-tcannot test, not grouped\ax)
		} else /if (!${Range.Between[1,6:${Me.GroupSize}]}) {
			/invoke ${out[bad, GroupSize, int, ${Me.GroupSize}]}
		} else {
			/invoke ${out[good, GroupSize]}
		}


	| Me.AmIGroupLeader
		/if (${Select[${Me.Grouped},NULL]}) {
			/invoke ${out[inc, AmIGroupLeader, bool, ${Me.AmIGroupLeader}]}
			OUT ....(\a-tcannot test, not grouped\ax)
		} else /if (!${Me.AmIGroupLeader} || ${Me.AmIGroupLeader}) {
			/invoke ${out[good, AmIGroupLeader]}
		}


	| Me.MaxBuffSlots
		/if (!${Range.Between[1,42:${Me.MaxBuffSlots}]}) {
			/invoke ${out[bad, MaxBuffSlots, int, ${Me.MaxBuffSlots}]}
		} else {
			/invoke ${out[good, MaxBuffSlots]}
		}


	| Me.FreeBuffSlots
		/if (!${Range.Between[1,42:${Me.FreeBuffSlots}]}) {
			/invoke ${out[bad, FreeBuffSlots, int, ${Me.FreeBuffSlots}]}
		} else {
			/invoke ${out[good, FreeBuffSlots]}
		}

	| Me.Gem
		/if (!${Select[${Me.Class.ShortName},WAR,ROG,BER,MON]}) {
			/for _count 1 to ${Me.NumGems}
				/if (${Bool[${Me.Gem[${_count}]}]}) {
					/varset _tmpSwitch TRUE
					/break
				}
			/next _count
		}

		| classes that don't have gems
		/if (${Select[${Me.Class.ShortName},WAR,ROG,BER,MON]}) {
			/invoke ${out[inc, Gem, string, ${Me.Gem}]}
			OUT ....(\a-tclass does not use gems\ax)

		| did not find a gem with a spell
		} else /if (!${_tmpSwitch}) {
			/invoke ${out[inc, Gem, string, ${Me.Gem}]}
			OUT ....(\a-tno gems loaded\ax)

		| found and good
		} else /if (${_tmpSwitch}) {
			/invoke ${out[good, Gem]}
		}


	| Me.LanguageSkill
		/if (!${Range.Between[0,100:${Me.LanguageSkill[common]}]}) {
			/invoke ${out[bad, LanguageSkill[common], int, ${Me.LanguageSkill[common]}]}
		} else {
			/invoke ${out[good, LanguageSkill[common]]}
		}


	| Me.Language
		/declare _language[3] string local
		/varset _language[1] |Common Tongue|Barbarian|Erudian|Elvish|Dwarvish|Troll|Ogre|Gnomish|Halfling|Theves Cant|Old Erudian
		/varset _language[2] |Elder Elvish|Froglock|Goblin|Gnoll|Combine Tongue|Elder Teir'Dal|Lizardman|Orcish|Faerie|Dragon
		/varset _language[3] |Elder Dragon|Dark Speech|Vah Shir|Alarian|Hadal

		/for _countArray 1 to ${_language.Size}
			/for _count 1 to ${_language[${_countArray}].Count[|]}
				/if (!${Range.Between[0,100:${Me.Language[${_language[${_countArray}].Arg[${_count},|]}]}]}) {
					/invoke ${out[bad, Language[${_language[${_countArray}].Arg[${_count},|]}], int, ${Me.${_language[${_countArray}].Arg[${_count},|]}}]}
				} else {
					/invoke ${out[good, Language[${_language[${_countArray}].Arg[${_count},|]}]]}
				}
			/next _count
		/next _countArray
		/deletevar _language


	| Me.CombatAbility
	| Me.CombatAbilityTimer
	| Me.CombatAbilityReady
	| Me.ActiveDisc

	| Me.Moving
		/if (!${Me.Moving}) {
			/invoke ${out[inc, Moving, bool, ${Me.Moving}]}
			OUT ....(\a-tmotion test\ax)
		} else {
			/invoke ${out[inc, Moving, bool, ${Me.Moving}]}
			OUT ....(\a-tmotion test\ax)
		}


	| Me.Running
		/if (!${Select[${Me.Running},TRUE,FALSE]}) {
			/invoke ${out[bad, Running, bool, ${Me.Running}]}
		} else {
			/invoke ${out[good, Running]}
		}


	| Me.Hunger
		/if (!${Range.Between[0,10000:${Me.Hunger}]}) {
			/invoke ${out[bad, Hunger, int, ${Me.Hunger}]}
		} else {
			/invoke ${out[good, Hunger]}
		}


	| Me.Thirst
		/if (!${Range.Between[0,10000:${Me.Thirst}]}) {
			/invoke ${out[bad, Thirst, int, ${Me.Thirst}]}
		} else {
			/invoke ${out[good, Thirst]}
		}

	| Me.Drunk
		/if (!${Range.Between[0,100:${Me.Drunk}]}) {
			/invoke ${out[inc, Drunk, int, ${Me.Drunk}]}
			OUT ....(\a-tgo drink some alcohol to test this\ax)
		} else {
			/invoke ${out[good, Drunk]}
		}


	| Me.AltAbilityTimer
		/if (!${Range.Between[0,100:${Me.AltAbilityTimer[origin]}]}) {
			/invoke ${out[bad, AltAbilityTimer[origin], int, ${Me.AltAbilityTimer[origin]}]}
		} else {
			/invoke ${out[good, AltAbilityTimer[origin]]}
		}


	| Me.AltTimerReady
		/if (!${Me.AltTimerReady[origin]}) {
			/invoke ${out[bad, AltTimerReady[origin], bool, ${Me.AltTimerReady[origin]}]}
		} else {
			/invoke ${out[good, AltTimerReady[origin]]}
		}


	| Me.AltAbilityReady
		/if (!${Me.AltAbilityReady[origin]}) {
			/invoke ${out[bad, AltAbilityReady[origin], bool, ${Me.AltAbilityReady[origin]}]}
		} else {
			/invoke ${out[good, AltAbilityReady[origin]]}
		}


	| Me.AltAbility
		/if (${Me.AltAbility[origin]} != 331) {
			/invoke ${out[bad, AltAbility[origin], int, ${Me.AltAbility[origin]}]}
		} else {
			/invoke ${out[good, AltAbility[origin]]}
		}


	| Skill, SkillBase, SkillCap
		/varset _MemberList |Skill|SkillBase|SkillCap
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _tmpMember ${_MemberList.Arg[${_count},|]}
			/if (!${Range.Between[1,99999:${Me.${_tmpMember}[alcohol tolerance]}]}) {
				/invoke ${out[bad, ${_tmpMember}[alcohol tolerance], int, ${Me.${_tmpMember}[alcohol tolerance]}]}
			} else {
				/invoke ${out[good, ${_tmpMember}[alcohol tolerance]]}
			}
		/next _count





	| Me.Ability


	| Me.RangedReady

	| Me.Book
	| Me.Spell
	| Me.ItemReady
	| Me.BardSongPlaying
	| Me.SpellReady
	| Me.PetBuff
	| Me.Stunned
	| Me.LargestFreeInventory
	| Me.FreeInventory
	| Me.TargetOfTarget

	| Me.RaidAssistTarget
	| Me.GroupAssistTarget
	| Me.RaidMarkNPC
	| Me.GroupMarkNPC







	| Me.AAPointsTotal
	| Me.AAPointsAssigned


	| Me.TributeActive
	| Me.TributeTimer
	| Me.CurrentFavor
	| Me.CareerFavor









	| Me.Shrouded


	| Me.AutoFire


	| Me.Aura


	| Me.LAMarkNPC
	| Me.LANPCHealth
	| Me.LADelegateMA
	| Me.LADelegateMarkNPC
	| Me.LAInspectBuffs
	| Me.LASpellAwareness
	| Me.LAOffenseEnhancement
	| Me.LAManaEnhancement
	| Me.LAHealthEnhancement


	| Me.LAHealthRegen
	| Me.LAFindPathPC
	| Me.LAHoTT
	| Me.ActiveFavorCost
	| Me.CombatState





	| Me.Fellowship


	| Me.Downtime





	| Dar ???

	| Me.Mercenary
		/if (${Select[${Me.Mercenary},SUSPENDED]}) {
			/invoke ${out[inc, Mercenary, string, ${Me.Mercenary}]}
			OUT ....(\a-tneed a merc to test with\ax)
		} else /if (!${Me.Mercenary.ID}) {
			/invoke ${out[bad, Mercenary, string, ${Me.Mercenary}]}
		} else {
			/invoke ${out[good, Mercenary, string, ${Me.Mercenary}]}
		}


	| Me.MercenaryStance
		/if (${Select[${Me.Mercenary},SUSPENDED]}) {
			/invoke ${out[inc, MercenaryStance, string, ${Me.MercenaryStance}]}
			OUT ....(\a-tneed a merc to test with\ax)
		} else /if (!${Select[${Me.MercenaryStance},Reactive,Balanced,Effeicient,Passive,Burn,Aggressive,Assist]}) {
			/invoke ${out[bad, MercenaryStance, string, ${Me.MercenaryStance}]}
		} else {
			/invoke ${out[good, MercenaryStance, string, ${Me.MercenaryStance}]}
		}



	| Me.PctMercAAExp


	| Me.MercAAExp
	| Me.MercAAPoints
	| Me.MercAAPointsSpent
	| Me.MercListInfo



	| Me.XTargetSlots
	| Me.XTAggroCount
	| Me.XTHaterCount
	| Me.XTarget

	| Me.Haste


	| Me.SPA



	| Me.GemTimer

	| Me.HaveExpansion
		/if (!${Me.HaveExpansion[The Ruins of Kunark]}) {
			/invoke ${out[bad, HaveExpansion[The Ruins of Kunark], int, ${Me.HaveExpansion[The Ruins of Kunark]}]}
		} else {
			/invoke ${out[good, HaveExpansion[The Ruins of Kunark]]}
		}

	| Me.PctAggro
	| Me.SecondaryPctAggro
	| Me.SecondaryAggroPlayer



	| Me.AggroLock


	| Me.ZoneBound

	| Me.ZoneBoundX
	| Me.ZoneBoundY
	| Me.ZoneBoundZ








	| Me.Slowed
	| Me.Rooted
	| Me.Crippled
	| Me.Maloed
	| Me.Mezzed
	| Me.Tashed
	| Me.Snared
	| Me.Hasted






	| Me.LastZoned
		/invoke ${out[inc, LastZoned, int, ${Me.LastZoned}]}
		OUT ....(\a-ti refuse to do this one\ax)

	| Me.Zoning
		/invoke ${out[inc, Zoning, int, ${Me.Zoning}]}
		OUT ....(\a-tuseless damn commands\ax)



	| Me.TotalCounters
	| Me.CountersDisease
	| Me.CountersPoison
	| Me.CountersCurse
	| Me.CountersCorruption
	| Me.Diseased
	| Me.Poisoned
	| Me.Cursed
	| Me.Corrupted


	| Me.DSed
	| Me.RevDSed
	| Me.Feared
	| Me.Silenced
	| Me.Charmed
	| Me.Invulnerable
	| Me.Dotted




	| Me.Aego

	| Me.Skin

	| Me.Focus
	| Me.Regen


	| Me.Symbol

	| Me.Clarity

	| Me.Pred
	| Me.Strength
	| Me.Brells
	| Me.SV
	| Me.SE
	| Me.HybridHP
	| Me.Growth
	| Me.Shining




	| Me.InInstance
	| Me.Instance
	| Me.UseAdvancedLooting


	| Me.SpellInCooldown

	| Me.AssistComplete

	| Me.NumGems

	| Me.GuildID

	| Me.ExpansionFlags


	| Me.BoundLocation

	| Me.AutoSkill


	| Me.Beneficial

	| Me.Bandolier





/return











