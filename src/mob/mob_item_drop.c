/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function related to mob item and their drop rate
*/
#include "game_element.h"
#include "mob.h"
#include "my.h"

static item_t *find_mob_item(char *item_id, item_t **item_list)
{
    int i = 0;

    while (my_strcmp(item_id, item_list[i]->id) != 0) {
        ++i;
    }
    return (item_list[i]);
}

static int assign_item_mob(char **mob_info, bot_t *mob, item_t **list_item)
{
    int nb_item = 0;

    while (nb_item < 5 && my_strcmp(mob_info[MOB_DROP + nb_item], "NA")
        != 0) {
        mob->list_drop[nb_item] = find_mob_item(mob_info[MOB_DROP + nb_item],
                                                list_item);
        ++nb_item;
    }
    if (nb_item != 5)
        mob->list_drop[nb_item] = NULL;
    return (0);
}

static void assign_drop_rate_item(char **mob_info, bot_t *mob)
{
    int item_nb = 0;

    while (item_nb < 5 &&
        my_strcmp(mob_info[DROP_RATE + item_nb], "NA") != 0) {
        mob->drop_rate[item_nb].x = my_getnbr(mob_info[DROP_RATE + item_nb]);
        mob->drop_rate[item_nb].y = my_getnbr(mob_info[DROP_RATE + item_nb + 1]);
        item_nb += 2;
    }
}

static void assign_max_drop(char **mob_info, bot_t *mob)
{
    int item_nb = 0;

    while (item_nb < 5 && my_strcmp(mob_info[DROP_NB + item_nb], "NA") != 0) {
        mob->max_nb_drop[item_nb] = my_getnbr(mob_info[DROP_NB + item_nb]);
        ++item_nb;
    }
}

int call_function_item_mob(char **mob_info, bot_t *mob, item_t **list_item)
{
    assign_item_mob(mob_info, mob, list_item);
    assign_drop_rate_item(mob_info, mob);
    assign_max_drop(mob_info, mob);
    return (0);
}
