/*
** EPITECH PROJECT, 2022
** manage_text.c
** File description:
** manage_text
*/

#include "my_rpg.h"

void display_text(sfRenderWindow *window, sfText **all_text, int nb)
{
    for (int i = 0; i < nb; i++)
        sfRenderWindow_drawText(window, all_text[i], NULL);
    return;
}

sfText *create_text(char *str, sfColor *color, int scale, sfVector2f *pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/font/gameplay.ttf");

    sfText_setString(text, str);
    sfText_setPosition(text, *pos);
    sfText_setCharacterSize(text, scale);
    sfText_setColor(text, *color);
    sfText_setFont(text, font);
    return text;
}

void display_text_skin(sfText **text, int nb_text, sfRenderWindow *window)
{
    for (int i = 0; i < nb_text; i++)
        sfRenderWindow_drawText(window, text[i], NULL);
}
