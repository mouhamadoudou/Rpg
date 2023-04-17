/*
** EPITECH PROJECT, 2021
** my_memset.c
** File description:
** set mem to 0
*/

char *my_memset(char *str, int i, char fill)
{
    while (i != 0) {
        --i;
        str[i] = fill;
    }
    return (str);
}
