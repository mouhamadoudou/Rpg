/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main function used for the thread of mob detection
*/
#include <SFML/System/Thread.h>
#include <stdlib.h>
#include "rpg_struct.h"
#include "path_finding.h"
#include "mob.h"
#include "rpg_free.h"
#include "rpg_macro.h"

static int check_pos_around_mob(player_t *player, bot_t *mob)
{
    if (player->player.cord.x >= (mob->texture->cord.x - 50) &&
        player->player.cord.x <= (mob->texture->cord.x + 50)) {
        if (player->player.cord.y >= mob->texture->cord.y - 50 &&
            player->player.cord.y <= mob->texture->cord.y + 50) {
            return (0);
        } else {
            return (-1);
        }
    } else {
        return (-1);
    }
}

static int detect_player(player_t *player, bot_t **mob_in_map)
{
    int i = 0;

    while (i < NB_MOB_ON_MAP && mob_in_map[i] != NULL) {
        if (check_pos_around_mob(player, mob_in_map[i]) == 0)
            return (i);
        ++i;
    }
    return (-1);
}

static int call_a_star(int mob_pos, program_elem_t *data)
{
    coord_for_a_star_t *coords = NULL;

    coords = create_coord_for_a_star(mob_pos, data);
    if (coords == NULL)
        return (-1);
    if (data->t_data->sub_thread_data == NULL)
        launch_thread_move(data->elem_game->mob_in_map, data->t_data);
    if (data->t_data->prev_dest[mob_pos].x == coords->map_pos->x &&
        data->t_data->prev_dest[mob_pos].y == coords->map_pos->y)
        return (0);
    if (coords->map_pos[PLAYER_POS].x == coords->map_pos[MOB_POS].x &&
        coords->map_pos[PLAYER_POS].y == coords->map_pos[MOB_POS].y)
        return (0);
    a_star(mob_pos, coords, data->elem_win->map, data->t_data);
    data->t_data->prev_dest[mob_pos].x = coords->map_pos->x;
    data->t_data->prev_dest[mob_pos].y = coords->map_pos->y;
    free(coords);
    return (0);
}

static void is_player_detected(clock_elem_t *c_elem, program_elem_t *data)
{
    int mob_pos = -1;

    mob_pos = detect_player(data->elem_game->player,
                            data->elem_game->mob_in_map);
    if (mob_pos != -1) {
        attack_player_mob(mob_pos, data->elem_game);
        wait_attack_mob(c_elem);
    }
}

void call_detection_and_path_finding(void *v_data)
{
    program_elem_t *data = (program_elem_t *)v_data;
    clock_elem_t c_elem;

    c_elem.clock = sfClock_create();
    while (data->t_data->stop_thread == false) {
        if (data->elem_game->player != NULL &&
            data->elem_game->player->in_dialog == false) {
            is_player_detected(&c_elem, data);
        }
    }
    if (data->t_data->sub_thread != NULL) {
        sfThread_wait(data->t_data->sub_thread);
        sfThread_destroy(data->t_data->sub_thread);
    }
    free_thread_data(data);
}
