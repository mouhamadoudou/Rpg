/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to free dialog elem
*/
#include <stdlib.h>
#include "dialog.h"

static void free_text_array(sfText **array)
{
    int i = 0;

    while (array[i] != NULL) {
        sfText_destroy(array[i]);
        ++i;
    }
    free(array);
}

static void free_dialog(int nb_dialog, sfText ***dialog_text)
{
    int i = 0;

    while (i < nb_dialog) {
        free_text_array(dialog_text[i]);
        ++i;
    }
    free(dialog_text);
}

void free_dialog_elem(dialog_t *dialog)
{
    free(dialog->caracter_dialog);
    free_text_array(dialog->names);
    free_dialog(dialog->nb_dialog, dialog->dialog_text);
    free(dialog);
}
