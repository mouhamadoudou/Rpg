/*
** EPITECH PROJECT, 2022
** stat_menu.c
** File description:
** stat_menu
*/

#include <stdlib.h>
#include "my_rpg.h"

static void detect_key_s(window_elem_t *elem_win, int *pressed,
                        bool *active_menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && !(elem_win->out_stat)) {
        *pressed = 1;
        *active_menu = true;
    }
    return;
}

char **put_stat_to_str(program_elem_t *all_elem)
{
    char **stats = malloc(sizeof(char *) * 5);

    stats[0] = int_to_str(all_elem->elem_game->player->stat.hp);
    stats[1] = int_to_str(all_elem->elem_game->player->stat.attack);
    stats[2] = int_to_str(all_elem->elem_game->player->stat.resistance);
    stats[3] = int_to_str(all_elem->elem_game->player->stat.mana);
    stats[4] = int_to_str(all_elem->elem_game->player->level);
    return stats;
}

void fill_stats_txt(sfText **stat, char **stats_txt)
{
    stat[0] = create_text("Stats", &sfWhite, 50, &(sfVector2f) { 800, 100 });
    stat[1] = create_text("Life:", &sfWhite, 30, &(sfVector2f) { 750, 400 });
    stat[2] = create_text("Attack:", &sfWhite, 30, &(sfVector2f) { 750, 500 });
    stat[3] = create_text("Defense:", &sfWhite, 30, &(sfVector2f) { 750, 600 });
    stat[4] = create_text(stats_txt[0], &sfWhite, 30, &(sfVector2f)
                        { 1000, 400 });
    stat[5] = create_text(stats_txt[1], &sfWhite, 30, &(sfVector2f)
                        { 1000, 500 });
    stat[6] = create_text(stats_txt[2], &sfWhite, 30, &(sfVector2f)
                        { 1000, 600 });
    stat[7] = create_text("Mana:", &sfWhite, 30, &(sfVector2f) { 750, 700 });
    stat[8] = create_text(stats_txt[3], &sfWhite, 30, &(sfVector2f)
                        { 1000, 700 });
    stat[9] = create_text("Level:", &sfWhite, 30, &(sfVector2f) { 750, 800 });
    stat[10] = create_text(stats_txt[4], &sfWhite, 30, &(sfVector2f)
                        { 1000, 800 });
    return;
}

static sfText **set_stat_txt(program_elem_t *all_elem)
{
    sfText **stat = malloc(sizeof(sfText *) * 11);
    char **stats_txt = put_stat_to_str(all_elem);

    fill_stats_txt(stat, stats_txt);
    for (int i = 0; i < 5; i++) {
        stats_txt[i] -= 1;
        free(stats_txt[i]);
    }
    free(stats_txt);
    return stat;
}

void get_stat_loop(program_elem_t *all_elem)
{
    int pressed = 0;
    bool active_menu = false;
    sfSprite *opacity = set_opacity();
    sfText **stat_txt;

    detect_key_s(all_elem->elem_win, &pressed, &active_menu);
    if (active_menu)
        stat_txt = set_stat_txt(all_elem);
    while (active_menu && sfRenderWindow_isOpen(all_elem->elem_win->window)) {
        detect_end_pause(&pressed, all_elem->elem_win, &active_menu, 18);
        display_background_pause(all_elem, opacity);
        display_all_text(stat_txt, 11, all_elem->elem_win->window);
        sfRenderWindow_display(all_elem->elem_win->window);
        free_text_tuto(active_menu, stat_txt, 11);
    }
    sfTexture_destroy(sfSprite_getTexture(opacity));
    sfSprite_destroy(opacity);
    return;
}
