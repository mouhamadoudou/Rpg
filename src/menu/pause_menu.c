/*
** EPITECH PROJECT, 2022
** pause_menu.c
** File description:
** pause_menu
*/

#include <stdlib.h>
#include "my_rpg.h"

static void detect_escape(window_elem_t *elem_win, int *pressed,
                        bool *active_menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && !(elem_win->out_pause)) {
        *pressed = 1;
        *active_menu = true;
    }
    return;
}

static void interact_element(button_t *btn, int *pressed, bool *active_menu,
                            window_elem_t *elem_win)
{
    display_btn(btn, 3, elem_win->window);
    detect_end_pause(pressed, elem_win, active_menu, 36);
    sfRenderWindow_display(elem_win->window);
    return;
}

static void manage_background(program_elem_t *all_elem, sfSprite *opacity,
                            sfText *pause_txt, button_t *btn)
{
    display_background_pause(all_elem, opacity);
    sfRenderWindow_drawText(all_elem->elem_win->window, pause_txt, NULL);
    hover_btn(btn, *all_elem->elem_win, 3, 150);
    return;
}

static int get_good_return(bool quit, bool go_to_menu)
{
    if (quit)
        return -1;
    else if (go_to_menu)
        return 1;
    return 0;
}

int pause_menu(program_elem_t *all_elem)
{
    int pressed = 0;
    bool active_menu = false;
    sfSprite *opacity = set_opacity();
    sfText *pause_txt = create_text("Pause", &sfWhite, 50,
                                    &(sfVector2f) { 800, 100 });
    button_t *btn = set_btn_pause();
    bool quit = false;
    bool go_to_menu = false;

    detect_escape(all_elem->elem_win, &pressed, &active_menu);
    while (active_menu && sfRenderWindow_isOpen(all_elem->elem_win->window) &&
        !(quit) && !(go_to_menu)) {
        manage_background(all_elem, opacity, pause_txt, btn);
        quit = click_btn_pause(btn, &go_to_menu, all_elem);
        interact_element(btn, &pressed, &active_menu, all_elem->elem_win);
    }
    free_pause_menu(opacity, pause_txt, btn);
    return get_good_return(quit, go_to_menu);
}
