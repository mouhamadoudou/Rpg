/*
** EPITECH PROJECT, 2022
** free_menu.c
** File description:
** free_menu
*/

#include <stdlib.h>
#include "my_rpg.h"

void free_text_tuto(bool active_menu, sfText **content, int nb_text)
{
    if (!(active_menu)) {
        for (int i = 0; i < nb_text; i++) {
            sfFont_destroy(sfText_getFont(content[i]));
            sfText_destroy(content[i]);
        }
        free(content);
    }
}

void free_main_menu(char **map, button_t *all_btn, sfSprite *opa, sfText *logo)
{
    free_array(map);
    for (int i = 0; i < 4; i++) {
        sfFont_destroy(sfText_getFont(all_btn[i].content));
        sfText_destroy(all_btn[i].content);
    }
    sfTexture_destroy(sfSprite_getTexture(opa));
    sfSprite_destroy(opa);
    sfFont_destroy(sfText_getFont(logo));
    sfText_destroy(logo);
    return;
}

void free_settings(sfSprite *opacity, sfSprite *cursor, sfSprite **sound,
                sfText **text)
{
    sfTexture_destroy(sfSprite_getTexture(opacity));
    sfSprite_destroy(opacity);
    sfTexture_destroy(sfSprite_getTexture(cursor));
    sfSprite_destroy(cursor);
    for (int i = 0; i < 2; i++) {
        sfTexture_destroy(sfSprite_getTexture(sound[i]));
        sfSprite_destroy(sound[i]);
    }
    for (int i = 0; i < 4; i++) {
        sfFont_destroy(sfText_getFont(text[i]));
        sfText_destroy(text[i]);
    }
    free(text);
    free(sound);
    return;
}
