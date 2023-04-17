/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create the list of all the spells
*/
#include <stdlib.h>
#include "game_element.h"
#include "conf_file.h"
#include "spell.h"
#include "my.h"

spell_t **create_list_spell(void)
{
    int i = 0;
    char ***info_all_spell = create_info("conf/spell.conf");
    spell_t **list_spell = NULL;

    if (info_all_spell == NULL)
        return (NULL);
    list_spell = malloc(sizeof(spell_t *) * (size_t)
                        ((big_array_len(info_all_spell)) + 1));
    if (list_spell == NULL)
        return (NULL);
    while (i < (int)big_array_len(info_all_spell)) {
        list_spell[i] = create_spell(info_all_spell[i]);
        if (list_spell[i] == NULL)
            return (NULL);
        ++i;
    }
    list_spell[i] = NULL;
    free_3_array(info_all_spell);
    free(info_all_spell);
    return (list_spell);
}
