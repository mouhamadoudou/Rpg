/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** getline struct function
*/
#include <stdlib.h>
#include "rpg_struct.h"

getline_elem_t *create_getline_struct(const char *filename)
{
    getline_elem_t *elem = malloc(sizeof(getline_elem_t) * 1);

    if (elem == NULL)
        return (NULL);
    elem->stream = fopen(filename, "r");
    if (elem->stream == NULL) {
        free(elem);
        return (NULL);
    }
    elem->lineptr = NULL;
    elem->n = 0;
    return (elem);
}

void free_getline_elem(getline_elem_t *elem)
{
    free(elem->lineptr);
    fclose(elem->stream);
    free(elem);
}
