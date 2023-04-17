/*
** EPITECH PROJECT, 2022
** button.c
** File description:
** button
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"

int click_btn(button_t *btn, program_elem_t *all_elem, map_t **bg, sfText *logo_game)
{
    for (int i = 0; i < 4; i++) {
        if (btn[i].hover && sfMouse_isButtonPressed(sfMouseLeft)) {
            sfText_setColor(btn[i].content, sfColor_fromRGB(118, 0, 0));
            sfRenderWindow_drawText(all_elem->elem_win->window, btn[i].content, NULL);
            sfRenderWindow_display(all_elem->elem_win->window);
            sfSleep(sfMicroseconds(100000));
            return btn[i].pt_fct(bg, logo_game, all_elem);
        } else
            sfText_setColor(btn[i].content, sfWhite);
    }
    return 0;
}

void hover_btn(button_t *btn, window_elem_t elem_win, int nb, int width)
{
    sfVector2i mouse = sfMouse_getPosition(elem_win.window);
    int x = mouse.x;
    int y = mouse.y;

    for (int i = 0; i < nb; i++) {
        if ((x <= btn[i].pos.x + width && x >= btn[i].pos.x) && \
            (y <= btn[i].pos.y + 50 && y >= btn[i].pos.y)) {
            btn[i].hover = true;
        } else
            btn[i].hover = false;
    }
}

void display_btn(button_t *btn, int nb, sfRenderWindow *window)
{
    for (int i = 0; i < nb; i++) {
        if (btn[i].hover)
            sfText_setCharacterSize(btn[i].content, 55);
        else
            sfText_setCharacterSize(btn[i].content, 50);
        sfRenderWindow_drawText(window, btn[i].content, NULL);
    }
    return;
}

button_t fill_button(int (*pt_fct)(map_t **bg, sfText *logo_game, program_elem_t *all_elem), sfVector2f pos, char *content_text)
{
    button_t btn;

    btn.hover = false;
    btn.content = create_text(content_text, &sfWhite, 50, &pos);
    btn.pt_fct = pt_fct;
    btn.pos = pos;
    return btn;
}

int my_test(map_t **bg, sfText *logo_game, program_elem_t *all_elem)
{
    return 0;
}

int quit_game(map_t **bg, sfText *logo_game, program_elem_t *all_elem)
{
    return -1;
}

button_t *set_all_btn(void)
{
    button_t *array_btn = malloc(sizeof(button_t) * 4);

    array_btn[0] = fill_button(&choice_skin_loop, (sfVector2f) { 150, 370 }, "New Game");
    array_btn[1] = fill_button(&my_test, (sfVector2f) { 150, 520 }, "Saved");
    array_btn[2] = fill_button(&settings_loop, (sfVector2f) { 150, 670 }, "Settings");
    array_btn[3] = fill_button(&quit_game, (sfVector2f) { 1600,880 }, "Quit");
    return array_btn;
}
