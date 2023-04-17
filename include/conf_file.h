/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function used while opening conf file
*/

#pragma once

#include "rpg_struct.h"

size_t big_array_len(void *array);
char **get_file_content(const char *filename);
void free_getline_elem(getline_elem_t *elem);
getline_elem_t *create_getline_struct(const char *filename);
char ***create_info(char *filepath);
char **str_to_word_array(char *str, char separator);
void free_3_array(void *array);
