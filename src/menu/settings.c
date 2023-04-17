/*
** EPITECH PROJECT, 2022
** settings.c
** File description:
** settings
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "rpg_macro.h"

static void change_sound(window_elem_t *elem_win, int *press)
{
    sfVector2i mouse = sfMouse_getPosition(elem_win->window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && *press == 0)
        *press = 1;
    else if (sfMouse_isButtonPressed(sfMouseLeft) && *press == 1)
        *press = -1;
    if (*press == -1 && !(sfMouse_isButtonPressed(sfMouseLeft)))
        *press = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && mouse.x <= 150 &&
        mouse.x >= 50) {
        if (mouse.y <= 160 && mouse.y >= 50 && elem_win->sound_is_on &&
            *press == 1)
            elem_win->sound_is_on = false;
        else if (mouse.y <= 160 && mouse.y >= 50 && *press == 1)
            elem_win->sound_is_on = true;
    }
    return;
}

sfText **set_text_settings(void)
{
    sfText **text = malloc(sizeof(sfText *) * 4);

    text[0] = create_text("Choose your FPS:", &sfWhite, 30, &(sfVector2f)
                        { 710, 380 });
    text[1] = create_text("60", &sfWhite, 30, &(sfVector2f) { 625, 560 });
    text[2] = create_text("90", &sfWhite, 30, &(sfVector2f) { 873, 560 });
    text[3] = create_text("144", &sfWhite, 30, &(sfVector2f) { 1120, 560 });
    return text;
}

void set_fps(int choice_fps, program_elem_t *all_elem)
{
    if (choice_fps == 1)
        sfRenderWindow_setFramerateLimit(all_elem->elem_win->window, 60);
    else if (choice_fps == 2)
        sfRenderWindow_setFramerateLimit(all_elem->elem_win->window, 90);
    else
        sfRenderWindow_setFramerateLimit(all_elem->elem_win->window, 144);
    return;
}

static void display_back(program_elem_t *all_elem, map_t **bg,
                        sfSprite *opacity, sfText *logo_game)
{
    handle_event(all_elem);
    sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
    move_background(bg);
    display_texture(bg, all_elem->elem_win->window);
    sfRenderWindow_drawSprite(all_elem->elem_win->window, opacity, NULL);
    sfRenderWindow_drawText(all_elem->elem_win->window, logo_game, NULL);
    return;
}

int settings_loop(map_t **bg, sfText *logo_game, program_elem_t *all_elem)
{
    sfSprite *opacity = set_opacity();
    sfSprite **sound = set_sound();
    sfSprite *cursor = set_cursor();
    sfText **text = set_text_settings();
    int mouse_pressed = 0;
    int choice_fps = 1;
    int can_move_cursor = 0;

    while (sfRenderWindow_isOpen(all_elem->elem_win->window) && !(ESC) &&
        !(ENTER)) {
        display_back(all_elem, bg, opacity, logo_game);
        change_sound(all_elem->elem_win, &mouse_pressed);
        display_sound(sound, *all_elem->elem_win);
        loop_cursor(&can_move_cursor, &choice_fps, cursor, all_elem);
        display_text(all_elem->elem_win->window, text, 4);
        sfRenderWindow_display(all_elem->elem_win->window);
    }
    set_fps(choice_fps, all_elem);
    free_settings(opacity, cursor, sound, text);
    return 0;
}
