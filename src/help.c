/*
** EPITECH PROJECT, 2022
** help.c
** File description:
** help
*/

#include <unistd.h>
#include "my_rpg.h"

int get_col_map(map_t *map)
{
    int i = 0;

    while (map[i].texture != NULL)
        i++;
    return i;
}

void m_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (src[i] == '\0') {
        dest[i] = '\0';
    }
}

int m_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

void m_putstr(char *str)
{
    int len = m_strlen(str);

    write(1, str, len);

    return;
}

void help(void)
{
    m_putstr("help\n");

    return;
}
