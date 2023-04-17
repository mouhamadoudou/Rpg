/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function for event management
*/
#include "rpg_struct.h"
#include "game_element.h"
#include "dialog.h"

static void manage_event_dialog_launched(sfEvent *event,
                                        program_elem_t *all_elem)
{
    if (event->key.code == sfKeySpace &&
        all_elem->elem_game->player->in_dialog == true &&
        all_elem->elem_game->dialog_elem->dialog_text
        [all_elem->elem_game->dialog_elem->displayed_dialog]
        [all_elem->elem_game->dialog_elem->nb_char_to_display + 1] == NULL &&
        all_elem->elem_game->dialog_elem->nb_dialog ==
        all_elem->elem_game->dialog_elem->displayed_dialog + 1) {
        all_elem->elem_game->player->in_dialog = false;
        if (all_elem->elem_game->list_npc
            [all_elem->elem_game->dialog_elem->npc_nb].active_dialog < 1) {
            ++all_elem->elem_game->list_npc
            [all_elem->elem_game->dialog_elem->npc_nb].active_dialog;
        }
        free_dialog_elem(all_elem->elem_game->dialog_elem);
        return;
    }
}

void manage_event_dialog(sfEvent *event, program_elem_t *all_elem)
{
    if (event->key.code == sfKeyE && all_elem->elem_game->player->in_dialog ==
        false) {
        all_elem->elem_game->dialog_elem =
        call_dialog(all_elem->elem_game->list_npc,
                    &all_elem->elem_game->player->player.cord);
        if (all_elem->elem_game->dialog_elem != NULL)
            all_elem->elem_game->player->in_dialog = true;
        return;
    }
    if (event->key.code == sfKeySpace &&
        all_elem->elem_game->player->in_dialog == true &&
        all_elem->elem_game->dialog_elem->dialog_text
        [all_elem->elem_game->dialog_elem->displayed_dialog]
        [all_elem->elem_game->dialog_elem->nb_char_to_display + 1] == NULL &&
        all_elem->elem_game->dialog_elem->nb_dialog !=
        all_elem->elem_game->dialog_elem->displayed_dialog + 1) {
        ++all_elem->elem_game->dialog_elem->displayed_dialog;
        all_elem->elem_game->dialog_elem->nb_char_to_display = 1;
        return;
    }
    manage_event_dialog_launched(event, all_elem);
}
