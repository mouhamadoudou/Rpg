/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** displays the number given as parameter.
*/

void my_putchar(char c);

int print_the_nbr(int number)
{
    if (number != 0) {
        my_putchar('0' + number);
    } else {
        my_putchar('0');
    }
    return (0);
}

int my_put_nbr(int nb)
{
    int nbr = nb;
    int i = 1;
    int to_print = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        nbr *= -1;
    }
    while (nbr >= 10) {
        i *= 10;
        nbr /= 10;
    }
    while (i >= 1) {
        to_print = (nb / i) % 10;
        i /= 10;
        print_the_nbr(to_print);
    }
    return (0);
}
