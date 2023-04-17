/*
** EPITECH PROJECT, 2022
** file get free function and check
** File description:
** file get free function and check
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "my.h"

int check_direction(sfVector2f A, sfVector2f B)
{
    int a = A.x + A.y;
    int b = B.x + B.y;

    if (a > b)
        return -1;
    if (b > a)
        return 1;
    return 1;
}

void function_free(char **tab)
{
    for (int a = 0; tab[a] != NULL; a++)
        free(tab[a]);
    free(tab);
}

void function_free_int(int **tab)
{
    for (int a = 0; tab[a] != NULL; a++)
        free(tab[a]);
    free(tab);
}

int check_nb_air(char *scrypte)
{
    int result = 0;
    int len = my_strlen(scrypte);

    for (int i = 0; i < len; i++) {
        if (scrypte[i] == 'P')
            result++;
    }
    return result;
}

sfRenderWindow *gestion_window(void)
{
    sfVideoMode mode = { 1000, 800, 32 };
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "My_rpg", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return window;
}
