/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int len_str = my_strlen(str);
    char j[1];

    while (i < len_str / 2) {
        j[0] = str[len_str - i - 1];
        str[len_str - 1 - i] = str[i];
        str[i] = j[0];
        i++;
    }
    return (str);
}
