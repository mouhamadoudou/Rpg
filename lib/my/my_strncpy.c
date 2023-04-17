/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (n > i) {
        dest[i] = '\0';
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
