/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create a spell from conf file
*/
#include <stdlib.h>
#include "spell.h"
#include "my_rpg.h"
#include "my.h"

static int set_csfml_elem_spell(char **spell_info, spell_t *spell)
{
    spell->clock = sfClock_create();
    if (spell->clock == NULL)
        return (-1);
    spell->name = sfText_create();
    spell->description = sfText_create();
    if (spell->name == NULL || spell->description == NULL)
        return (-1);
    sfText_setString(spell->name, (const char *)spell_info[NAME]);
    sfText_setString(spell->description, (const char *)spell_info[DESC]);
    return (0);
}

static void set_stat_spell(char **spell_info, spell_t *spell)
{
    spell->stat.regen_hp = my_getnbr(spell_info[REGEN_HP]);
    spell->stat.regen_mp = my_getnbr(spell_info[REGEN_MP]);
    spell->stat.heal = my_getnbr(spell_info[HEAL]);
    spell->stat.luck = my_getnbr(spell_info[LUCK]);
    spell->stat.speed = my_getnbr(spell_info[SPEED]);
    spell->stat.resistance = my_getnbr(spell_info[RESISTANCE]);
    spell->stat.attack = my_getnbr(spell_info[ATTACK]);
    spell->stat.heal_mana = my_getnbr(spell_info[HEAL_MANA]);
}

static void set_value_spell(char **spell_info, spell_t *spell)
{
    spell->pourcent_attack = my_getnbr(spell_info[POURCENT_ATTACK]);
    spell->mana = my_getnbr(spell_info[MANA_COST]);
    spell->cd = my_getnbr(spell_info[CD]);
}

spell_t *create_spell(char **spell_data)
{
    spell_t *spell = malloc(sizeof(spell_t) * 1);

    if (spell == NULL)
        return (NULL);
    spell->id = my_strdup(spell_data[ID]);
    if (set_csfml_elem_spell(spell_data, spell) == -1)
        return (NULL);
    set_stat_spell(spell_data, spell);
    set_value_spell(spell_data, spell);
    return (spell);
}
