/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header for spell, in particular spell related macro
*/

#pragma once

#include "game_element.h"
#define ID (0)
#define REGEN_HP (1)
#define REGEN_MP (2)
#define HEAL (3)
#define LUCK (5)
#define SPEED (6)
#define RESISTANCE (8)
#define ATTACK (9)
#define HEAL_MANA (10)
#define POURCENT_ATTACK (11)
#define MANA_COST (12)
#define CD (13)
#define NAME (14)
#define DESC (15)

spell_t *create_spell(char **spell_data);
spell_t **create_list_spell(void);
