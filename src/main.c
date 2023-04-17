/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include "dialog.h"
#include "my_rpg.h"
#include "rpg_thread.h"
#include "mob.h"

void handle_event(program_elem_t *all_elem)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(all_elem->elem_win->window, &event)) {
        close_window(all_elem->elem_win->window, event);
        if (event.type == sfEvtKeyPressed)
            manage_event_dialog(&event, all_elem);
    }
    return;
}

char *get_good_skin(int skin)
{
    if (skin == 1)
        return "assets/skin/mage.png";
    else if (skin == 2)
        return "assets/skin/archer.png";
    else
        return "assets/skin/knight.png";
}

void loading_menu(program_elem_t *all_elem, int *skin)
{
    sfText *logo_game = create_text("Magic World", &sfWhite, 120,
                                    &(sfVector2f) { 680, 430 });

    sfText_setFont(logo_game, sfFont_createFromFile(
                "./assets/font/wrestlemania.ttf"));
    sfRenderWindow_drawText(all_elem->elem_win->window, logo_game, NULL);
    sfRenderWindow_display(all_elem->elem_win->window);
    sfText_setPosition(logo_game, (sfVector2f) { 680, 100 });
    get_main_menu(all_elem, logo_game, skin);
}

void fill_elem_game(program_elem_t *all_elem, int skin, char **map,
                    sfText *loading)
{
    if (skin != -1) {
        sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
        sfRenderWindow_drawText(all_elem->elem_win->window, loading, NULL);
        sfRenderWindow_display(all_elem->elem_win->window);
        all_elem->elem_win->map = get_all_obj(map,
                                            all_elem->elem_win->init_pos_x,
                                            all_elem->elem_win->init_pos_y);
        all_elem->elem_game->list_npc = get_all_pnj();
        all_elem->elem_game->player = load_player(get_good_skin(skin));
        all_elem->elem_game->player->life_bar = create_bar(1, "assets/red.png");
        all_elem->elem_game->player->mana_bar = 
                                            create_bar(2, "assets/blue.png");
        all_elem->elem_game->player->in_dialog = false;
    }
}

int loading_game(program_elem_t *all_elem, int skin)
{
    char **map = get_map("map/menu_map.txt");
    sfText *loading = create_text("Loading the map...", &sfWhite, 30,
                                &(sfVector2f) { 730, 500 });

    fill_elem_game(all_elem, skin, map, loading);
    sfFont_destroy(sfText_getFont(loading));
    sfText_destroy(loading);
    free_array(map);
    if (skin == -1)
        return -1;
    else
        return 1;
}

int main(int ac, char **av)
{
    program_elem_t *all_elem = set_all_elem();
    int skin = 0;
    sfThread *thread = NULL;
    int quit = 1;

    if (all_elem == NULL)
        return 84;
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    launch_thread_detect(all_elem, &thread);
    while (quit != 0 && quit != -1) {
        loading_menu(all_elem, &skin);
        quit = loading_game(all_elem, skin);
        if (quit != -1) {
            all_elem->elem_game->player->skin = skin;
            quit = game_loop(all_elem);
        }
        skin = 0;
        sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
    }
    if (thread != NULL) {
        all_elem->t_data->stop_thread = true;
        sfThread_wait(thread);
        sfThread_destroy(thread);
    }
    return 0;
}
