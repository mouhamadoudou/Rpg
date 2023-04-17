/*
** EPITECH PROJECT, 2022
** create_bar.c
** File description:
** create_bar
*/

#include <stdlib.h>
#include "my_rpg.h"

static void get_life_bar(sfSprite **array_bar, sfTexture *black,
                        sfTexture *texture)
{
    sfSprite_setTexture(array_bar[0], texture, sfTrue);
    sfSprite_setPosition(array_bar[0], (sfVector2f) { 600, 950 });
    sfSprite_setTextureRect(array_bar[0], (sfIntRect) { .left = 0, .top = 0,
                            .width = 600, .height = 20 });
    sfSprite_setTexture(array_bar[1], black, sfTrue);
    sfSprite_setPosition(array_bar[1], (sfVector2f) { 595, 945 });
    sfSprite_setTextureRect(array_bar[1], (sfIntRect) { .left = 0, .top = 0,
                            .width = 610, .height = 30 });
    return;
}

static void get_mana_bar(sfSprite **array_bar, sfTexture *black,
                        sfTexture *texture)
{
    sfSprite_setTexture(array_bar[0], texture, sfTrue);
    sfSprite_setPosition(array_bar[0], (sfVector2f) { 720, 920 });
    sfSprite_setTextureRect(array_bar[0], (sfIntRect) { .left = 0, .top = 0,
                            .width = 400, .height = 7 });
    sfSprite_setTexture(array_bar[1], black, sfTrue);
    sfSprite_setPosition(array_bar[1], (sfVector2f) { 717, 917 });
    sfSprite_setTextureRect(array_bar[1], (sfIntRect) { .left = 0, .top = 0,
                            .width = 406, .height = 13 });
    return;
}

sfSprite **create_bar(int chose, char *filepath)
{
    sfSprite **array_bar = malloc(sizeof(sfSprite *) * 2);
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfTexture *black = sfTexture_createFromFile("assets/black.png", NULL);

    array_bar[0] = sfSprite_create();
    array_bar[1] = sfSprite_create();
    if (chose == 1)
        get_life_bar(array_bar, black, texture);
    else
        get_mana_bar(array_bar, black, texture);
    return array_bar;
}
