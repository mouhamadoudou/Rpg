/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** returns number, sent to the fonction as string
*/

int convert_to_int(char const *str, int count_symbole, int nbr,
                int count_minus)
{
    int i = 0;
    int len_to_nbr = nbr;
    int value = 0;
    int digit = 0;

    while (i < len_to_nbr) {
        digit = str[count_symbole] - '0';
        value = value * 10 + digit;
        i++;
        count_symbole++;
    }
    if (count_minus % 2 != 0) {
        value *= -1;
    }
    return (value);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int count_minus = 0;
    int count_symbole = 0;
    int nbr = 0;

    while (('0' <= str[i] && str[i] <= '9') || str[i] == '+' ||
            str[i] == '-') {
        if (str[i] == '-') {
            count_minus++;
        } else if (str[i] == '+') {
            count_symbole++;
        } else {
            nbr++;
        }
        i++;
    }
    count_symbole += count_minus;
    return (convert_to_int(str, count_symbole, nbr, count_minus));
}
