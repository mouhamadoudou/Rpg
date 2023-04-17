/*
** EPITECH PROJECT, 2022
** get_all_obj.c
** File description:
** get_all_obj
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

int go_next_id(int j, char *map)
{
    while (map[j] != ',' && map[j] != '\n')
        j++;
    return j;
}

static void fill_first_tile(map_t **all_obj, int nb_line, int nb_col)
{
    all_obj[0][0].clock = sfClock_create();
    all_obj[0][0].sec = 0.00;
    all_obj[nb_line] = NULL;
    all_obj[0][0].last_line = nb_line;
    all_obj[0][0].last_col = nb_col;
    return;
}

static void fill_map(char **map, map_t **all_obj, int x, int y)
{
    int index_t = 0;
    float i[2] = { 0, 0 };
    int nb_col = my_strlen_w_coma(map[0]);

    for (int k = 0; map[k] != NULL; k++, i[0] = 0, i[1] += 1.2, index_t = 0) {
        all_obj[k] = malloc(sizeof(map_t) * (nb_col + 1));
        for (int j = 0; map[k][j] != '\0'; j++) {
            create_texture(m_getnbr(map[k], j),
                                    &(sfVector2f) { x + (i[0] * 50), y +
                                    (i[1] * 80) }, &(sfIntRect){.left = 0,
                                    .top = 0, .width = 64, .height = 64 },
                                    &all_obj[k][index_t]);
            i[0] += 1.9;
            j = go_next_id(j, map[k]);
            index_t++;
        }
        all_obj[k][nb_col].texture = NULL;
    }
}

map_t **get_all_obj(char **map, int x, int y)
{
    int nb_line = my_arraylen(map);
    int nb_col = my_strlen_w_coma(map[0]);
    map_t **all_obj = malloc(sizeof(map_t *) * (nb_line + 1));

    fill_map(map, all_obj, x, y);
    fill_first_tile(all_obj, nb_line, nb_col);
    return all_obj;
}
