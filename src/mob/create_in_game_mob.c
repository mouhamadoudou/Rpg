/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create a mob for in game application
*/
#include <stdlib.h>
#include "game_element.h"
#include "mob.h"
#include "my.h"

static int generate_level_mob(char *mob_max_lvl)
{
    int res;
    int *tmp = malloc(sizeof(int));

    if (tmp == NULL)
        return (-1);
    srand((__intptr_t)tmp);
    res = my_getnbr(mob_max_lvl);
    res = rand() % res;
    return (res);
}

static int find_mob_in_list(char *mob_name, bot_t **mob_list)
{
    int i = 0;

    while (my_strcmp(mob_name, mob_list[i]->name) != 0) {
        ++i;
    }
    return (i);
}

static void set_mob_stat_with_level(bot_t *mob)
{
    int i = 0;

    while (i < NB_STAT) {
        get_stat_to_set(i, mob);
        ++i;
    }
}

int create_mob_texture(int id, sfVector2f *pos, sfIntRect *rect, bot_t *mob)
{
    sfIntRect *cut_rect = malloc(sizeof(sfIntRect));

    if (cut_rect == NULL)
        return (-1);
    cut_rect->width = 31;
    cut_rect->height = 45;
    cut_rect->left = 0;
    cut_rect->top = 0;
    mob->texture->texture = sfTexture_createFromFile("./assets/blue.png",
                                                    cut_rect);
    mob->texture->sprite = sfSprite_create();
    mob->texture->rect = *rect;
    mob->texture->cord = *pos;
    sfSprite_setPosition(mob->texture->sprite, mob->texture->cord);
    sfSprite_setTexture(mob->texture->sprite, mob->texture->texture, sfTrue);
    sfSprite_setTextureRect(mob->texture->sprite, mob->texture->rect);
    //sfSprite_setScale(mob->texture->sprite, (sfVector2f) { 2, 2 });
    free(cut_rect);
    return (0);
}

bot_t *create_in_game_mob(char **mob_info, bot_t **mob_list)
{
    int pos = 0;
    bot_t *mob = malloc(sizeof(bot_t) * 1);

    if (mob == NULL)
        return (NULL);
    pos = find_mob_in_list(mob_info[MOB_ID], mob_list);
    *mob = *mob_list[pos];
    mob->level = generate_level_mob(mob_info[MOB_LVL_MAX_VAL]);
    if (mob->level == -1)
        return (NULL);
    if (mob->level == 1)
        return (mob);
    set_mob_stat_with_level(mob);
    mob->texture = malloc(sizeof(game_object_t) * 1);
    if (mob->texture == NULL)
        return (NULL);
    create_mob_texture(1, &(sfVector2f){ 1300, 600 }, &(sfIntRect){ 0, 0, 20, 20 }, mob);
    return (mob);
}
