/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** reproduce the behavior of the strcmp function
*/

int my_strlen(char const *str);

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (i < my_strlen(s1)) {
        if (s1[i] != s2[i])
            return (1);
        ++i;
    }
    return (0);
}
