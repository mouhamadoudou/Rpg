/*
** EPITECH PROJECT, 2022
** player_attack.c
** File description:
** player_attack
*/

#include "my_rpg.h"

static bool check_around_mob(player_t *player, bot_t *bot)
{
    if (bot->texture->cord.x >= 700 && bot->texture->cord.x <= 1000)
        if (bot->texture->cord.y >= 350 && bot->texture->cord.y <= 650)
            return true;
    return false;
}

void player_attack(player_t *player, program_elem_t *all_elem)
{
    for (int i = 0; i < NB_MOB_ON_MAP; i++) {
        printf("%i\n", i);
        if (check_around_mob(player, all_elem->elem_game->list_mob[i]) &&
            player->anim.atck_1)
            all_elem->elem_game->list_mob[i]->current_life -= 10;
        else if (check_around_mob(player, all_elem->elem_game->list_mob[i]) &&
                player->anim.atck_2)
            all_elem->elem_game->list_mob[i]->current_life -= 20;
    }
    return;
}

int get_player_dead(player_t *player)
{
    if (player->current_life <= 0)
        return 1;
    return 0;
}