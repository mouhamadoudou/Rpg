/*
** EPITECH PROJECT, 2022
** main_menu.c
** File description:
** main_menu
*/

#include "my_rpg.h"

void detect_end_pause(int *pressed, window_elem_t *elem_win, bool *active_menu,
                    int num_key)
{
    if (!(sfKeyboard_isKeyPressed(num_key)))
        *pressed = 0;
    else if (sfKeyboard_isKeyPressed(num_key) && *pressed == 0) {
        if (num_key == 7)
            elem_win->out_help = true;
        else if (num_key == 18)
            elem_win->out_stat = true;
        else
            elem_win->out_pause = true;
        *active_menu = false;
    }
    return;
}

sfSprite *set_opacity(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("assets/opacity.png", NULL);
    sfIntRect rect = (sfIntRect){ .left = 0, .top = 0, .width = 1800,
                    .height = 1200 };
    sfVector2f pos = (sfVector2f){ 0, 0 };

    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);

    return sprite;
}

static void display_element_menu(sfSprite *bg, program_elem_t *all_elem,
                                sfSprite *opacity, sfText *logo_game)
{
    sfRenderWindow_clear(all_elem->elem_win->window, sfBlack);
    move_background(bg);
    display_texture(bg, all_elem->elem_win->window);
    sfRenderWindow_drawSprite(all_elem->elem_win->window, opacity, NULL);
    sfRenderWindow_drawText(all_elem->elem_win->window, logo_game, NULL);
    return;
}

void get_main_menu(program_elem_t *all_elem, sfText *logo_game, int *skin)
{
    char **map = get_map("map/menu_map.txt");
    map_t **background = get_all_obj(map, 0, 0);
    button_t *all_btn = set_all_btn();
    sfSprite *opacity = set_opacity();
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f pos = {0, 0};
    sfMusic *music = set_music_back("./assets/music/menu_music.ogg");

    sfCircleShape_setRadius(circle, 2);
    sfCircleShape_setFillColor(circle, sfWhite);
    while (sfRenderWindow_isOpen(all_elem->elem_win->window) && *skin == 0) {
        display_element_menu(background, all_elem, opacity, logo_game);
        display_btn(all_btn, 4, all_elem->elem_win->window);
        hover_btn(all_btn, *all_elem->elem_win, 4, 290);
        *skin = click_btn(all_btn, all_elem, background, logo_game);
        handle_event(all_elem);
        sfRenderWindow_display(all_elem->elem_win->window);
    }
    free_map(background);
    free_main_menu(map, all_btn, opacity, logo_game);
    sfMusic_destroy(music);
}

void display_all_text(sfText **txt, int nb_txt, sfRenderWindow *window)
{
    for (int i = 0; i < nb_txt; i++)
        sfRenderWindow_drawText(window, txt[i], NULL);
    return;
}
