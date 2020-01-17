


sub start_MQ2CharacterType()
	/echo
	OUT Testing::\awMQ2CharacterType\ax (\a-tMe.\ax)
	LOG
	LOG Testing::MQ2CharacterType

	| reuse variables
	/declare _count int local 0
	/declare _countArray int local 0
	/declare _stat string local
	/declare _MemberList string local
	/declare _tmpSwitch bool local FALSE
	/declare _tmpString string local


	| STR, STA, AGI, DEX, WIS, INT, CHA, LCK
		/varset _MemberList |STR|STA|AGI|DEX|WIS|INT|CHA|LCK
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _stat ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,99999:${Me.${_stat}}]}) {
				/invoke ${out[bad, ${_stat}, int, ${Me.${_stat}}]}
			} else {
				/invoke ${out[good, ${_stat}]}
			}
		/next _count



	| BaseSTR, BaseSTA, BaseAGI, BaseDEX, BaseWIS, BaseINT, BaseCHA
		/varset _MemberList |BaseSTR|BaseSTA|BaseAGI|BaseDEX|BaseWIS|BaseINT|BaseCHA
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _stat ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,99999:${Me.${_stat}}]}) {
				/invoke ${out[bad, ${_stat}, int, ${Me.${_stat}}]}
			} else {
				/invoke ${out[good, ${_stat}]}
			}
		/next _count




	| svMagic, svFire, svCold, svPoison, svDisease, svCorruption, svPrismatic, svChromatic
		/varset _MemberList |svMagic|svFire|svCold|svPoison|svDisease|svCorruption|svPrismatic|svChromatic
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _stat ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,99999:${Me.${_stat}}]}) {
				/invoke ${out[bad, ${_stat}, int, ${Me.${_stat}}]}
			} else {
				/invoke ${out[good, ${_stat}]}
			}
		/next _count




	| HeroicINTBonus, HeroicWISBonus, HeroicAGIBonus, HeroicDEXBonus, HeroicSTABonus, HeroicCHABonus
		/varset _MemberList |HeroicINTBonus|HeroicWISBonus|HeroicAGIBonus|HeroicDEXBonus|HeroicSTABonus|HeroicCHABonus
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _stat ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[1,99999:${Me.${_stat}}]}) {
				/invoke ${out[bad, ${_stat}, int, ${Me.${_stat}}]}
			} else {
				/invoke ${out[good, ${_stat}]}
			}
		/next _count




	| Me.CurrentWeight
		/if (!${Range.Between[1,99999:${Me.CurrentWeight}]}) {
			/invoke ${out[bad, CurrentWeight, int, ${Me.CurrentWeight}]}
		} else {
			/invoke ${out[good, CurrentWeight]}
		}

	| Me.Name





	| Me.Origin

	| Me.SubscriptionDays




	| Me.Subscription
		/if (!${Select[${Me.Subscription},FREE,SILVER,GOLD]}) {
			/invoke ${out[bad, Subscription, "string (FREE|SILVER|GOLD)", ${Me.Subscription}]}
		} else {
			/invoke ${out[good, Subscription]}
		}



	| Me.Exp
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
		}AAVitality

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
	| Me.MaxMana
	| Me.PctMana
		/if (!${Range.Between[0,100:${Me.PctMana}]}) {
			/invoke ${out[bad, PctMana, int, ${Me.PctMana}]}
		} else {
			/invoke ${out[good, PctMana]}
		}

	| Me.CountBuffs
	| Me.CountSongs
	| Me.BlockedPetBuff

	| Me.BlockedBuff

	| Me.Buff

	| Me.Song
	| Me.HPBonus
	| Me.ManaBonus
	| Me.CombatEffectsBonus
	| Me.ShieldingBonus
	| Me.SpellShieldBonus
	| Me.AvoidanceBonus
	| Me.AccuracyBonus
	| Me.StunResistBonus

	| Me.StrikeThroughBonus
	| Me.DoTShieldBonus
	| Me.AttackBonus
	| Me.HPRegenBonus

	| Me.ManaRegenBonus
	| Me.DamageShieldBonus

	| Me.DamageShieldMitigationBonus

	| Me.HeroicSTRBonus

	| Me.HealAmountBonus
	| Me.SpellDamageBonus
	| Me.ClairvoyanceBonus
	| Me.EnduranceRegenBonus
	| Me.AttackSpeed
	| Me.CurrentEndurance
	| Me.MaxEndurance
	| Me.PctEndurance



	| Me.GukEarned
	| Me.MMEarned
	| Me.RujEarned
	| Me.TakEarned
	| Me.MirEarned
	| Me.LDoNPoints
	| Me.CurrentFavor
	| Me.CareerFavor


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
			/varset _stat ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[0,999999999999:${Me.${_stat}}]}) {
				/invoke ${out[bad, ${_stat}, int, ${Me.${_stat}}]}
			} else {
				/invoke ${out[good, ${_stat}]}
			}
		/next _count



	| CashBank, PlatinumBank, GoldBank, CursorSilver, CopperBank
		/varset _MemberList |CashBank|PlatinumBank|GoldBank|SilverBank|CopperBank
		/for _count 1 to ${_MemberList.Count[|]}
			/varset _stat ${_MemberList.Arg[${_count},|]}

			/if (!${Range.Between[0,999999999999:${Me.${_stat}}]}) {
				/invoke ${out[bad, ${_stat}, int, ${Me.${_stat}}]}
			} else {
				/invoke ${out[good, ${_stat}]}
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
		/declare _altCurrency[6]
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

	| Me.HPRegen

	| Me.ManaRegen

	| Me.EnduranceRegen

	| Me.Grouped
	| Me.GroupList


	| Me.AmIGroupLeader
	| Me.MaxBuffSlots
	| Me.FreeBuffSlots

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
		/declare _language[3]
		/varset _language[1] |Common Tongue|Barbarian|Erudian|Elvish|Dwarvish|Troll|Ogre|Gnomish|Halfling|Theves Cant|Old Erudian
		/varset _language[2] |Elder Elvish|Froglock|Goblin|Gnoll|Combine Tongue|Elder Teir'Dal|Lizardman|Orcish|Faerie|Dragon
		/varset _language[3] |Elder Dragon|Dark Speech|Vah Shir|Alarian|Hadal





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
	| Me.Thirst

	| Me.Drunk
		/if (!${Range.Between[0,100:${Me.Drunk}]}) {
			/invoke ${out[bad, Drunk, int, ${Me.Drunk}]}
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
			/varset _stat ${_MemberList.Arg[${_count},|]}
			/if (!${Range.Between[1,99999:${Me.${_stat}[alcohol tolerance]}]}) {
				/invoke ${out[bad, ${_stat}[alcohol tolerance], int, ${Me.${_stat}[alcohol tolerance]}]}
			} else {
				/invoke ${out[good, ${_stat}[alcohol tolerance]]}
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




	| Me.GroupSize





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

	| Me.TotalCounters
	| Me.CountersDisease
	| Me.CountersPoison
	| Me.CountersCurse
	| Me.CountersCorruption


	| Me.Mercenary
	| Me.MercenaryStance
	| Me.PctMercAAExp
	| Me.MercAAExp
	| Me.MercAAPoints
	| Me.MercAAPointsSpent



	| Me.XTargetSlots
	| Me.XTAggroCount
	| Me.XTHaterCount
	| Me.XTarget

	| Me.Haste


	| Me.SPA



	| Me.GemTimer

	| Me.HaveExpansion


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
	| Me.Zoning



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
	| Me.Diseased
	| Me.Poisoned
	| Me.Cursed
	| Me.Corrupted
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
	| Me.MercListInfo
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











