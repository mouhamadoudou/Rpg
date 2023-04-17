/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free data thread
*/
#include <stdlib.h>
#include "game_element.h"
#include "rpg_free.h"

static void free_mob_thread(sub_thread_data_t *t_data)
{
    int i = 0;

    while (i < NB_MOB_ON_MAP) {
        free_mob_struct(t_data->mob_in_map[i]);
        free(t_data->mob_in_map[i]);
        ++i;
    }
    free(t_data->mob_in_map);
}

void free_thread_data(program_elem_t *data)
{
    int i = 0;

    while (i < NB_MOB_ON_MAP) {
        if (data->t_data->sub_thread_data != NULL) {
            free(data->t_data->sub_thread_data->list_cell[i]);
            free(data->t_data->sub_thread_data->pos_mob_player[i]);
        }
        ++i;
    }
    if (data->t_data->sub_thread_data != NULL)
        free_mob_thread(data->t_data->sub_thread_data);
    free(data->t_data->sub_thread_data);
    free(data->t_data);
}
