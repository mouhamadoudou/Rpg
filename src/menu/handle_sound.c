/*
** EPITECH PROJECT, 2022
** handle_sound.c
** File description:
** handle_sound
*/

#include <stdlib.h>
#include "my_rpg.h"

sfSprite **set_sound(void)
{
    sfSprite **sound = malloc(sizeof(sfSprite *) * 2);
    sfTexture *sound_on = sfTexture_createFromFile("assets/sound_on.png", NULL);
    sfTexture *sound_off = sfTexture_createFromFile("assets/sound_off.png",
                                                    NULL);
    sfVector2f pos = { 50, 50 };

    for (int i = 0; i < 2; i++) {
        sound[i] = sfSprite_create();
        sfSprite_setScale(sound[i], (sfVector2f) { 0.19, 0.19 });
        sfSprite_setPosition(sound[i], pos);
    }
    sfSprite_setTexture(sound[0], sound_on, sfTrue);
    sfSprite_setTexture(sound[1], sound_off, sfTrue);
    return sound;
}

void display_sound(sfSprite **sound, window_elem_t elem_win)
{
    if (elem_win.sound_is_on)
        sfRenderWindow_drawSprite(elem_win.window, sound[0], NULL);
    else
        sfRenderWindow_drawSprite(elem_win.window, sound[1], NULL);
    return;
}
