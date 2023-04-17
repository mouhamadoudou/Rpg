/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is the char an I for different offset
*/
#include "dialog.h"

int is_char_i_or_m(char c)
{
    if (c == 'i' || c == 'I') {
        return (5);
    } else if (c == 'm' || c == 'M') {
        return (17);
    } else {
        return (15);
    }
}
