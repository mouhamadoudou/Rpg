/*
** EPITECH PROJECT, 2022
** how_to_play.c
** File description:
** how_top_play
*/

#include <stdlib.h>
#include "my_rpg.h"

static void detect_key_h(window_elem_t *elem_win, int *pressed,
                        bool *active_menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && !(elem_win->out_help)) {
        *pressed = 1;
        *active_menu = true;
    }
    return;
}

static sfText **set_tuto_txt(void)
{
    sfText **stat = malloc(sizeof(sfText *) * 6);

    stat[0] = create_text("How To Play", &sfWhite, 50, &(sfVector2f)
                        { 700, 100 });
    stat[1] = create_text("Arrow:     to move the player", &sfWhite, 30,
                        &(sfVector2f) { 100, 300 });
    stat[2] = create_text("1 and 2:     to attack", &sfWhite, 30,
                        &(sfVector2f) { 100, 450 });
    stat[3] = create_text("S:                to display player's stats", 
                        &sfWhite, 30, &(sfVector2f) { 100, 600 });
    stat[4] = create_text("Escape:   to display pause menu", &sfWhite, 30, 
                        &(sfVector2f) { 100, 750 });
    stat[5] = create_text("E:                to interact with NPC", &sfWhite,
                        30, &(sfVector2f) { 100, 900 });
    return stat;
}

void get_how_to_play(program_elem_t *all_elem)
{
    int pressed = 0;
    bool active_menu = false;
    sfSprite *opacity = set_opacity();
    sfText **content;

    detect_key_h(all_elem->elem_win, &pressed, &active_menu);
    if (active_menu)
        content = set_tuto_txt();
    while (active_menu && sfRenderWindow_isOpen(all_elem->elem_win->window)) {
        detect_end_pause(&pressed, all_elem->elem_win, &active_menu, 7);
        display_background_pause(all_elem, opacity);
        display_all_text(content, 6, all_elem->elem_win->window);
        sfRenderWindow_display(all_elem->elem_win->window);
        free_text_tuto(active_menu, content, 6);
    }
    sfTexture_destroy(sfSprite_getTexture(opacity));
    sfSprite_destroy(opacity);
    return;
}
