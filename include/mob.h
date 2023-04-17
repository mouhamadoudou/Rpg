/*
** EPITECH PROJECT, 2022
** MY_RPG
** File description:
** header related to mob
*/

#pragma once

#include "game_element.h"
#include "rpg_macro.h"
#define NB_STAT (10)
#define MOB_ID (0)
#define MOB_STAT (1)
#define MOB_REGEN_HP (1)
#define MOB_REGEN_MP (2)
#define MOB_HEAL (3)
#define MOB_MANA (4)
#define MOB_LUCK (5)
#define MOB_SPEED (6)
#define MOB_HP (7)
#define MOB_RES (8)
#define MOB_ATTACK (9)
#define MOB_HEAL_MANA (10)
#define MOB_SPELL (11)
#define MOB_LVL_MAX_VAL (16)
#define MOB_EXP (17)
#define MOB_DROP (18)
#define DROP_RATE (23)
#define DROP_NB (32)

typedef struct fun_set_stat_s {
    int stat;
    void (*fun_ptr) (bot_t *);
} fun_set_stat_t;

bot_t **create_list_mob(game_elem_t *game_elem);
bot_t *create_mob(char **mob_data, game_elem_t *game_elem);
bot_t *create_in_game_mob(char **mob_info, bot_t **mob_list);

spell_t *find_mob_spell(char *spell_id, spell_t **spell_list);

int get_stat_to_set(int i, bot_t *mob);
void set_speed(bot_t *mob);
void set_hp(bot_t *mob);
void set_resistance(bot_t *mob);
void set_attack(bot_t *mob);

int call_function_item_mob(char **mob_info, bot_t *mob, item_t **list_item);

int *find_mob_current_tile(sfVector2f *mop_pos, map_t **all_texture);

void display_mob(bot_t **mob_in_map, sfRenderWindow *window);

void wait_attack_mob(clock_elem_t *c_elem);
int attack_player_mob(int mob_pos, game_elem_t *elem_game);
