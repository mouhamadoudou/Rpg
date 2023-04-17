/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** wait function for movement of mob
*/

#include "path_finding.h"

void wait_move(sfTime *time, sfClock *clock)
{
    static float seconds;

    *time = sfClock_getElapsedTime(clock);
    seconds = time->microseconds / 1000000.0;
    while (seconds < 0.5) {
        *time = sfClock_getElapsedTime(clock);
        seconds = time->microseconds / 1000000.0;
    }
    sfClock_restart(clock);
}
