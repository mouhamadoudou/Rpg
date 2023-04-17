/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** path finding function and struct
*/

#pragma once

#include "rpg_struct.h"
#include "game_element.h"
#include "rpg_macro.h"

#define NOT_SET (-96)
#define IS_AN_OBSTACLE (-42)
#define ALREADY_IN_PATHS (-69)
#define GO_LEFT (80000)
#define GO_RIGHT (80001)
#define GO_UP (80002)
#define GO_DOWN (80003)
#define END_OF_MAP (-420)
#define END_OF_LIST (-690)
#define PLAYER_POS (1)
#define MOB_POS (0)

typedef struct coord_for_a_star_s {
    sfVector2i map_pos[2];
    sfVector2f window_pos[2];
} coord_for_a_star_t;

typedef struct tab_check_s {
    int value;
    sfVector2i to_check;
} tab_check_t;

typedef struct paths_s {
    map_t *map;
    sfVector2i pos_map;
} paths_t;

typedef struct a_star_elem_s {
    int map_len;
    int line_len;
    paths_t *current;
    paths_t *paths;
    sfVector2i **came_from;
    sfVector2i **score;
} a_star_elem_t;

typedef struct move_straight_fun {
    sfVector2i direction;
    void (*fun_ptr) (int mob_nb, clock_elem_t *, sfVector2f *,
                    sub_thread_data_t *t_data);
} move_straight_fun_t;

coord_for_a_star_t *create_coord_for_a_star(int mob_pos, program_elem_t *data);

void set_value_a_star_elem(int line_len, sfVector2i *score,
                        sfVector2i *came_from);
int a_star(int mob_nb, coord_for_a_star_t *coords, map_t **map,
        thread_data_t *t_data);

sfVector2i *calculate_score(int i, sfVector2i *dest, a_star_elem_t *a_elem,
                            map_t **map);
int h_score(sfVector2i *pos, sfVector2i *dest);
paths_t *best_f_score(paths_t *paths, sfVector2i **score);
bool is_new_pos_in_paths(sfVector2i *new_pos, paths_t *paths_list);
bool pos_already_exist(sfVector2i *new_pos, a_star_elem_t *a_elem);
bool is_score_neighbor_good(sfVector2i *score_neighbor);

int list_remove(paths_t *to_remove, paths_t **paths_list);
int paths_append(sfVector2i *new_paths, paths_t **paths, map_t **map);

void wait_move(sfTime *time, sfClock *clock);
int launch_thread_move(bot_t **mob_in_map, thread_data_t *t_data);
int create_list_cell_of_path(int mob_nb, coord_for_a_star_t *coords,
                            a_star_elem_t *a_elem, thread_data_t *t_data);
sfVector2f *determine_value_move_diag(sfVector2i *direction);
void do_move(void *data);
void move_diagonal(int mob_nb, clock_elem_t *c_elem, sfVector2f *to_move,
                   sub_thread_data_t *t_data);
int move_straight_line(int mob_nb, clock_elem_t *c_elem, sfVector2i *to_move,
                       sub_thread_data_t *t_data);
void move_down(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data);
void move_up(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data);
void move_left(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data);
void move_right(int mob_nb, clock_elem_t *c_elem, sfVector2f *pos_mob,
            sub_thread_data_t *t_data);

void free_a_elem(a_star_elem_t *a_elem, map_t **map);
