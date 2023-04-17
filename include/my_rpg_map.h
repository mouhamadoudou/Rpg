/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header related to map function
*/

#ifndef MY_RPG_MAP_H_
#define MY_RPG_MAP_H_

#include <SFML/Graphics.h>
#include "rpg_struct.h"

void free_map(map_t **map);
char **get_map(char *filepath);
map_t **get_all_obj(char **map, int x, int y);
int create_texture(int id, sfVector2f *pos, sfIntRect *rect, map_t *object);
void free_map_str(char **map);
int map_line_len(map_t *map);
int my_tablen(map_t **map);

#endif /* !MY_RPG_MAP_H_ */
