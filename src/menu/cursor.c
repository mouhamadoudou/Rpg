/*
** EPITECH PROJECT, 2022
** cursor.c
** File description:
** cursor
*/

#include "my_rpg.h"

void handle_move_cursor(int *can_move_cursor, int *choice_skin, 
                        sfSprite *cursor)
{
    if (*can_move_cursor == 1)
        move_cursor(choice_skin, cursor, can_move_cursor);
    if ((sfKeyboard_isKeyPressed(sfKeyLeft) || 
        sfKeyboard_isKeyPressed(sfKeyRight)) && *can_move_cursor == 0)
        *can_move_cursor = 1;
    else if (!(sfKeyboard_isKeyPressed(sfKeyLeft)) && 
            !(sfKeyboard_isKeyPressed(sfKeyRight)))
        *can_move_cursor = 0;
    return;
}

sfSprite *set_cursor(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/cursor.png", NULL);
    sfVector2f pos = { 632, 470 };

    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f) { 0.1, 0.1 });
    return sprite;
}

void move_cursor(int *skin, sfSprite *cursor, int *can_move_cursor)
{
    sfVector2f pos;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) && *skin > 1) {
        *skin -= 1;
        pos = sfSprite_getPosition(cursor);
        pos.x -= 250;
        sfSprite_setPosition(cursor, pos);
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && *skin < 3) {
        *skin += 1;
        pos = sfSprite_getPosition(cursor);
        pos.x += 250;
        sfSprite_setPosition(cursor, pos);
    }
    *can_move_cursor = -1;
    return;
}

void loop_cursor(int *can_move_cursor, int *choice_skin, sfSprite *cursor,
            program_elem_t *all_elem)
{
    handle_move_cursor(can_move_cursor, choice_skin, cursor);
    sfRenderWindow_drawSprite(all_elem->elem_win->window, cursor, NULL);
    return;
}
