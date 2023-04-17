/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free function for my_rpg
*/

#pragma once

#include "game_element.h"

void free_game_object_t(game_object_t *object);
void free_mob_struct(bot_t *mob);
void free_list_all_mob_and_in_map(game_elem_t *elem_game);
void free_thread_data(program_elem_t *data);

