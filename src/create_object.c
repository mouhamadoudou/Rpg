/*
** EPITECH PROJECT, 2022
** create_object.c
** File description:
** create_object
*/

#include <stdlib.h>
#include "my_rpg.h"

static bool if_obstacle(int id)
{
    int id_block[20] = { 0, 4, 7, 8, 12, 13, 15, 16, 19, 20, 23, 27, 28, 29,
                        30, 31, 32, 33, 34, -1 };

    for (int i = 0; id_block[i] != -1; i++) {
        if (id == id_block[i])
            return true;
    }
    return false;
}

int create_texture(int id, sfVector2f *pos, sfIntRect *rect, map_t *object)
{
    sfIntRect *cut_rect = malloc(sizeof(sfIntRect));
    
    if (cut_rect == NULL)
        return (-1);
    cut_rect->width = 64;
    cut_rect->height = 64;
    cut_rect->left = id * 64;
    cut_rect->top = 0;
    object->texture = sfTexture_createFromFile("./assets/ground_texture.png",
                                            cut_rect);
    object->sprite = sfSprite_create();
    object->rect = *rect;
    object->pos = *pos;
    object->is_block = if_obstacle(id);
    sfSprite_setPosition(object->sprite, object->pos);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->rect);
    free(cut_rect);
    return (0);
}

int create_pnj(int id, sfVector2f *pos, sfIntRect *rect, npc_t *object)
{
    sfIntRect *cut_rect = malloc(sizeof(sfIntRect));

    if (cut_rect == NULL)
        return (-1);
    cut_rect->width = 31;
    cut_rect->height = 45;
    cut_rect->left = id * 31;
    cut_rect->top = 0;
    object->texture->texture = sfTexture_createFromFile("./assets/pnj.png",
                                                        cut_rect);
    object->texture->sprite = sfSprite_create();
    object->texture->rect = *rect;
    object->texture->cord = *pos;
    sfSprite_setPosition(object->texture->sprite, object->texture->cord);
    sfSprite_setTexture(object->texture->sprite, object->texture->texture,
                        sfTrue);
    sfSprite_setTextureRect(object->texture->sprite, object->texture->rect);
    sfSprite_setScale(object->texture->sprite, (sfVector2f) { 2, 2 });
    free(cut_rect);
    return (0);
}
