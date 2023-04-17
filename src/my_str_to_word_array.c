/*
** EPITECH PROJECT, 2022
** str_to_word_array.c
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include <unistd.h>
#include "rpg_struct.h"
#include "my.h"

static int get_nb_delim(char *str, char delim)
{
    int i = 0;
    int nb_delim = 0;

    while (str[i] != '\0') {
        if (str[i] == delim)
            ++nb_delim;
        ++i;
    }
    return (nb_delim);
}

static int malloc_no_data(char **tab, cycle_counter_t *counters)
{
    if (counters->i - counters->j == 0) {
        tab[counters->k] = malloc(sizeof(char) * 4);
        if (tab[counters->k] == NULL) {
            return (-1);
        }
        tab[counters->k][0] = '\0';
        my_strcat(tab[counters->k], "N/A");
        ++counters->k;
        counters->j += 2;
        ++counters->i;
        return (0);
    }
    return (1);
}

static int malloc_tab(char *str, char **tab, char delim,
                    cycle_counter_t *counters)
{
    int r_val = 1;

    if (str[counters->i] == delim || str[counters->i] == '\0') {
        r_val = malloc_no_data(tab, counters);
        if (r_val == -1 || r_val == 0)
            return (r_val);
        tab[counters->k] = malloc(sizeof(char) * (size_t)
                                (counters->i - counters->j + 1));
        if (tab[counters->k] == NULL)
            return (-1);
        tab[counters->k][0] = '\0';
        my_strncat(tab[counters->k], &str[counters->j],
                counters->i - counters->j);
        counters->j = counters->i;
        ++counters->j;
        ++counters->k;
    }
    return (0);
}

char **str_to_word_array(char *str, char delim)
{
    cycle_counter_t counters = { 0, 0, 0 };
    int nb_delim = get_nb_delim(str, delim);
    char **tab = malloc(sizeof(char *) * (size_t)(nb_delim + 2));

    if (tab == NULL)
        return (NULL);
    while (str[counters.i] != '\0') {
        if (malloc_tab(str, tab, delim, &counters) == -1)
            return (NULL);
        ++counters.i;
    }
    if (malloc_tab(str, tab, delim, &counters) == -1)
        return (NULL);
    tab[counters.k] = NULL;
    return (tab);
}
