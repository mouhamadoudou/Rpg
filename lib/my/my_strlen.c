/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** counts and returns number caracter string passed as parameter
*/

int my_strlen(char const *str)
{
    int i = 0;

    while ('\0' != str[i]) {
        i += 1;
    }
    return (i);
}
