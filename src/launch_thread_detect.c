/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** launch thread detect
*/
#include "game_element.h"
#include "rpg_thread.h"

int launch_thread_detect(program_elem_t *all_elem, sfThread **thread)
{
    *thread = sfThread_create(&call_detection_and_path_finding, all_elem);

    if (*thread == NULL)
        return (ERROR);
    sfThread_launch(*thread);
    return (0);
}
