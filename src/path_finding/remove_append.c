/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** remove and append for data in A*
*/
#include <stdlib.h>
#include "path_finding.h"

static void duplicate_list(int size, int to_remove, paths_t *new_list,
                        paths_t **paths_list)
{
    int i = 0;
    int j = 0;

    while (i < size) {
        if (i != to_remove) {
            new_list[j] = (*paths_list)[i];
            ++j;
        }
        ++i;
    }
    if (i != 0)
        new_list[size - 1].map = NULL;
    else
        new_list[0].map = NULL;
    free(*paths_list);
    *paths_list = new_list;
}

int list_remove(paths_t *to_remove, paths_t **paths_list)
{
    int i = 0;
    int size = 0;
    paths_t *new_list = NULL;

    while ((*paths_list)[size].map != NULL) {
        ++size;
    }
    while (i < size) {
        if (to_remove->pos_map.x != (*paths_list)[i].pos_map.x &&
            to_remove->pos_map.y != (*paths_list)[i].pos_map.y)
            break;
        ++i;
    }
    new_list = malloc(sizeof(paths_t) * (size_t)(size));
    if (new_list == NULL)
        return (-1);
    duplicate_list(size, i, new_list, paths_list);
    return (0);
}

int paths_append(sfVector2i *new_paths, paths_t **paths, map_t **map)
{
    int i = 0;
    int size = 0;
    paths_t *tmp_paths = NULL;

    while ((*paths)[size].map != NULL)
        ++size;
    tmp_paths = malloc(sizeof(paths_t) * (size_t)(size + 2));
    if (tmp_paths == NULL)
        return (-1);
    while (i < size) {
        tmp_paths[i] = (*paths)[i];
        ++i;
    }
    tmp_paths[i].pos_map = new_paths[0];
    tmp_paths[i].map = &map[new_paths[0].y][new_paths[0].x];
    tmp_paths[i + 1].map = NULL;
    free(*paths);
    *paths = tmp_paths;
    return (0);
}
