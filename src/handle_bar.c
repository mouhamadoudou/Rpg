/*
** EPITECH PROJECT, 2022
** handle_bar.c
** File description:
** handle_bar
*/

#include <stdlib.h>
#include "my_rpg.h"

void compute_bar(player_t *player, sfSprite **bar, int chose)
{
    int percent_mana;
    int percent_life;
    int percent_bar;

    if (chose == 1) {
        percent_life = (player->current_life * 100) / player->stat.hp;
        percent_bar = (600 * percent_life) / 100;
        sfSprite_setTextureRect(bar[0], (sfIntRect) { .left = 0, .top = 0,
                                .width = percent_bar, .height = 20 });
    } else {
        percent_mana = (player->current_mana * 100) / player->stat.mana;
        percent_bar = (400 * percent_mana) / 100;
        sfSprite_setTextureRect(bar[0], (sfIntRect) { .left = 0, .top = 0,
                                .width = percent_bar, .height = 7 });
    }
}

void display_bar(sfSprite **mana_bar, sfSprite **life_bar,
                sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, life_bar[1], NULL);
    sfRenderWindow_drawSprite(window, life_bar[0], NULL);
    sfRenderWindow_drawSprite(window, mana_bar[1], NULL);
    sfRenderWindow_drawSprite(window, mana_bar[0], NULL);
    return;
}

void free_bar(sfSprite **mana_bar, sfSprite **life_bar)
{
    for (int i = 0; i < 2; i++) {
        sfTexture_destroy(sfSprite_getTexture(mana_bar[i]));
        sfSprite_destroy(mana_bar[i]);
        sfTexture_destroy(sfSprite_getTexture(life_bar[i]));
        sfSprite_destroy(life_bar[i]);
    }
    return;
}
