/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header related to item, particularly macro
*/

#pragma once

#include "game_element.h"
#define ITEM_ID (0)
#define ITEM_NAME (1)
#define ITEM_DESC (2)
#define ITEM_REGEN_HP (3)
#define ITEM_REGEN_MP (4)
#define ITEM_MANA (6)
#define ITEM_LUCK (7)
#define ITEM_SPEED (8)
#define ITEM_HP (9)
#define ITEM_RESISTANCE (10)
#define ITEM_ATTACK (11)
#define ITEM_VALUE (13)

item_t *create_item(char **item_data);
item_t **create_list_item(void);
