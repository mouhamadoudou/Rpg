/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to move in diagonal
*/
#include <stdlib.h>
#include "path_finding.h"

sfVector2f *determine_value_move_diag(sfVector2i *direction)
{
    sfVector2f *to_move = malloc(sizeof(sfVector2f) * 1);

    if (to_move == NULL)
        return (NULL);
    if (direction->x == GO_LEFT)
        to_move->x = -64;
    else
        to_move->x = 64;
    if (direction->y == GO_UP)
        to_move->y = -64;
    else
        to_move->y = 64;
    return (to_move);
}

static bool is_move_finished(sfVector2f *remain, sfVector2f *original_val)
{
    if (remain->x <= 0 && original_val->x > 0)
        return (true);
    else if (remain->x >= 0 && original_val->x < 0)
        return (true);
    else
        return (false);
}

static void do_diag_move(int mob_nb, sfVector2f *remain,
                        sub_thread_data_t *t_data)
{
    if (remain->x < 0) {
        t_data->mob_in_map[mob_nb]->texture->cord.x -=
        t_data->mob_in_map[mob_nb]->stat.speed;
        remain->x += t_data->mob_in_map[mob_nb]->stat.speed;
    } else if (remain->x > 0) {
        t_data->mob_in_map[mob_nb]->texture->cord.x +=
        t_data->mob_in_map[mob_nb]->stat.speed;
        remain->x -= t_data->mob_in_map[mob_nb]->stat.speed;
    }
    if (remain->y < 0) {
        t_data->mob_in_map[mob_nb]->texture->cord.y -=
        t_data->mob_in_map[mob_nb]->stat.speed;
        remain->y += t_data->mob_in_map[mob_nb]->stat.speed;
    } else if (remain->y > 0) {
        t_data->mob_in_map[mob_nb]->texture->cord.y +=
        t_data->mob_in_map[mob_nb]->stat.speed;
        remain->y -= t_data->mob_in_map[mob_nb]->stat.speed;
    }
}

void move_diagonal(int mob_nb, clock_elem_t *c_elem, sfVector2f *to_move,
                sub_thread_data_t *t_data)
{
    sfVector2f *remain = to_move;
    sfVector2f original_val = *remain;

    while (t_data->stop_thread == false &&
        is_move_finished(remain, &original_val) == false) {
        wait_move(&c_elem->time, c_elem->clock);
        do_diag_move(mob_nb, remain, t_data);
    }
}
