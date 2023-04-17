/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function that move the mob in the window
*/
#include <stdlib.h>
#include "path_finding.h"

static sfVector2i *detect_direction(sfVector2i *pos, sfVector2i *next_cell)
{
    int x = pos->x - next_cell->x;
    int y = pos->y - next_cell->y;
    sfVector2i *direction = malloc(sizeof(sfVector2i) * 1);

    if (direction == NULL)
        return (NULL);
    if (x < 0)
        x = GO_RIGHT;
    else if (x > 0)
        x = GO_LEFT;
    if (y > 0)
        y = GO_UP;
    else if (y < 0)
        y = GO_DOWN;
    direction->x = x;
    direction->y = y;
    return (direction);
}

static sfVector2f *is_path_straight_line(int i, sfVector2i *direction,
                                        sfVector2f *pos_mob,
                                        sfVector2f *pos_player)
{
    sfVector2f *to_move = malloc(sizeof(sfVector2i) * 1);

    if (to_move == NULL)
        return (NULL);
    *to_move = (sfVector2f){ 0, 0 };
    if (i != 1 && direction->x < GO_LEFT && direction->y < GO_UP) {
        return (to_move);
    } else if (i == 1) {
        to_move->x = pos_mob->x - pos_player->x;
        to_move->y = pos_mob->y - pos_player->y;
        return (to_move);
    } else {
        to_move = determine_value_move_diag(direction);
        if (to_move == NULL)
            return (NULL);
        return (to_move);
    }
}

static int move_mob(int mob_nb, int pos_list_cell, sfVector2i *direction,
                    sub_thread_data_t *t_data)
{
    clock_elem_t c_elem;
    sfVector2f *to_move = is_path_straight_line(pos_list_cell, direction,
                                                &t_data->pos_mob_player[mob_nb]
                                                [MOB_POS],
                                                &t_data->pos_mob_player[mob_nb]
                                                [PLAYER_POS]);

    c_elem.clock = sfClock_create();
    if (to_move == NULL || c_elem.clock == NULL) {
        free(direction);
        return (-1);
    }
    if (to_move->x == 0 || to_move->y == 0) {
        move_straight_line(mob_nb, &c_elem, direction, t_data);
    } else
        move_diagonal(mob_nb, &c_elem, to_move, t_data);
    free(direction);
    free(to_move);
    sfClock_destroy(c_elem.clock);
    return (0);
}

static void init_pos_list_cell(int *nb_cell, sfVector2i *list_cell)
{
    if (*nb_cell == NOT_SET) {
        while (list_cell[*nb_cell].x != END_OF_LIST) {
            ++(*nb_cell);
        }
    }
}

void do_move(void *data)
{
    sub_thread_data_t *t_data = (sub_thread_data_t *)data;
    int i = 0;
    int *pos_list_cell = malloc(sizeof(int) * NB_MOB_ON_MAP);

    if (pos_list_cell == NULL)
        return;
    for (int j = 0; j < NB_MOB_ON_MAP; ++j) {
        pos_list_cell[j] = NOT_SET;
    }
    while (t_data->stop_thread == false && i < NB_MOB_ON_MAP) {
        if (t_data->need_move[i] == true) {
            init_pos_list_cell(&pos_list_cell[i], t_data->list_cell[i]);
            move_mob(i, pos_list_cell[i],
                    detect_direction(t_data->list_cell[pos_list_cell[i]],
                    t_data->list_cell[pos_list_cell[i] - 1]), t_data);
            --pos_list_cell[i];
        }
        ++i;
        if (i == NB_MOB_ON_MAP)
            i = 0;
    }
}