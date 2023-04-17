/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display mob
*/
#include "mob.h"

void display_mob(bot_t **mob_in_map, sfRenderWindow *window)
{
    /*for (int i = 0; mob_in_map[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window, mob_in_map[i]->texture->sprite, NULL);
        sfSprite_setPosition(mob_in_map[i]->texture->sprite, mob_in_map[i]->texture->cord);
    }*/
    sfSprite_setPosition(mob_in_map[0]->texture->sprite, mob_in_map[0]->texture->cord);
    sfRenderWindow_drawSprite(window, mob_in_map[0]->texture->sprite, NULL);
    return;
}
