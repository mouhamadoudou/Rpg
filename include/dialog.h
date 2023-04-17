/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header for dialogue function and struct
*/

#pragma once

#include "rpg_struct.h"
#include "game_element.h"
#include "my.h"

#define NB_NPC (9)

typedef enum {
    DIALOG_SKIP,
    DIALOG_NORMAL,
    DIALOG_END,
} dialog_status_t;

char *char_to_str(char c);
dialog_t *call_dialog(npc_t *npc, sfVector2f *player_pos);
int get_nb_line(char *filepath);
char *assemble_str(char *str1, char *str2, char *str3);
char **get_npc_dialog(char ***name, npc_t *npc);
int is_char_i_or_m(char c);
dialog_t *create_dialog(char **name, char **dialogue_list);

int display_dialog(dialog_t *dialogue_elem, window_elem_t *elem_win);

void free_dialog_elem(dialog_t *dialogue);
void free_array(void *array);
