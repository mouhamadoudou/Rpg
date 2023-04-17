/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create the list of all the mob
*/
#include <stdlib.h>
#include "conf_file.h"
#include "game_element.h"
#include "my_rpg.h"
#include "mob.h"
#include "my.h"

bot_t **create_list_mob(game_elem_t *game_elem)
{
    int i = 0;
    char ***info_all_mob = create_info("conf/mob.conf");
    bot_t **list_mob = NULL;

    if (info_all_mob == NULL)
        return (NULL);
    list_mob = malloc(sizeof(bot_t *) * (size_t)
                    ((big_array_len(info_all_mob)) + 1));
    if (list_mob == NULL)
        return (NULL);
    while (i < (int)big_array_len(info_all_mob)) {
        list_mob[i] = create_mob(info_all_mob[i], game_elem);
        if (list_mob[i] == NULL)
            return (NULL);
        ++i;
    }
    list_mob[i] = NULL;
    game_elem->mob_data = info_all_mob;
    return (list_mob);
}
