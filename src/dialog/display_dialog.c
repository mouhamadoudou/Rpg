/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function in relation with display of dialog
*/
#include "dialog.h"

void display_texture(map_t **tab_obj, sfRenderWindow *window);

static void wait_write_dialog(sfTime *time, sfClock *clock)
{
    static float seconds;

    *time = sfClock_getElapsedTime(clock);
    seconds = time->microseconds / 1000000.0;
    while (seconds < 0.1) {
        *time = sfClock_getElapsedTime(clock);
        seconds = time->microseconds / 1000000.0;
    }
    sfClock_restart(clock);
}

static int is_space_bar_pressed(sfEvent *event)
{
    if (event->key.code == sfKeySpace)
        return (0);
    else
        return (1);
}

static int is_dialog_skip(dialog_status_t *status, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (2);
        }
        if (event.type == sfEvtKeyPressed)
            return (is_space_bar_pressed(&event));
    }
    return *status == DIALOG_NORMAL ? 1 : 0;
}

int display_dialog(dialog_t *dialog_elem, window_elem_t *elem_win)
{
    int i = 0;

    sfRenderWindow_drawText(elem_win->window, dialog_elem->names
                            [dialog_elem->caracter_dialog
                            [dialog_elem->displayed_dialog] - 1], NULL);
    while (i < dialog_elem->nb_char_to_display) {
        sfRenderWindow_drawText(elem_win->window, dialog_elem->dialog_text
                                [dialog_elem->displayed_dialog][i], NULL);
        ++i;
    }
    if (dialog_elem->dialog_text[dialog_elem->displayed_dialog]
        [dialog_elem->nb_char_to_display + 1] != NULL) {
        ++dialog_elem->nb_char_to_display;
    }
    return (DIALOG_NORMAL);
}
