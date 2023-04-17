/*
** EPITECH PROJECT, 2022
** free.c
** File description:
** free
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_all(sfText **text, player_t **skin, sfSprite *opa, sfSprite *cur)
{
    for (int i = 0; i < 4; i++) {
        sfFont_destroy(sfText_getFont(text[i]));
        sfText_destroy(text[i]);
    }
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(sfSprite_getTexture(skin[i]->player.sprite));
        sfSprite_destroy(skin[i]->player.sprite);
        free(skin[i]);
    }
    sfTexture_destroy(sfSprite_getTexture(opa));
    sfSprite_destroy(opa);
    sfTexture_destroy(sfSprite_getTexture(cur));
    sfSprite_destroy(cur);
    return;
}

void free_pause_menu(sfSprite *opacity, sfText *pause_txt, button_t *btn)
{
    sfTexture_destroy(sfSprite_getTexture(opacity));
    sfSprite_destroy(opacity);
    sfFont_destroy(sfText_getFont(pause_txt));
    sfText_destroy(pause_txt);
    for (int i = 0; i < 2; i++) {
        sfFont_destroy(sfText_getFont(btn[i].content));
        sfText_destroy(btn[i].content);
    }
    free(btn);
    return;
}

void free_map(map_t **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j].texture != NULL; j++) {
            sfTexture_destroy(sfSprite_getTexture(map[i][j].sprite));
            sfSprite_destroy(map[i][j].sprite);
        }
        free(map[i]);
    }
    free(map);
    return;
}

void free_pnj(npc_t *pnj)
{
    for (int i = 0; pnj[i].name != NULL; i++) {
        sfTexture_destroy(sfSprite_getTexture(pnj[i].texture->sprite));
        sfSprite_destroy(pnj[i].texture->sprite);
    }
    free(pnj);
    return;
}

void free_array(void *array)
{
    void **v_array = (void **)array;

    for (int i = 0; v_array[i] != NULL; i++) {
        free(v_array[i]);
    }
    return;
}

void free_3_array(void *array)
{
    void ***v_array = (void ***)array;

    for (int i = 0; v_array[i] != NULL; ++i) {
        free_array(v_array[i]);
    }
}
