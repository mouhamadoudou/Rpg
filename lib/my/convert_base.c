/*
** EPITECH PROJECT, 2021
** convert_base.c
** File description:
** convert a number in base 10 to any base
*/

int my_revnbr(int nbr, int is_zero_to_add_base_2)
{
    int mod = 0;
    int res = 0;

    while (nbr >= 10) {
        mod = nbr % 10;
        res = res * 10 + mod;
        nbr /= 10;
    }
    mod = nbr % 10;
    res = res * 10 + mod;
    if (is_zero_to_add_base_2 == 1)
        res *= 10;
    return (res);
}

int convert_base(int number, int base)
{
    int i = 0;
    int first_zero_base_2 = 0;
    int q = number;
    int m = 0;
    int res = 0;

    while (q / base != 0) {
        m = q % base;
        q = q / base;
        res = res * 10 + m;
    }
    if (q / base == 0) {
        m = q % base;
        res = res * 10 + m;
    }
    return (my_revnbr(res, first_zero_base_2));
}
