/*
** EPITECH PROJECT, 2022
** anim_player.c
** File description:
** anim_player
*/

#include <stdlib.h>
#include "my_rpg.h"

static void set_anim_player(player_t *player)
{
    player->anim.down = false;
    player->anim.up = false;
    player->anim.right = false;
    player->anim.left = false;
    player->anim.atck_1 = false;
    player->anim.atck_2 = false;
    player->anim.sec = 0.00;
    player->anim.clock = sfClock_create();
    player->anim.sec_atck = 0.00;
    player->anim.clock_atck = sfClock_create();
    return;
}

player_t *load_player(char *filepath)
{
    player_t *player = malloc(sizeof(player_t));

    player->player.rect = (sfIntRect){ .left = 0, .top = 0, .width = 45,
                        .height = 47 };
    player->stat.hp = 100;
    player->current_life = 100;
    player->stat.mana = 100;
    player->stat.resistance = 15;
    player->stat.attack = 40;
    player->current_mana = 100;
    set_anim_player(player);
    player->level = 1;
    player->player.texture = sfTexture_createFromFile(filepath, NULL);
    player->player.sprite = sfSprite_create();
    sfSprite_setPosition(player->player.sprite, (sfVector2f) { 850, 500 });
    player->player.cord = (sfVector2f) { 850, 500 };
    sfSprite_setTexture(player->player.sprite, player->player.texture, sfTrue);
    sfSprite_setTextureRect(player->player.sprite, player->player.rect);
    sfSprite_setScale(player->player.sprite, (sfVector2f) { 2.3, 2.3 });
    return player;
}

bool key_pressed(player_t *player)
{
    if (player->anim.left || player->anim.right)
        return true;
    else if (player->anim.up || player->anim.down)
        return true;
    if (player->anim.atck_1 || player->anim.atck_2)
        return true;
    return false;
}

void get_anim_player(player_t *player)
{
    player->anim.time = sfClock_getElapsedTime(player->anim.clock);
    player->anim.sec = player->anim.time.microseconds / 1000000.0;
    if (key_pressed(player) && player->anim.sec >= 0.1) {
        if (player->player.rect.left <= player->player.rect.width * 4) {
            player->player.rect.left += (player->player.rect.width - 1);
        } else
            player->player.rect.left = 0;
    }
    if (player->anim.sec >= 0.1) {
        player->anim.sec = 0;
        sfClock_restart(player->anim.clock);
    }
    return;
}
