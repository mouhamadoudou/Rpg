/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** open conf file and get info
*/
#include <stdlib.h>
#include "rpg_macro.h"
#include "conf_file.h"
#include "my.h"

static int get_nb_line(const char *filename)
{
    int nb_line = 0;
    getline_elem_t *elem = create_getline_struct(filename);

    if (elem == NULL)
        return (ERROR);
    while (getline(&elem->lineptr, &elem->n, elem->stream) != -1)
        ++nb_line;
    free_getline_elem(elem);
    return (nb_line);
}

static int read_file_content(int i, char **file_content, getline_elem_t *elem)
{
    elem->to_malloc = getline(&elem->lineptr, &elem->n, elem->stream);
    if (elem->to_malloc == ERROR)
        return (ERROR);
    if (elem->lineptr[elem->to_malloc - 1] != '\n')
        ++elem->to_malloc;
    file_content[i] = malloc(sizeof(char) * elem->to_malloc);
    if (file_content[i] == NULL)
        return (ERROR);
    file_content[i][0] = '\0';
    my_strncat(file_content[i], elem->lineptr, elem->to_malloc - 1);
    return (0);
}

char **get_file_content(const char *filename)
{
    int i = 0;
    int nb_line_file = get_nb_line(filename);
    char **file_content = NULL;
    getline_elem_t *elem = create_getline_struct(filename);

    if (nb_line_file < 1 || elem == NULL)
        return (NULL);
    file_content = malloc(sizeof(char *) * (size_t)(nb_line_file + 1));
    if (file_content == NULL)
        return (NULL);
    while (i < nb_line_file) {
        if (read_file_content(i, file_content, elem) == -1)
            return (NULL);
        ++i;
    }
    free_getline_elem(elem);
    file_content[i] = NULL;
    return (file_content);
}

char ***create_info(char *filepath)
{
    int i = 0;
    char **file_content = get_file_content(filepath);
    char ***info = NULL;

    if (file_content == NULL)
        return (NULL);
    info = malloc(sizeof(char **) * (size_t)(my_arraylen(file_content) + 1));
    if (info == NULL)
        return (NULL);
    while (i < my_arraylen(file_content)) {
        info[i] = str_to_word_array(file_content[i], ':');
        if (info[i] == NULL)
            return (NULL);
        ++i;
    }
    info[i] = NULL;
    return (info);
}
