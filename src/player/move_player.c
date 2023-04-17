/*
** EPITECH PROJECT, 2022
** move_player.c
** File description:
** move_player
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "rpg_macro.h"
#include "my.h"

int my_strlen_map(map_t *texture)
{
    int i = 0;

    while (texture[i].texture != NULL)
        i++;
    return i;
}

bool check_around(map_t **all_texture, int dir, int *index, npc_t *all_pnj)
{
    int i = index[0];
    int j = index[1];
    int nb_line = my_arraylen(all_texture);
    int nb_col = my_strlen_map(all_texture[i]);

    if (dir == 0 && i > 0 && all_texture[i - 1][j].is_block &&
        all_texture[i - 1][j].pos.y <= 600)
        return true;
    else if (dir == 1 && i < nb_line - 1 && all_texture[i + 1][j].is_block &&
            all_texture[i + 1][j].pos.y <= 620)
        return true;
    if (dir == 2 && j > 0 && all_texture[i][j - 1].is_block &&
        all_texture[i][j - 1].pos.x >= 770)
        return true;
    else if (dir == 3 && j < nb_col - 1 && all_texture[i][j + 1].is_block &&
            all_texture[i][j + 1].pos.x <= 930)
        return true;
    return check_pnj_around(all_pnj, dir);
}

void init_clock_anim(map_t **all_texture)
{
    if (all_texture[0][0].sec > 0.01) {
        sfClock_restart(all_texture[0][0].clock);
        all_texture[0][0].sec = 0.00;
    }
    return;
}

void move_player(map_t **all_texture, bot_t **mob_in_map, npc_t *all_pnj)
{
    int nb_raw = all_texture[0][0].last_line - 1;
    int nb_col = all_texture[0][0].last_col - 1;
    int *pos_current = malloc(sizeof(int) * 2);

    pos_current = find_current_tile(all_texture);
    if (LEFT && all_texture[0][0].pos.x <= 850 &&
        !(check_around(all_texture, 2, pos_current, all_pnj))) {
        move_pos_map_x(all_texture, mob_in_map, all_pnj, 6);
    } else if (RIGHT && all_texture[nb_raw][nb_col].pos.x >= 840 &&
            !(check_around(all_texture, 3, pos_current, all_pnj)))
        move_pos_map_x(all_texture, mob_in_map, all_pnj, -6);
    if (UP && all_texture[0][0].pos.y <= 530 &&
        !(check_around(all_texture, 0, pos_current, all_pnj))) {
        move_pos_map_y(all_texture, mob_in_map, all_pnj, 6);
    } else if (DOWN && all_texture[nb_raw][0].pos.y >= 535 &&
            !(check_around(all_texture, 1, pos_current, all_pnj)))
        move_pos_map_y(all_texture, mob_in_map, all_pnj, -6);
    init_clock_anim(all_texture);
    free(pos_current);
}
