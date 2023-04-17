/*
** EPITECH PROJECT, 2022
** handle_map.c
** File description:
** handle_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_rpg.h"
#include "rpg_macro.h"
#include "my_rpg_map.h"
#include "my.h"

int get_nb_line(char *filepath)
{
    int nb_line = 0;
    size_t len = 0;
    char *line = NULL;
    FILE *file = fopen(filepath, "r");

    if (file == NULL)
        return (-1);
    while (getline(&line, &len, file) != -1)
        ++nb_line;
    fclose(file);
    free(line);
    return nb_line;
}

static void loop_getline(char **map, __ssize_t to_malloc, int i, char *line)
{
    map[i] = malloc(sizeof(char) * (to_malloc + 1));
    if (map[i] == NULL)
        return;
    m_strcpy(map[i], line);
    map[i][to_malloc] = '\0';
    return;
}

char **get_map(char *filepath)
{
    int nb_line = get_nb_line(filepath);
    char **map = malloc(sizeof(char *) * (nb_line + 1));
    char *line = NULL;
    FILE *file = fopen(filepath, "r");
    size_t len = 0;
    __ssize_t to_malloc = 0;

    if (file == NULL)
        return (NULL);
    for (int i = 0; (to_malloc = getline(&line, &len, file)) != -1; i++)
        loop_getline(map, to_malloc, i, line);
    free(line);
    fclose(file);
    map[nb_line] = NULL;
    return map;
}
