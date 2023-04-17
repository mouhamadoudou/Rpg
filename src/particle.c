/*
** EPITECH PROJECT, 2022
** particle.c
** File description:
** particle
*/

#include "my_rpg.h"

void snow(int test, sfCircleShape *circle, sfVector2f position,
        window_elem_t *elem_win)
{
    if (sfKeyboard_isKeyPressed(sfKeyP))
        test = 0;
    if (sfKeyboard_isKeyPressed(sfKeyM))
        test = 1;
    if (test != 0) {
        for (int i = 0; i < 80000; i += 10) {
            position.x = rand() % 2000;
            position.y = rand() % 1100;
            sfCircleShape_setPosition (circle, position);
            sfRenderWindow_drawCircleShape(elem_win->window, circle, NULL);
        }
    }
    return;
}