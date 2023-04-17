/*
** EPITECH PROJECT, 2022
** lib2.c
** File description:
** lib2
*/
#include <stdlib.h>
#include <unistd.h>
#include "rpg_struct.h"
#include "my.h"

int my_getnbr(char const *str)
{
    int neg = 1;
    int value_0 = 48;
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-' || str[i] == '+') {
            neg = neg * -1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result += (str[i] - value_0);
        } else {
            return neg * result;
        }
    }
    return neg * result;
}

size_t big_array_len(void *array)
{
    void ***big_array = (void ***)array;
    size_t i = 0;

    while (big_array[i] != NULL)
        ++i;
    return i;
}

int nb_dig_int(int nb)
{
    int i = 0;
    int neg = 0;

    if (nb < 0) {
        neg = 1;
        nb *= -1;
    }
    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return i + neg;
}

static char *get_final_str(char *str)
{
    str = my_revstr(str);
    str += 1;
    if (str[0] == '0')
        str[0] = '-';
    return str;
}

char *int_to_str(int nb)
{
    int len = nb_dig_int(nb);
    char *str;
    int i = 0;

    if (nb < 0) {
        str = malloc(sizeof(char) * (len + 3));
        str[len + 2] = '-';
        str[len + 3] = '\0';
        nb *= -1;
    } else {
        str = malloc(sizeof(char) * (len + 2));
        str[len + 1] = '\0';
    }
    for (; i <= len; i++) {
        str[i] = (nb % 10) + 48;
        nb = nb / 10;
    }
    return get_final_str(str);
}