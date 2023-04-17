/*
** EPITECH PROJECT, 2022
** game_element.h
** File description:
** game_element
*/

#pragma once
#include <SFML/Graphics.h>
#include "rpg_struct.h"

typedef struct stat_s {
    int regen_hp;
    int regen_mp;
    int heal;
    int mana;
    int luck;
    int speed;
    int hp;
    int resistance;
    int attack;
    int heal_mana;
} stat_t;

typedef struct effect_s {
    int dot;
    bool stun;
    bool silence;
} effect_t;

typedef struct item_s {
    sfText *name;
    sfText *description;
    char *id;
    stat_t effect;
    int value;
} item_t;

typedef struct inventory_s {
    item_t list[30];
} inventory_t;

typedef struct item_bar_s {
    item_t list[4];
} item_bar_t;

typedef struct equip_item_s {
    item_t list[6];
} equip_item_t;

typedef struct spell_s {
    char *id;
    sfClock *clock;
    sfTime time;
    float sec;
    stat_t stat;
    int pourcent_attack;
    int mana;
    int cd;
    sfText *name;
    sfText *description;
} spell_t;

typedef struct player_s {
    stat_t stat;
    spell_t spell;
    int current_life;
    int current_mana;
    int level;
    int exp;
    int stat_point;
    game_object_t player;
    inventory_t inventory;
    item_bar_t item_bar;
    equip_item_t equip_item;
    animation_t anim;
    bool in_dialog;
    int skin;
    sfSprite **life_bar;
    sfSprite **mana_bar;
} player_t;

typedef struct bot_s {
    char *name;
    int level;
    int current_life;
    int exp_given;
    stat_t stat;
    spell_t *spell[5];
    item_t *list_drop[5];
    sfVector2i drop_rate[5];
    int max_nb_drop[5];
    sfVector2f to_move[2];
    game_object_t *texture;
} bot_t;

typedef struct npc_s {
    char *name;
    int active_dialog;
    int id_texture;
    game_object_t *texture;
    sfVector2i *pos_to_speak;
} npc_t;

typedef struct dialog_s {
    int npc_nb;
    bool go_next_dialog;
    int nb_dialog;
    int *caracter_dialog;
    int displayed_dialog;
    sfText **names;
    sfText ***dialog_text;
    int nb_char_to_display;
} dialog_t;

typedef struct game_elem_s {
    player_t *player;
    npc_t *list_npc;
    dialog_t *dialog_elem;
    int *move_mob;
    bot_t **mob_in_map;
    item_t **list_item;
    spell_t **list_spell;
    bot_t **list_mob;
    char ***mob_data;
} game_elem_t;

typedef struct sub_thread_data_s {
    bool stop_thread;
    bool need_move[NB_MOB_ON_MAP];
    sfVector2i *list_cell[NB_MOB_ON_MAP];
    sfVector2f *pos_mob_player[NB_MOB_ON_MAP];
    bot_t **mob_in_map;
} sub_thread_data_t;

typedef struct thread_data_s {
    bool stop_thread;
    sfVector2i prev_dest[NB_MOB_ON_MAP];
    sfThread *sub_thread;
    sub_thread_data_t *sub_thread_data;
} thread_data_t;

typedef struct program_elem_s {
    window_elem_t *elem_win;
    game_elem_t *elem_game;
    thread_data_t *t_data;
} program_elem_t;

typedef struct button_s {
    sfVector2f pos;
    sfText *content;
    int (*pt_fct)(map_t **bg, sfText *logo_game, program_elem_t *all_elem);
    bool hover;
}button_t;

