/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free a_star_elem_t struct
*/
#include <stdlib.h>
#include "my_rpg_map.h"
#include "path_finding.h"

void free_a_elem(a_star_elem_t *a_elem, map_t **map)
{
    int i = 0;
    int len_tab = my_tablen(map);

    free(a_elem->paths);
    while (i < len_tab) {
        free(a_elem->came_from[i]);
        free(a_elem->score[i]);
        ++i;
    }
    free(a_elem->came_from);
    free(a_elem->score);
    free(a_elem);
}
