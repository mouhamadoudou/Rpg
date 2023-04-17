/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** function to create mob for mob list
*/
#include <stdlib.h>
#include "mob.h"
#include "my_rpg.h"
#include "my.h"

static int set_mob_spell(char **mob_info, bot_t *mob, spell_t **list_spell)
{
    int nb_spell = 0;

    while (nb_spell < 5 && my_strcmp(mob_info[MOB_SPELL + nb_spell], "NA")
        != 0) {
        mob->spell[nb_spell] = find_mob_spell(mob_info[MOB_SPELL + nb_spell],
                                            list_spell);
        ++nb_spell;
    }
    if (nb_spell != 5)
        mob->spell[nb_spell] = NULL;
    return (0);
}

static int set_mob_stat(char **mob_info, bot_t *mob)
{
    mob->stat.regen_hp = my_getnbr(mob_info[MOB_REGEN_HP]);
    mob->stat.regen_mp = my_getnbr(mob_info[MOB_REGEN_MP]);
    mob->stat.heal = my_getnbr(mob_info[MOB_HEAL]);
    mob->stat.mana = my_getnbr(mob_info[MOB_MANA]);
    mob->stat.luck = my_getnbr(mob_info[MOB_LUCK]);
    mob->stat.speed = my_getnbr(mob_info[MOB_SPEED]);
    mob->stat.hp = my_getnbr(mob_info[MOB_HP]);
    mob->stat.resistance = my_getnbr(mob_info[MOB_RES]);
    mob->stat.attack = my_getnbr(mob_info[MOB_ATTACK]);
    mob->stat.heal_mana = my_getnbr(mob_info[MOB_HEAL_MANA]);
    return (0);
}

bot_t *create_mob(char **mob_data, game_elem_t *game_elem)
{
    bot_t *mob = malloc(sizeof(bot_t) * 1);

    if (mob == NULL)
        return (NULL);
    mob->name = my_strdup(mob_data[0]);
    set_mob_spell(mob_data, mob, game_elem->list_spell);
    set_mob_stat(mob_data, mob);
    mob->exp_given = my_getnbr(mob_data[MOB_EXP]);
    call_function_item_mob(mob_data, mob, game_elem->list_item);
    return (mob);
}
