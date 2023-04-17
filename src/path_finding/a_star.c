/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** A* algorithm
*/
#include <stdlib.h>
#include "my_rpg_map.h"
#include "path_finding.h"
#include "my.h"

static int fill_a_star_elem(sfVector2i *coords, a_star_elem_t *a_elem,
                            map_t **map)
{
    for (int i = 0; i < my_tablen(map); ++i) {
        a_elem->came_from[i] = malloc(sizeof(sfVector2i) *
                                      (size_t)map_line_len(map[0]));
        a_elem->score[i] = malloc(sizeof(sfVector2i) *
                                  (size_t)map_line_len(map[0]));
        if (a_elem->came_from[i] == NULL || a_elem->score[i] == NULL)
            return (-1);
        set_value_a_star_elem(a_elem->line_len, a_elem->score[i],
                            a_elem->came_from[i]);
    }
    a_elem->paths[0].map = &map[coords[MOB_POS].x][coords[MOB_POS].y];
    a_elem->paths[0].pos_map = coords[MOB_POS];
    a_elem->paths[1].map = NULL;
    a_elem->score[0][0].x = 0;
    a_elem->score[0][0].y = h_score(&coords[MOB_POS], &coords[PLAYER_POS]);
    return (0);
}

static a_star_elem_t *initialize_a_star(coord_for_a_star_t *coords,
                                        map_t **map)
{
    a_star_elem_t *a_elem = malloc(sizeof(a_star_elem_t) * 1);

    if (a_elem == NULL)
        return (NULL);
    a_elem->map_len = my_tablen(map);
    a_elem->line_len = map_line_len(map[0]);
    a_elem->current = NULL;
    a_elem->paths = malloc(sizeof(paths_t) * 2);
    a_elem->came_from = malloc(sizeof(sfVector2i *) * (size_t)my_tablen(map));
    a_elem->score = malloc(sizeof(sfVector2i *) * (size_t)my_tablen(map));
    if (a_elem->paths == NULL || a_elem->came_from == NULL ||
        a_elem->score == NULL)
        return (NULL);
    if (fill_a_star_elem(coords->map_pos, a_elem, map) == -1)
        return (NULL);
    return (a_elem);
}

static int update_paths_info(sfVector2i *tmp_score, a_star_elem_t *a_elem,
                            map_t **map)
{
    if (is_score_neighbor_good(tmp_score) == true &&
        pos_already_exist(&tmp_score[0], a_elem) == false) {
        a_elem->came_from[tmp_score[0].y][tmp_score[0].x] = a_elem->current->pos_map;
        a_elem->score[tmp_score[0].y][tmp_score[0].x] = tmp_score[1];
        if (is_new_pos_in_paths(&tmp_score[0], a_elem->paths) == false) {
            return (paths_append(tmp_score, &a_elem->paths, map));
        }
    }
    return (0);
}

static int find_new_paths(sfVector2i *dest, a_star_elem_t *a_elem, map_t **map)
{
    int i = 0;
    sfVector2i *tmp_score = NULL;

    while (i < 8) {
        tmp_score = calculate_score(i, dest, a_elem, map);
        if (tmp_score == NULL)
            return (-1);
        else if (tmp_score[1].x == END_OF_MAP) {
            ++i;
            free(tmp_score);
            continue;
        }
        if (update_paths_info(tmp_score, a_elem, map) == -1)
            return (-1);
        free(tmp_score);
        ++i;
    }
    return (0);
}

int a_star(int mob_nb, coord_for_a_star_t *coords, map_t **map,
        thread_data_t *t_data)
{
    a_star_elem_t *a_elem = initialize_a_star(coords, map);

    if (a_elem == NULL)
        return (-1);
    while (a_elem->paths[0].map != NULL) {
        a_elem->current = best_f_score(a_elem->paths, a_elem->score);
        if (a_elem->current->pos_map.x == coords->map_pos[PLAYER_POS].x &&
            a_elem->current->pos_map.y == coords->map_pos[PLAYER_POS].y) {
            create_list_cell_of_path(mob_nb, coords, a_elem, t_data);
            free_a_elem(a_elem, map);
            return (0);
        }
        if (list_remove(a_elem->current, &a_elem->paths) == -1)
            return (-1);
        if (find_new_paths(&coords->map_pos[PLAYER_POS], a_elem, map) == -1)
            return (-1);
        free(a_elem->current);
    }
    free_a_elem(a_elem, map);
    return (-1);
}
