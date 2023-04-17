/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free a mob struct
*/
#include <stdlib.h>
#include "game_element.h"
#include "rpg_free.h"

void free_mob_struct(bot_t *mob)
{
    int i = 0;

    free(mob->name);
    while (i < 5 && mob->spell[i] != NULL) {
        free(mob->spell[i]);
        ++i;
    }
    i = 0;
    while (i < 5 && mob->list_drop[i] != NULL) {
        free(mob->list_drop[i]);
        ++i;
    }
    free_game_object_t(mob->texture);
    free(mob->texture);
}

void free_list_all_mob_and_in_map(game_elem_t *elem_game)
{
    int i = 0;

    while (elem_game->list_mob[i] != NULL) {
        free_mob_struct(elem_game->list_mob[i]);
        free(elem_game->list_mob[i]);
        ++i;
    }
    i = 0;
    while (i < NB_MOB_ON_MAP) {
        free_mob_struct(elem_game->mob_in_map[i]);
        free(elem_game->mob_in_map[i]);
        ++i;
    }
}
