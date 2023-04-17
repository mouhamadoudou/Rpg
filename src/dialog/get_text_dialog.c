/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to get the text of the dialog in the dialog file
*/
#include <stdlib.h>
#include <stdio.h>
#include "dialog.h"

static char **open_dialog_file(void)
{
    int i = 0;
    int nb_line = get_nb_line(".dialogs/npc.txt");
    FILE *stream = fopen(".dialogs/npc.txt", "r");
    char **file_content = malloc(sizeof(char *) * (nb_line + 1));
    char *line = NULL;
    size_t len = 0;
    __ssize_t to_malloc = 0;

    if (file_content == NULL || stream == NULL || nb_line == -1)
        return (NULL);
    while ((to_malloc = getline(&line, &len, stream)) != -1) {
        if ((file_content[i] = malloc(sizeof(char) * (to_malloc))) == NULL)
            return (NULL);
        my_strncpy(file_content[i], line, to_malloc - 1);
        ++i;
    }
    free(line);
    fclose(stream);
    file_content[nb_line] = NULL;
    return (file_content);
}

static sfVector2i *get_line_dialog(int active_dialog, char *name_npc,
                                   char **file_content)
{
    char active[] = "a";
    active[0] = active_dialog + '0';
    char *name_in_file = assemble_str("###", name_npc, "###");
    char *line = assemble_str("###", active, "###");
    sfVector2i *lines = malloc(sizeof(sfVector2i) * 1);

    if (lines == NULL)
        return (NULL);
    lines->x = 0;
    while (my_strcmp(file_content[lines->x], name_in_file) != 0)
        ++lines->x;
    while (my_strcmp(file_content[lines->x], line) != 0)
        ++lines->x;
    lines->y = ++lines->x;
    while (my_strcmp(file_content[lines->y], line) != 0)
        ++lines->y;
    free(line);
    free(name_in_file);
    return (lines);
}

static char **get_name_dialog(int *start_line, char **filecontent)
{
    int i = 0;
    int j = 0;
    char **list_name = NULL;

    ++(*start_line);
    while (my_strcmp(filecontent[*start_line + i], "##") != 0)
        ++i;
    list_name = malloc(sizeof(char *) * (size_t)(i + 1));
    if (list_name == NULL)
        return (NULL);
    while (j < i) {
        list_name[j] = my_strdup(filecontent[*start_line + j]);
        ++j;
    }
    *start_line += ++i;
    list_name[j] = NULL;
    return (list_name);
}

static int assigne_value(npc_t *npc, char **file_content, char ***name,
                         sfVector2i **lines)
{
    *lines = get_line_dialog(npc->active_dialog, npc->name, file_content);
    if (*lines == NULL)
        return (-1);
    *name = get_name_dialog(&(*lines)->x, file_content);
    if (name == NULL)
        return (-1);
    return (0);
}

char **get_npc_dialog(char ***name, npc_t *npc)
{
    int i = 0;
    char **file_content = open_dialog_file();
    char **dialog = NULL;
    sfVector2i *lines = NULL;

    if (file_content == NULL)
        return (NULL);
    if (assigne_value(npc, file_content, name, &lines) == -1)
        return (NULL);
    dialog = malloc(sizeof(char *) * (size_t)(lines->y - lines->x + 1));
    if (dialog == NULL)
        return (NULL);
    while (i < lines->y - lines->x) {
        dialog[i] = my_strdup(file_content[lines->x + i]);
        if (dialog[i] == NULL)
            return (NULL);
        ++i;
    }
    dialog[i] = NULL;
    return (dialog);
}
