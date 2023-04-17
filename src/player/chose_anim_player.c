/*
** EPITECH PROJECT, 2022
** chose_anim_player.c
** File description:
** chose_anim_player
*/

#include "my_rpg.h"
#include "rpg_macro.h"

static void choose_anim(player_t *player)
{
    int passed = 0;

    player->player.rect.height = 47;
    passed = go_atck1(player);
    if (passed == 0)
        passed = go_atck2(player);
    if (passed == 0)
        passed = go_up(player);
    if (passed == 0)
        passed = go_left(player);
    if (passed == 0)
        go_right(player);
    return;
}

static void resize_sprite(player_t *player)
{
    if (player->anim.atck_1 || player->anim.atck_2) {
        player->player.rect.left = 0;
        player->player.rect.top = 0;
        player->player.rect.height = 47;
        sfSprite_setTextureRect(player->player.sprite, player->player.rect);
    }
    return;
}

void get_direction(player_t *player)
{
    if (player->anim.sec_atck < 0.3 && (player->anim.atck_1 ||
        player->anim.atck_2)) {
        player->anim.time_atck = sfClock_getElapsedTime(player->
                                                        anim.clock_atck);
        player->anim.sec_atck = player->anim.time_atck.microseconds / 1000000.0;
        sfSprite_setTextureRect(player->player.sprite, player->player.rect);
        return;
    }
    if (player->anim.sec_atck > 0.3) {
        player->anim.sec_atck = 0;
        sfClock_restart(player->anim.clock_atck);
        resize_sprite(player);
        player->anim.atck_1 = false;
        player->anim.atck_2 = false;
    }
    choose_anim(player);
    return;
}
