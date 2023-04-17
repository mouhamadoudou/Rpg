/*
** EPITECH PROJECT, 2022
** my_arraylen.c
** File description:
** calculate the length of an array of strings
*/
#include <unistd.h>

int my_arraylen(void *array)
{
    void **v_array = (void **)array;
    int i = 0;

    while (v_array[i] != NULL) {
        ++i;
    }
    return (i);
}
