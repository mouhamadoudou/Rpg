/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to create the sfText dialog
*/
#include <stdlib.h>
#include "dialog.h"

static sfText **create_text_name(char **name)
{
    int i = 0;
    int nb_name = my_arraylen(name);
    sfText **names = malloc(sizeof(sfText *) * (size_t)(nb_name + 1));

    if (names == NULL)
        return (NULL);
    while (i < nb_name) {
        names[i] = sfText_create();
        if (names[i] == NULL)
            return (NULL);
        sfText_setString(names[i], (const char *)name[i]);
        sfText_setPosition(names[i], (sfVector2f) { 100, 800 });
        sfText_setCharacterSize(names[i], 25);
        sfText_setColor(names[i], sfRed);
        sfText_setFont(names[i],
                       sfFont_createFromFile("./assets/font/gameplay.ttf"));
        ++i;
    }
    names[i] = NULL;
    return (names);
}

static int *get_caracter_for_dialog(char **dialog)
{
    int i = 0;
    int nb_dialog = my_arraylen(dialog);
    int *caracter = malloc(sizeof(int) * nb_dialog);

    if (caracter == NULL)
        return (NULL);
    while (i < nb_dialog) {
        caracter[i] = my_getnbr(dialog[i]);
        ++i;
    }
    return (caracter);
}

static int fill_dialog(int nb_char, char *dialog, sfText **text)
{
    int i = 0;
    sfVector2f pos = { 100, 850 };
    char *str = NULL;

    while (i < nb_char - 2) {
        if ((text[i] = sfText_create()) == NULL)
            return (-1);
        str = char_to_str(dialog[i + 2]);
        sfText_setString(text[i], str);
        sfText_setPosition(text[i], pos);
        sfText_setCharacterSize(text[i], 20);
        sfText_setColor(text[i], sfRed);
        sfText_setFont(text[i],
                       sfFont_createFromFile("./assets/font/gameplay.ttf"));
        pos.x += is_char_i_or_m(dialog[i + 2]);
        ++i;
        free(str);
    }
    text[i] = NULL;
    return (0);
}

static int create_dialog_text(char **dialog_list, dialog_t *dialog)
{
    int i = 0;

    while (i < dialog->nb_dialog) {
        dialog->dialog_text[i] = malloc(sizeof(sfText *) * (size_t)
                                        (my_strlen(dialog_list[i]) - 1));
        if (dialog->dialog_text[i] == NULL)
            return (-1);
        if (fill_dialog(my_strlen(dialog_list[i]), dialog_list[i],
                        dialog->dialog_text[i]) == -1)
            return (-1);
        ++i;
    }
    dialog->dialog_text[i] = NULL;
    return (0);
}

dialog_t *create_dialog(char **name, char **dialog_list)
{
    dialog_t *dialog = malloc(sizeof(dialog_t) * 1);

    if (dialog == NULL)
        return (NULL);
    dialog->nb_dialog = my_arraylen(dialog_list);
    dialog->caracter_dialog = get_caracter_for_dialog(dialog_list);
    dialog->names = create_text_name(name);
    dialog->nb_char_to_display = 1;
    dialog->displayed_dialog = 0;
    dialog->dialog_text = malloc(sizeof(sfText **) * (size_t)
                                 (dialog->nb_dialog + 1));
    if (dialog->caracter_dialog == NULL)
        return (NULL);
    if (dialog->names == NULL)
        return (NULL);
    if (dialog->dialog_text == NULL)
        return (NULL);
    if (create_dialog_text(dialog_list, dialog) == -1)
        return (NULL);
    return (dialog);
}
