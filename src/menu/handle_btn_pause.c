/*
** EPITECH PROJECT, 2022
** handle_btn_pause.c
** File description:
** handle_btn_pause
*/

#include <stdlib.h>
#include "my_rpg.h"

void display_background_pause(program_elem_t *all_elem, sfSprite *opacity)
{
    handle_event(all_elem);
    sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
    display_texture(all_elem->elem_win->map, all_elem->elem_win->window);
    display_pnj(all_elem->elem_game->list_npc, all_elem->elem_win->window);
    sfRenderWindow_drawSprite(all_elem->elem_win->window,
                            all_elem->elem_game->player->player.sprite, NULL);
    sfRenderWindow_drawSprite(all_elem->elem_win->window, opacity, NULL);
    return;
}

button_t *set_btn_pause(void)
{
    button_t *btn = malloc(sizeof(button_t) * 3);

    btn[0] = fill_button(&choice_skin_loop, (sfVector2f) { 600, 520 }, "Home");
    btn[1] = fill_button(&choice_skin_loop, (sfVector2f) { 810, 520 }, "Save");
    btn[2] = fill_button(&choice_skin_loop, (sfVector2f) { 1020, 520 }, "Quit");
    return btn;
}

void go_to_home(bool *go_to_menu, program_elem_t *all_elem, button_t *btn)
{
    sfText_setColor(btn[0].content, sfColor_fromRGB(118, 0, 0));
    sfRenderWindow_drawText(all_elem->elem_win->window, btn[0].content,
                            NULL);
    sfRenderWindow_display(all_elem->elem_win->window);
    sfSleep(sfMicroseconds(100000));
    *go_to_menu = true;
}

bool click_btn_pause(button_t *btn, bool *go_to_menu, program_elem_t *all_elem)
{
    if (btn[2].hover && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfText_setColor(btn[2].content, sfColor_fromRGB(118, 0, 0));
        sfRenderWindow_drawText(all_elem->elem_win->window, btn[2].content,
                                NULL);
        sfRenderWindow_display(all_elem->elem_win->window);
        sfSleep(sfMicroseconds(100000));
        return true;
    } else if (btn[0].hover && sfMouse_isButtonPressed(sfMouseLeft))
        go_to_home(go_to_menu, all_elem, btn);
    if (btn[1].hover && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfText_setColor(btn[1].content, sfColor_fromRGB(118, 0, 0));
        sfRenderWindow_drawText(all_elem->elem_win->window, btn[1].content,
                                NULL);
        sfRenderWindow_display(all_elem->elem_win->window);
        save_game(all_elem);
        sfSleep(sfMicroseconds(100000));
    }
    return false;
}
