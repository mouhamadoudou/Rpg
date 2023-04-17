/*
** EPITECH PROJECT, 2022
** struc.h
** File description:
** struc.h
*/

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Thread.h>
#include "rpg_macro.h"

typedef struct game_object {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f cord;
    sfIntRect rect;
} game_object_t;

typedef struct map_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int last_line;
    int last_col;
    bool is_block;
    sfClock *clock;
    sfTime time;
    float sec;
} map_t;

typedef struct animation_s {
    bool left;
    bool right;
    bool up;
    bool down;
    bool atck_1;
    bool atck_2;
    float sec;
    sfClock *clock;
    sfTime time;
    float sec_atck;
    sfClock *clock_atck;
    sfTime time_atck;
} animation_t;

typedef struct clock_elem_s {
    sfTime time;
    sfClock *clock;
} clock_elem_t;

typedef struct window_elem_s {
    sfRenderWindow *window;
    sfEvent event;
    map_t **map;
    bool sound_is_on;
    bool out_pause;
    bool out_stat;
    bool out_help;
    int init_pos_x;
    int init_pos_y;
} window_elem_t;

typedef struct getline_elem_s {
    char *lineptr;
    size_t n;
    __ssize_t to_malloc;
    FILE *stream;
} getline_elem_t;

typedef struct cycle_counter_s {
    int i;
    int j;
    int k;
} cycle_counter_t;
