/*
** EPITECH PROJECT, 2022
** lib.c
** File description:
** lib
*/

#include <unistd.h>
#include "my_rpg.h"
#include "my.h"

int my_strlen_w_coma(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i] != '\0') {
        if (str[i] == ',')
            res++;
        i++;
    }
    return res;
}

int my_tablen(map_t **map)
{
    int i = 0;

    while (map[i] != NULL)
        i++;
    return i;
}

int map_line_len(map_t *map)
{
    int i = 0;

    while (map[i].texture != NULL)
        ++i;
    return (i);
}

int m_getnbr(char *line, int j)
{
    int neg = 1;
    int value_0 = 48;
    int result = 0;

    while (line[j] != ',' && line[j] != '\n') {
        if (line[j] == '-' || line[j] == '+')
            neg = neg * -1;
        else if (line[j] >= '0' && line[j] <= '9') {
            result = result * 10;
            result += (line[j] - value_0);
        } else
            return neg * result;
        j++;
    }
    return neg * result;
}

void display_error(char *str)
{
    write(2, str, my_strlen(str));
    return;
}