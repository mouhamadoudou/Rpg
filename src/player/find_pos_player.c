/*
** EPITECH PROJECT, 2022
** find_pos_player.c
** File description:
** find_pos_player
*/

#include <stdlib.h>
#include "my_rpg.h"

int good_tile(int *res, map_t **all_texture, int i, int j)
{
    if (all_texture[i][j].pos.y >= 500 && all_texture[i][j].pos.y <= 600) {
        if (all_texture[i][j].pos.x >= 800 && all_texture[i][j].pos.x <= 900) {
            res[0] = i;
            res[1] = j;
            return 1;
        }
    }
    return 0;
}

int *find_current_tile(map_t **all_texture)
{
    int *res = malloc(sizeof(int) * 2);
    int passed = 0;

    for (int i = 0; all_texture[i] != NULL && passed == 0; i++) {
        for (int j = 0; all_texture[i][j].texture != NULL && passed == 0; j++) {
            passed = good_tile(res, all_texture, i, j);
        }
    }
    if (passed == 1)
        return res;
    free(res);
    return NULL;
}
