/*
** EPITECH PROJECT, 2022
** game_loop.c
** File description:
** game_loop
*/

#include "my_rpg.h"
#include "mob.h"
#include "dialog.h"

void put_out_menu(program_elem_t *all_elem)
{
    if (all_elem->elem_win->out_pause &&
        !(sfKeyboard_isKeyPressed(sfKeyEscape)))
        all_elem->elem_win->out_pause = false;
    else if (all_elem->elem_win->out_help && !(sfKeyboard_isKeyPressed(sfKeyH)))
        all_elem->elem_win->out_help = false;
    if (all_elem->elem_win->out_stat && !(sfKeyboard_isKeyPressed(sfKeyS)))
        all_elem->elem_win->out_stat = false;
    if (all_elem->elem_game->player->in_dialog == true)
        display_dialog(all_elem->elem_game->dialog_elem,
                    all_elem->elem_win);
    return;
}

int draw_background(program_elem_t *all_elem, sfCircleShape *circle)
{
    int quit;

    handle_event(all_elem);
    sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
    quit = pause_menu(all_elem);
    get_stat_loop(all_elem);
    get_how_to_play(all_elem);
    get_direction(all_elem->elem_game->player);
    get_anim_player(all_elem->elem_game->player);
    display_texture(all_elem->elem_win->map, all_elem->elem_win->window);
    sfRenderWindow_drawSprite(all_elem->elem_win->window,
                            all_elem->elem_game->player->player.sprite, NULL);
    snow(0, circle, (sfVector2f){0, 0}, all_elem->elem_win);
    return quit;
}

int display_element(program_elem_t *all_elem, int quit)
{
    if (quit == 0) {
        display_pnj(all_elem->elem_game->list_npc, all_elem->elem_win->window);
        move_player(all_elem->elem_win->map, all_elem->elem_game->mob_in_map,
        all_elem->elem_game->list_npc);
        display_bar(all_elem->elem_game->player->mana_bar,
                    all_elem->elem_game->player->life_bar,
                    all_elem->elem_win->window);
        display_mob(all_elem->elem_game->mob_in_map,
                    all_elem->elem_win->window);
        compute_bar(all_elem->elem_game->player,
                    all_elem->elem_game->player->life_bar,  1);
        put_out_menu(all_elem);
        return get_player_dead(all_elem->elem_game->player);
    }
    return quit;
}

int game_loop(program_elem_t *all_elem)
{
    int quit = 0;
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, 2);
    all_elem->elem_game->mob_in_map[0] = create_in_game_mob(
        all_elem->elem_game->mob_data[0], all_elem->elem_game->list_mob);
    while (sfRenderWindow_isOpen(all_elem->elem_win->window) &&
        !(sfKeyboard_isKeyPressed(sfKeyQ)) && quit == 0) {
        quit = draw_background(all_elem, circle);
        quit = display_element(all_elem, quit);
        sfRenderWindow_display(all_elem->elem_win->window);
    }
    all_elem->t_data->stop_thread = true;
    free_map(all_elem->elem_win->map);
    free_bar(all_elem->elem_game->player->mana_bar,
            all_elem->elem_game->player->life_bar);
    free_pnj(all_elem->elem_game->list_npc);
    return quit;
}