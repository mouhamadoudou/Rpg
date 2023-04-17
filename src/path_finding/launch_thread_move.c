/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move the mob int the window when the path was found
*/
#include <stdlib.h>
#include "path_finding.h"
#include "mob.h"

/*static void free_sub_thread_data(sub_thread_data_t *s_t_data)
{
    free(s_t_data->list_cell);
    free(s_t_data->pos_mob_player);
    free(s_t_data);
}*/

int create_list_cell_of_path(int mob_nb, coord_for_a_star_t *coords,
                            a_star_elem_t *a_elem, thread_data_t *t_data)
{
    int i = 0;
    sfVector2i x_y = a_elem->current->pos_map;
    sfVector2i *list_cell = NULL;

    while (x_y.x != coords->map_pos[PLAYER_POS].x &&
        x_y.y != coords->map_pos[PLAYER_POS].y) {
        ++i;
        x_y = a_elem->came_from[x_y.y][x_y.x];
    }
    if ((list_cell = malloc(sizeof(sfVector2i) * (size_t)(i + 1))) == NULL)
        return (-1);
    x_y = a_elem->current->pos_map;
    for (int j = 0; j < i; ++j) {
        list_cell[j] = a_elem->came_from[x_y.y][x_y.x];
        x_y = a_elem->came_from[x_y.y][x_y.x];
    }
    list_cell[i].x = END_OF_LIST;
    t_data->sub_thread_data->list_cell[mob_nb] = list_cell;
    t_data->sub_thread_data->pos_mob_player[mob_nb] = coords->window_pos;
    t_data->sub_thread_data->need_move[mob_nb] = true;
    return (0);
}

static sub_thread_data_t *create_sub_thread_data(bot_t **mob_in_map)
{
    sub_thread_data_t *new_data = malloc(sizeof(sub_thread_data_t) * 1);

    if (new_data == NULL)
        return (NULL);
    new_data->stop_thread = false;
    for (int i = 0; i < NB_MOB_ON_MAP; ++i) {
        new_data->need_move[i] = false;
        new_data->pos_mob_player[i] = NULL;
        new_data->list_cell[i] = NULL;
    }
    new_data->mob_in_map = mob_in_map;
    return (new_data);
}

int launch_thread_move(bot_t **mob_in_map, thread_data_t *t_data)
{
    sub_thread_data_t *new_data = create_sub_thread_data(mob_in_map);

    if (new_data == NULL)
        return (-1);
    t_data->sub_thread_data = new_data;
    t_data->sub_thread = sfThread_create(&do_move, t_data->sub_thread_data);
    sfThread_launch(t_data->sub_thread);
    return (0);
}
