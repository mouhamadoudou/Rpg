/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** my_strncat
*/
#include <stddef.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;
    int len_str = 0;

    while (dest[j] != '\0') {
        j++;
    }
    while (src[i] != '\0' && i < nb) {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}
