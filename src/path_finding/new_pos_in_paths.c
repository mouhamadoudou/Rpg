/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** Is the neighbor of current already in paths
*/
#include "path_finding.h"

bool is_new_pos_in_paths(sfVector2i *new_pos, paths_t *paths_list)
{
    int i = 0;

    while (paths_list[i].map != NULL) {
        if (new_pos->x == paths_list[i].pos_map.x &&
            new_pos->y == paths_list[i].pos_map.y)
            return (true);
        ++i;
    }
    return (false);
}

bool pos_already_exist(sfVector2i *new_pos, a_star_elem_t *a_elem)
{
    if (a_elem->score[new_pos->y][new_pos->x].x == NOT_SET) {
        return (false);
    }
    return (true);
}
