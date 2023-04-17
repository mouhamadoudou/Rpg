/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create the coords for a star
*/
#include <stdlib.h>
#include "path_finding.h"
#include "mob.h"
#include "my_rpg.h"

static void set_map_pos(int *mob_pos_map, int *player_pos_map,
                        coord_for_a_star_t *coords)
{
    coords->map_pos[MOB_POS].x = mob_pos_map[0];
    coords->map_pos[MOB_POS].y = mob_pos_map[1];
    coords->map_pos[PLAYER_POS].x = player_pos_map[0];
    coords->map_pos[PLAYER_POS].y = player_pos_map[1];
    free(mob_pos_map);
    free(player_pos_map);
}

coord_for_a_star_t *create_coord_for_a_star(int mob_pos, program_elem_t *data)
{
    int *player_pos_map = NULL;
    int *mob_pos_map = NULL;
    coord_for_a_star_t *coords = malloc(sizeof(coord_for_a_star_t) * 1);

    if (coords == NULL)
        return (NULL);
    coords->window_pos[MOB_POS].x = data->elem_game->mob_in_map[mob_pos]->
                                texture->cord.x;
    coords->window_pos[MOB_POS].y = data->elem_game->mob_in_map[mob_pos]->
                                texture->cord.y;
    coords->window_pos[PLAYER_POS].x = data->elem_game->player->player.cord.x;
    coords->window_pos[PLAYER_POS].y = data->elem_game->player->player.cord.y;
    player_pos_map = find_current_tile(data->elem_win->map);
    mob_pos_map = find_mob_current_tile(&data->elem_game->mob_in_map
                                        [mob_pos]->texture->cord,
                                        data->elem_win->map);
    if (player_pos_map == NULL || mob_pos_map == NULL)
        return (NULL);
    set_map_pos(mob_pos_map, player_pos_map, coords);
    return (coords);
}