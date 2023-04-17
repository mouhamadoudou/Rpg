/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function that assemble 3 string
*/
#include <stdlib.h>
#include "my.h"

char *assemble_str(char *str1, char *str2, char *str3)
{
    int len = my_strlen(str1) + my_strlen(str2) + my_strlen(str3);
    char *composed_str = malloc(sizeof(char) * (size_t)(len + 1));

    if (composed_str == NULL)
        return (NULL);
    composed_str[0] = '\0';
    my_strcat(composed_str, str1);
    my_strcat(composed_str, str2);
    my_strcat(composed_str, str3);
    return (composed_str);
}

char *char_to_str(char c)
{
    char *str = malloc(sizeof(char) * 2);

    if (str == NULL)
        return (NULL);
    str[0] = c;
    str[1] = '\0';
    return (str);
}
