/*
** EPITECH PROJECT, 2021
** my_compute_power_rec.c
** File description:
** recursive fonction returns first arg raised to power p, p second arg
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    }
    if (nb == 0 || p < 0) {
        return (0);
    }
    while (p != 1) {
        return (nb * my_compute_power_rec(nb, p - 1));
    }
}
