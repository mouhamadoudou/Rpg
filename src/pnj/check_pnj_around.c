/*
** EPITECH PROJECT, 2022
** check_pnj_around.c
** File description:
** check_pnj_around
*/

#include "my_rpg.h"
#include "my.h"

static bool check_up_down(npc_t *all_pnj, int dir, int i)
{
    if ((dir == 0 || dir == 1) && all_pnj[i].texture->cord.x <= 920 &&
        all_pnj[i].texture->cord.x >= 780) {
        if (dir == 0 && all_pnj[i].texture->cord.y + 90 >= 500 &&
            all_pnj[i].texture->cord.y + 90 <= 510)
            return true;
        else if (dir == 1 && all_pnj[i].texture->cord.y - 90 <= 500 &&
                all_pnj[i].texture->cord.y - 90 >= 490)
            return true;
    }
    return false;
}

static bool check_left_right(npc_t *all_pnj, int dir, int i)
{
    if ((dir == 2 || dir == 3) && all_pnj[i].texture->cord.y <= 570 &&
        all_pnj[i].texture->cord.y >= 430) {
        if (dir == 2 && all_pnj[i].texture->cord.x + 45 >= 850 &&
            all_pnj[i].texture->cord.x + 45 <= 860) {
            return true;
        } else if (dir == 3 && all_pnj[i].texture->cord.x - 90 <= 850 &&
                all_pnj[i].texture->cord.x - 90 >= 840)
            return true;
    }
    return false;
}

bool check_pnj_around(npc_t *all_pnj, int dir)
{
    for (int i = 0; all_pnj[i].name != NULL; i++) {
        if (check_up_down(all_pnj, dir, i))
            return true;
        else if (check_left_right(all_pnj, dir, i))
            return true;
        else
            continue;
    }
    return false;
}