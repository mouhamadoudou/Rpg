/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move function mob
*/
#include "path_finding.h"
#include "rpg_macro.h"

static const move_straight_fun_t TAB_FUN[] = {
    { { GO_LEFT, 0 }, &move_left },
    { { GO_RIGHT, 0 }, &move_right },
    { { 0, GO_UP }, &move_up },
    { { 0, GO_DOWN }, &move_down }
};

void move_left(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data)
{
    int i = 0;

    while (t_data->stop_thread == false && i < 64) {
        wait_move(&c_elem->time, c_elem->clock);
        t_data->mob_in_map[mob_nb]->texture->cord.x -=
        t_data->mob_in_map[mob_nb]->stat.speed;
        i += t_data->mob_in_map[mob_nb]->stat.speed;
    }
}

void move_right(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data)
{
    int i = 0;

    while (t_data->stop_thread == false && i < 64) {
        wait_move(&c_elem->time, c_elem->clock);
        t_data->mob_in_map[mob_nb]->texture->cord.x +=
        t_data->mob_in_map[mob_nb]->stat.speed;
        i += t_data->mob_in_map[mob_nb]->stat.speed;
    }
}

void move_up(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data)
{
    int i = 0;

    while (t_data->stop_thread == false && i < 64) {
        wait_move(&c_elem->time, c_elem->clock);
        t_data->mob_in_map[mob_nb]->texture->cord.y -=
        t_data->mob_in_map[mob_nb]->stat.speed;
        i += t_data->mob_in_map[mob_nb]->stat.speed;
    }
}

void move_down(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data)
{
    int i = 0;

    while (t_data->stop_thread == false && i < 64) {
        wait_move(&c_elem->time, c_elem->clock);
        t_data->mob_in_map[mob_nb]->texture->cord.y +=
        t_data->mob_in_map[mob_nb]->stat.speed;
        i += t_data->mob_in_map[mob_nb]->stat.speed;
    }
}

int move_straight_line(int mob_nb, clock_elem_t *c_elem, sfVector2i *to_move,
                    sub_thread_data_t *t_data)
{
    for (int i = 0; i < 4; ++i) {
        if (to_move->x == TAB_FUN[i].direction.x &&
            to_move->y == TAB_FUN[i].direction.y) {
            TAB_FUN[i].fun_ptr(mob_nb, c_elem, t_data->pos_mob_player[0],
                            t_data);
            return (0);
        }
    }
    return (-1);
}
