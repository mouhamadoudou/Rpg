/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to spawn a mob on the map
*/
#include "mob.h"
#include "conf_file.h"

static int generate_random_mob(char ***mob_data)
{
    int res = 0;
    int nb_mob = big_array_len(mob_data);
    int *tmp = malloc(sizeof(int));

    if (tmp == NULL)
        return (res);
    srand((__intptr_t)tmp);
    res = rand() % nb_mob + 1;
    return (res);
}

int spawn_mob_on_map(game_elem_t *game_elem)
{
    bot_t *mob = create_in_game_mob(game_elem->mob_data
                                    [generate_random_mob(game_elem->mob_data)],
                                    game_elem->list_mob);

    if (mob == NULL)
        return (-1);
    game_elem->mob_in_map[0] = mob;
    return (0);
}
