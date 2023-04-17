/*
** EPITECH PROJECT, 2022
** all_anim_player.c
** File description:
** all_anim_player
*/

#include "my_rpg.h"
#include "rpg_macro.h"

int go_up(player_t *player)
{
    if (UP || ((UP && (RIGHT || LEFT)))) {
        if (player->anim.up == false)
            player->player.rect.left = 0;
        player->anim.up = true;
        if (RIGHT)
            player->player.rect.top = 141;
        else
            player->player.rect.top = 94;
        sfSprite_setTextureRect(player->player.sprite, player->player.rect);
        return 1;
    } else {
        if (player->anim.up)
            player->player.rect.left = 0;
        player->anim.up = false;
        player->player.rect.width = 45;
    }
    return 0;
}

int go_left(player_t *player)
{
    if (LEFT || (LEFT && DOWN)) {
        player->anim.left = true;
        player->player.rect.top = 47;
        sfSprite_setTextureRect(player->player.sprite, player->player.rect);
        return 1;
    } else
        player->anim.left = false;
    return 0;
}

void go_right(player_t *player)
{
    if (RIGHT || DOWN) {
        player->anim.right = true;
        player->player.rect.top = 0;
        sfSprite_setTextureRect(player->player.sprite, player->player.rect);
    } else
        player->anim.right = false;
    return;
}

int go_atck1(player_t *player)
{
    if ((LOW_ATCK && LEFT)) {
            player->anim.atck_1 = true;
            player->player.rect.top = 239;
            player->player.rect.height = 51;
            player->player.rect.left = 0;
            sfSprite_setTextureRect(player->player.sprite, player->player.rect);
            return 1;
    } else if ((LOW_ATCK && RIGHT) || LOW_ATCK) {
            player->anim.atck_1 = true;
            player->player.rect.top = 188;
            player->player.rect.height = 51;
            player->player.rect.left = 0;
            sfSprite_setTextureRect(player->player.sprite, player->player.rect);
            return 1;
    }
    return 0;
}

int go_atck2(player_t *player)
{
    if ((BIG_ATCK && LEFT)) {
            player->anim.atck_2 = true;
            player->player.rect.top = 341;
            player->player.rect.height = 51;
            player->player.rect.left = 0;
            sfSprite_setTextureRect(player->player.sprite, player->player.rect);
            return 1;
    } else if ((BIG_ATCK && RIGHT) || BIG_ATCK) {
            player->anim.atck_2 = true;
            player->player.rect.top = 290;
            player->player.rect.height = 51;
            player->player.rect.left = 0;
            sfSprite_setTextureRect(player->player.sprite, player->player.rect);
            return 1;
    }
    return 0;
}
