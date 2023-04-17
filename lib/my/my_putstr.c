/*
** EPITECH PROJECT, 2021
** putstr2
** File description:
** print string
*/
#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char *str)
{
    int len = my_strlen((char const *)str);

    write(1, str, len);
    return (0);
}
