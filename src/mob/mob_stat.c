/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set the stat of a mob
*/
#include "mob.h"

static const fun_set_stat_t TAB[] = {
    { 5, &set_speed },
    { 6, &set_hp },
    { 7, &set_resistance },
    { 8, &set_attack },
};

void set_speed(bot_t *mob)
{
    mob->stat.speed += mob->level - 1;
}

void set_hp(bot_t *mob)
{
    mob->stat.hp += mob->level - 1;
}

void set_resistance(bot_t *mob)
{
    mob->stat.resistance += mob->level - 1;
}

void set_attack(bot_t *mob)
{
    mob->stat.attack += mob->level - 1;
}

int get_stat_to_set(int i, bot_t *mob)
{
    for (int x = 0; x < 4; ++x) {
        if (TAB[x].stat == i) {
            TAB[x].fun_ptr(mob);
            return (0);
        }
    }
    return (0);
}
