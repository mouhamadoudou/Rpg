/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to handle attack of the player
*/
#include "game_element.h"
#include "mob.h"

void wait_attack_mob(clock_elem_t *c_elem)
{
    static float seconds;

    c_elem->time = sfClock_getElapsedTime(c_elem->clock);
    seconds = c_elem->time.microseconds / 1000000.0;
    while (seconds < 0.5) {
        c_elem->time = sfClock_getElapsedTime(c_elem->clock);
        seconds = c_elem->time.microseconds / 1000000.0;
    }
    sfClock_restart(c_elem->clock);
}

int attack_player_mob(int mob_pos, game_elem_t *elem_game)
{
    int tmp = elem_game->player->current_life;

    if (tmp == 0)
        return (0);
    if (tmp - elem_game->mob_in_map[mob_pos]->stat.attack < 0)
        elem_game->player->current_life = 0;
    else
        elem_game->player->current_life -= elem_game->mob_in_map[mob_pos]->
                                        stat.attack;
    return (0);
}
