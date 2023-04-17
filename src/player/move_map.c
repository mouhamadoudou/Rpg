/*
** EPITECH PROJECT, 2022
** move_map.c
** File description:
** move_map
*/

#include "my_rpg.h"

static void loop_movex_texture(map_t **all_texture, int increment)
{
    for (int i = 0; all_texture[i] != NULL; i++)
        for (int j = 0; all_texture[i][j].texture != NULL; j++)
            all_texture[i][j].pos.x += increment;
    return;
}

static void loop_movey_texture(map_t **all_texture, int increment)
{
    for (int i = 0; all_texture[i] != NULL; i++)
        for (int j = 0; all_texture[i][j].texture != NULL; j++)
            all_texture[i][j].pos.y += increment;
    return;
}

void move_pos_map_x(map_t **all_texture, bot_t **mob_in_map, npc_t *all_pnj,
                    int increment)
{
    all_texture[0][0].time = sfClock_getElapsedTime(all_texture[0][0].clock);
    all_texture[0][0].sec = all_texture[0][0].time.microseconds / 1000000.0;
    if (all_texture[0][0].sec > 0.01) {
        loop_movex_texture(all_texture, increment);
        for (int i = 0; all_pnj[i].name != NULL; i++)
            all_pnj[i].texture->cord.x += increment;
        for (int i = 0; i < NB_MOB_ON_MAP; ++i) {
            mob_in_map[i]->texture->cord.x += increment;
        }
    }
    return;
}

void move_pos_map_y(map_t **all_texture, bot_t **mob_in_map, npc_t *all_pnj,
                    int increment)
{
    all_texture[0][0].time = sfClock_getElapsedTime(all_texture[0][0].clock);
    all_texture[0][0].sec = all_texture[0][0].time.microseconds / 1000000.0;
    if (all_texture[0][0].sec > 0.01) {
        loop_movey_texture(all_texture, increment);
        for (int i = 0; all_pnj[i].name != NULL; i++)
            all_pnj[i].texture->cord.y += increment;
        for (int i = 0; i < NB_MOB_ON_MAP; ++i) {
            mob_in_map[i]->texture->cord.y += increment;
        }
    }
    return;
}