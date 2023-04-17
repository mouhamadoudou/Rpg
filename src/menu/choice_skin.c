/*
** EPITECH PROJECT, 2022
** choice_skin.c
** File description:
** choice_skin
*/

#include <stdlib.h>
#include "my_rpg.h"

static player_t **set_skin(void)
{
    player_t **skin = malloc(sizeof(player_t *) * 3);
    float x = 600;
    float y = 500;

    skin[0] = load_player("assets/skin/mage.png");
    skin[1] = load_player("assets/skin/archer.png");
    skin[2] = load_player("assets/skin/knight.png");
    for (int i = 0; i < 3; i++) {
        skin[i]->player.cord.x = x;
        skin[i]->player.cord.y = y;
        skin[i]->anim.right = true;
        sfSprite_setPosition(skin[i]->player.sprite, skin[i]->player.cord);
        sfSprite_setScale(skin[i]->player.sprite, (sfVector2f) { 3, 3 });
        x += 250;
    }
    return skin;
}

static void draw_skin(player_t **skin, sfRenderWindow *window)
{
    for (int i = 0; i < 3; i++) {
        get_anim_player(skin[i]);
        sfSprite_setTextureRect(skin[i]->player.sprite, skin[i]->player.rect);
        sfRenderWindow_drawSprite(window, skin[i]->player.sprite, NULL);
    }
    return;
}

static sfText **set_all_text_skin(void)
{
    sfText **all_text = malloc(sizeof(sfText *) * 4);

    all_text[0] = create_text("Choose your skin:", &sfWhite, 30, &(sfVector2f)
    { 710, 380 });
    all_text[1] = create_text("Magician", &sfWhite, 20, &(sfVector2f) 
    { 605, 660 });
    all_text[2] = create_text("Archer", &sfWhite, 20, &(sfVector2f) 
    { 863, 660 });
    all_text[3] = create_text("Knight", &sfWhite, 20, &(sfVector2f) 
    { 1120, 660 });
    return all_text;
}

void display_background_menu(program_elem_t *all_elem, map_t **bg,
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

int choice_skin_loop(map_t **bg, sfText *logo_game, program_elem_t *all_elem)
{
    sfSprite *opacity = set_opacity();
    player_t **skin = set_skin();
    sfText **all_text = set_all_text_skin();
    sfSprite *cursor = set_cursor();
    int choice_skin = 1;
    int can_move_cursor = 0;

    while (sfRenderWindow_isOpen(all_elem->elem_win->window) &&
            !(sfKeyboard_isKeyPressed(sfKeyEscape)) &&
            !(sfKeyboard_isKeyPressed(sfKeyEnter))) {
        display_background_menu(all_elem, bg, opacity, logo_game);
        draw_skin(skin, all_elem->elem_win->window);
        display_text(all_elem->elem_win->window, all_text, 4);
        loop_cursor(&can_move_cursor, &choice_skin, cursor, all_elem);
        sfRenderWindow_display(all_elem->elem_win->window);
    }
    destroy_all(all_text, skin, opacity, cursor);
    if (sfKeyboard_isKeyPressed(sfKeyEnter))
        return choice_skin;
    return 0;
}
