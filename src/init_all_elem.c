/*
** EPITECH PROJECT, 2022
** init_all_elem.c
** File description:
** init_all_elem
*/

#include <stdlib.h>
#include "path_finding.h"
#include "mob.h"
#include "spell.h"
#include "item.h"
#include "dialog.h"
#include "my_rpg.h"

static window_elem_t *set_elem_win(void)
{
    window_elem_t *elem_win = malloc(sizeof(window_elem_t));

    if (elem_win == NULL)
        return NULL;
    elem_win->window = handle_window();
    elem_win->sound_is_on = true;
    elem_win->out_pause = false;
    elem_win->out_stat = false;
    elem_win->out_help = false;
    elem_win->init_pos_x = 100;
    elem_win->init_pos_y = 530;
    return elem_win;
}

static game_elem_t *set_game_elem(void)
{
    game_elem_t *game_elem = malloc(sizeof(game_elem_t));

    if (game_elem == NULL)
        return NULL;
    game_elem->list_item = create_list_item();
    game_elem->list_npc = get_all_pnj();
    game_elem->list_spell = create_list_spell();
    game_elem->list_mob = create_list_mob(game_elem);
    game_elem->player = NULL;
    game_elem->mob_in_map = malloc(sizeof(bot_t *) * NB_MOB_ON_MAP);
    game_elem->mob_in_map[0] = NULL;
    if (game_elem->list_item == NULL || game_elem->list_mob == NULL)
        return NULL;
    if (game_elem->list_npc == NULL || game_elem->list_spell == NULL)
        return NULL;
    return game_elem;
}

static thread_data_t *set_thread(void)
{
    thread_data_t *thread = malloc(sizeof(thread_data_t));

    if (thread == NULL)
        return NULL;
    thread->stop_thread = false;
    thread->prev_dest->x = NOT_SET;
    thread->sub_thread = NULL;
    thread->sub_thread_data = NULL;
    return thread;
}

program_elem_t *set_all_elem(void)
{
    program_elem_t *all_elem = malloc(sizeof(program_elem_t));

    if (all_elem == NULL)
        return NULL;
    all_elem->elem_win = set_elem_win();
    all_elem->elem_game = set_game_elem();
    all_elem->t_data = set_thread();
    return all_elem;
}
