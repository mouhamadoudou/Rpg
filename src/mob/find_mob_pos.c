/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** find the pos of a mob on the map
*/
#include <stdlib.h>
#include "rpg_struct.h"

static int good_tile_mob(int *res, cycle_counter_t *i_j, sfVector2f *mob_pos,
                        map_t **all_texture)
{
    if (all_texture[i_j->i][i_j->j].pos.y >= mob_pos->y - 200 &&
        all_texture[i_j->i][i_j->j].pos.y <= mob_pos->y + 200) {
        if (all_texture[i_j->i][i_j->j].pos.x >= mob_pos->x - 200 &&
            all_texture[i_j->i][i_j->j].pos.x <= mob_pos->x + 200) {
            res[0] = i_j->i;
            res[1] = i_j->j;
            return 1;
        }
    }
    return 0;
}

int *find_mob_current_tile(sfVector2f *mop_pos, map_t **all_texture)
{
    int *res = malloc(sizeof(int) * 2);
    int passed = 0;
    cycle_counter_t i_j = { 0 };

    while (all_texture[i_j.i] != NULL && passed == 0) {
        while (all_texture[i_j.i][i_j.j].texture != NULL && passed == 0) {
            passed = good_tile_mob(res, &i_j, mop_pos, all_texture);
            ++i_j.j;
        }
        i_j.j = 0;
        ++i_j.i;
    }
    if (passed == 1)
        return res;
    free(res);
    return NULL;
}
