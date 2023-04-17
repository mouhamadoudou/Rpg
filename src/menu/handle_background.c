/*
** EPITECH PROJECT, 2022
** handle_background.c
** File description:
** handle_background
*/

#include "my_rpg.h"
#include "my.h"
#include "rpg_macro.h"
#include "my_rpg_map.h"

void get_good_move(map_t **bg, int *x, int *y)
{
    int col = get_col_map(bg[0]);
    int row = my_arraylen(bg);

    bg[0][0].time = sfClock_getElapsedTime(bg[0][0].clock);
    bg[0][0].sec = bg[0][0].time.microseconds / 1000000.0;
    if (bg[0][col - 1].pos.x > 1700 && bg[0][0].pos.y >= 0) {
        *x = -2;
        return;
    } else if (bg[row - 1][0].pos.y > 1000 && bg[0][col - 1].pos.x <= 1700) {
        *y = -2;
        return;
    } if (bg[row - 1][0].pos.x < 0) {
        *x = 2;
        return;
    } else if (bg[0][0].pos.y < 0)
        *y = 2;
    return;
}

void move_background(map_t **background)
{
    int x = 0;
    int y = 0;

    get_good_move(background, &x, &y);
    for (int i = 0; background[i] != NULL && background[0][0].sec > 0.01; i++) {
        for (int j = 0; background[i][j].texture != NULL; j++) {
            background[i][j].pos.x += x;
            background[i][j].pos.y += y;
        }
    }
    if (background[0][0].sec > 0.01) {
        sfClock_restart(background[0][0].clock);
        background[0][0].sec = 0.00;
    }
    return;
}
