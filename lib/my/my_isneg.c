/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** display N if parameter is negative and P if positive
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar(78);
    } else if (n >= 0) {
        my_putchar(80);
    }
    my_putchar('\n');
}
