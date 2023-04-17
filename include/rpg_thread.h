/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function for thread
*/

#pragma once

#include "game_element.h"

int launch_thread_detect(program_elem_t *all_elem, sfThread **thread);
void call_detection_and_path_finding(void *v_data);
