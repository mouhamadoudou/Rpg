/*
** EPITECH PROJECT, 2022
** my_putstrerror.c
** File description:
** print string on error output
*/
#include <unistd.h>

void my_putcharerror(char c)
{
    write(2, &c, 1);
}

int my_putstrerror(char *str)
{
    while (*str) {
        my_putcharerror(*str);
        str++;
    }
}
