/*
** EPITECH PROJECT, 2022
** display_map.c
** File description:
** display_map
*/

#include "my_rpg.h"

static void display_current_texture(sfRenderWindow *window, map_t **tab_obj,
                                    int i, int j)
{
    if (WINDOW_R && WINDOW_L && WINDOW_D && WINDOW_T) {
        sfSprite_setScale(tab_obj[i][j].sprite, (sfVector2f) { 1.5, 1.5 });
        sfRenderWindow_drawSprite(window, tab_obj[i][j].sprite, NULL);
        sfSprite_setPosition(tab_obj[i][j].sprite, tab_obj[i][j].pos);
    }
    return;
}

void display_texture(map_t **tab_obj, sfRenderWindow *window)
{
    for (int i = 0; tab_obj[i] != NULL; i++) {
        for (int j = 0; tab_obj[i][j].texture != NULL; j++) {
            display_current_texture(window, tab_obj, i, j);
        }
    }
}
