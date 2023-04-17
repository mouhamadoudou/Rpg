/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** swaps the content of two integers, adresse given as parameter
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
