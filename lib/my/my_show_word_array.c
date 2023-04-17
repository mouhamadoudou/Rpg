/*
** EPITECH PROJECT, 2021
** my_show_word_array.c
** File description:
** displays the content of an array of words.
*/
#include <stddef.h>

int my_putstr(char *str);

void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}
