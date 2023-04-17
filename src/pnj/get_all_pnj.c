/*
** EPITECH PROJECT, 2022
** get_all_pnj.c
** File description:
** get_all_pnj
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

static void fill_pnj(npc_t *pnj, char **parsed_content, int j)
{
    int id;
    float x;
    float y;

    pnj->name = malloc(sizeof(char) *
                    (my_strlen(parsed_content[j]) + 1));
    pnj->name = parsed_content[j];
    pnj->name[my_strlen(parsed_content[j])] = '\0';
    id = my_getnbr(parsed_content[j + 1]);
    x = my_getnbr(parsed_content[j + 2]);
    y = my_getnbr(parsed_content[j + 3]);
    pnj->active_dialog = 0;
    pnj->texture = malloc(sizeof(game_object_t));
    create_pnj(id, &(sfVector2f){x, y}, &(sfIntRect){.left = 0, .top = 0,
            .width = 31, .height = 45}, pnj);
    return;
}

npc_t *get_all_pnj(void)
{
    int nb_pnj = get_nb_line("conf/pnj.conf") / 4;
    npc_t *all_pnj = malloc(sizeof(npc_t) * (nb_pnj + 1));
    char *content = get_content_file("conf/pnj.conf");
    char **parsed_content = str_to_word_array(content, '\n');
    int j = 0;

    for (int i = 0; i < nb_pnj; i++) {
        fill_pnj(&all_pnj[i], parsed_content, j);
        j += 4;
    }
    all_pnj[nb_pnj].name = NULL;
    return all_pnj;
}

void display_pnj(npc_t *all_pnj, sfRenderWindow *window)
{
    for (int i = 0; all_pnj[i].name != NULL; i++) {
        sfRenderWindow_drawSprite(window, all_pnj[i].texture->sprite, NULL);
        sfSprite_setPosition(all_pnj[i].texture->sprite, all_pnj[i].
                            texture->cord);
    }
    return;
}
