/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** copy a string into another
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int len_str = my_strlen(src);

    while (i < len_str + 1) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
