/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function related to score of node for A*
*/
#include <stdlib.h>
#include "path_finding.h"
#include "rpg_data_type.h"
#include "rpg_macro.h"

static const tab_check_t TAB[] = {
    { 0, { 0, 1 } },
    { 1, { 1, 0 } },
    { 2, { 0, -1 } },
    { 3, { -1, 0 } },
    { 4, { 1, 1 } },
    { 5, { -1, -1 } },
    { 6, { -1, 1 } },
    { 7, { 1, -1 } },
};

paths_t *best_f_score(paths_t *paths, sfVector2i **score)
{
    int i = 0;
    sfVector2i best_paths = { NOT_SET, NOT_SET };
    paths_t *return_val = malloc(sizeof(paths_t) * 1);

    if (return_val == NULL)
        return (NULL);
    while (paths[i].map != NULL) {
        if (ABS(score[paths[i].pos_map.y][paths[i].pos_map.x].x +
            score[paths[i].pos_map.y][paths[i].pos_map.x].y) <
            best_paths.x || best_paths.x == NOT_SET) {
            best_paths.x = score[paths[i].pos_map.y][paths[i].pos_map.x].x +
                        score[paths[i].pos_map.y][paths[i].pos_map.x].y;
            best_paths.y = i;
        }
        ++i;
    }
    *return_val = paths[best_paths.y];
    return (return_val);
}

int h_score(sfVector2i *pos, sfVector2i *dest)
{
    int cost = 0;

    cost = dest->x - pos->x + dest->y - pos->y;
    return (cost);
}

static sfVector2i *value_score_neighbor(sfVector2i *tmp_score,
                                        sfVector2i *dest,
                                        a_star_elem_t *a_elem, map_t **map)
{
    if (map[tmp_score[0].y][tmp_score[0].x].is_block == true) {
        tmp_score[1].x = IS_AN_OBSTACLE;
        tmp_score[1].y = IS_AN_OBSTACLE;
    } else {
        tmp_score[1].x = a_elem->score[a_elem->current->pos_map.y]
                        [a_elem->current->pos_map.x].x + 1;
        tmp_score[1].y = h_score(&tmp_score[0], dest);
    }
    return (tmp_score);
}

sfVector2i *calculate_score(int i, sfVector2i *dest, a_star_elem_t *a_elem,
                            map_t **map)
{
    sfVector2i *tmp_pos = malloc(sizeof(sfVector2i) * 2);

    if (tmp_pos == NULL)
        return (NULL);
    tmp_pos[0].x = a_elem->current->pos_map.x;
    tmp_pos[0].y = a_elem->current->pos_map.y;
    for (int x = 0; x < 8; ++x) {
        if (TAB[x].value == i) {
            tmp_pos[0].x += TAB[x].to_check.x;
            tmp_pos[0].y += TAB[x].to_check.y;
            break;
        }
    }
    if (tmp_pos[0].x < 0 || tmp_pos[0].y < 0 ||
        tmp_pos[0].x > a_elem->line_len - 1 ||
        tmp_pos[0].y > a_elem->map_len - 1) {
        tmp_pos[1].x = END_OF_MAP;
        return (tmp_pos);
    }
    return (value_score_neighbor(tmp_pos, dest, a_elem, map));
}

bool is_score_neighbor_good(sfVector2i *score_neighbor)
{
    if (score_neighbor[1].x != IS_AN_OBSTACLE) {
        return (true);
    } else {
        return (false);
    }
}
