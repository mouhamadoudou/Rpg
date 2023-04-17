/*
** EPITECH PROJECT, 2022
** dante
** File description:
** init the value of score and came from variable
*/
#include "path_finding.h"

void set_value_a_star_elem(int line_len, sfVector2i *score,
                        sfVector2i *came_from)
{
    int i = 0;

    while (i < line_len) {
        score[i].x = NOT_SET;
        came_from[i].x = NOT_SET;
        ++i;
    }
}
