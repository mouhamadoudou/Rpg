/*
** EPITECH PROJECT, 2022
** save_menu.c
** File description:
** save_menu
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

void set_pos_btn(int i, float *pos_x, float *pos_y)
{
    if (i == 3 || i == 6) {
        *pos_y += 100;
        *pos_x = 350;
    } else
        *pos_x += 200;

    return;
}

static char *concat_str_n_int(char *str, int nb)
{
    int len = my_strlen(str) + nb_dig_int(nb);
    char *final_str = malloc(sizeof(char) * (len + 1));

    my_strcpy_index(final_str, str, 0);
    my_strcpy_index(final_str, int_to_str(nb), my_strlen(str));

    final_str[len] = '\0';
    return final_str;
}

button_t *set_btn_save(int nb_file)
{
    button_t *btn = malloc(sizeof(button_t) * nb_file);
    char *content_button;
    float pos_x = 150;
    float pos_y = 400;

    btn = malloc(sizeof(sfText *) * nb_file);
    for (int i = 0; i < nb_file && i < 9; i++) {
        set_pos_btn(i, &pos_x, &pos_y);
        content_button = concat_str_n_int("game ", i + 1);
        btn[i].hover = false;
        btn[i].pos.x = pos_x;
        btn[i].pos.y = pos_y;
        btn[i].content = create_text(content_button, &sfWhite, 40, \
        &(sfVector2f){ pos_x, pos_y });
    }
    return btn;
}

button_t *found_no_file(void)
{
    button_t *btn = malloc(sizeof(button_t));

    btn[0].content = create_text("No map saved !", &sfWhite, 50, &(sfVector2f) {650, 600});
    btn[0].pos.x = 650;
    btn[0].pos.y = 600;
    btn[0].hover = false;

    return btn;
}

int click_text_menu(int nb, sfRenderWindow *window,
                    bool mouse_left)
{
    sfVector2i mouse = sfMouse_getPosition(window);
    int x = mouse.x;
    int y = mouse.y;
    int pos_x = 150;
    int pos_y = 400;

    for (int i = 0; i < nb && i < 9; i++) {
        if (i == 3 || i == 6) {
            pos_y += 100;
            pos_x = 350;
        } else
            pos_x += 200;
        if ((x <= pos_x + 80 && x >= pos_x) && (y <= pos_y + 43 && y >= pos_y)
            && mouse_left)
            return i + 1;
    }
    return 0;
}

static int click_btn_save(int nb, button_t *btn)
{
    for (int i = 0; i < nb; i++)
        if (btn[i].hover && sfMouse_isButtonPressed(sfMouseLeft))
            return i + 1;
    return 0;
}

void load_game(program_elem_t *all_elem, int choice)
{
    char *filepath = concat_nb_n_path("/save/game", choice, ".legend");
    size_t len = 0;
    char *line = NULL;
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return;
    getline(&line, &len, file);
    all_elem->elem_game->player->skin = my_getnbr(line);
    getline(&line, &len, file);
    all_elem->elem_win->init_pos_x = my_getnbr(line);
    getline(&line, &len, file);
    all_elem->elem_win->init_pos_y = my_getnbr(line);
    fclose(file);
    return;
}

int saved_game(map_t **bg, sfText *logo_game, program_elem_t *all_elem)
{
    int nb_file = get_nb_file("./save");
    button_t *btn;
    int choice_game = 0;
    sfSprite *opacity = set_opacity();

    if (nb_file == 0) {
        btn = found_no_file();
        nb_file++;
    } else
        btn = set_btn_save(nb_file);
    while (sfRenderWindow_isOpen(all_elem->elem_win->window) && choice_game == 0 && !(sfKeyboard_isKeyPressed(sfKeyEscape))) {
        sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
        move_background(bg);
        display_texture(bg, all_elem->elem_win->window);
        sfRenderWindow_drawSprite(all_elem->elem_win->window, opacity, NULL);
        sfRenderWindow_drawText(all_elem->elem_win->window, logo_game, NULL);
        hover_btn(btn, *all_elem->elem_win, nb_file, 250);
        display_btn(btn, nb_file, all_elem->elem_win->window);
        handle_event(all_elem);
        choice_game = click_btn_save(nb_file, btn);
        sfRenderWindow_display(all_elem->elem_win->window);
    }
    if (choice_game != 0) {
        load_game(all_elem, choice_game);
        return all_elem->elem_game->player->skin;
    }
    return 0;
}
