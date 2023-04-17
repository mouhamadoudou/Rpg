/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** find the spell to assign it to mob
*/
#include <stdlib.h>
#include "my_rpg.h"
#include "mob.h"
#include "my.h"

spell_t *find_mob_spell(char *spell_id, spell_t **spell_list)
{
    int i = 0;

    while (my_strcmp(spell_id, spell_list[i]->id) != 0) {
        ++i;
    }
    return (spell_list[i]);
}
