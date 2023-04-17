/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free game_object_t
*/
#include <stdlib.h>
#include "game_element.h"

void free_game_object_t(game_object_t *object)
{
    sfSprite_destroy(object->sprite);
    sfTexture_destroy(object->texture);
}
