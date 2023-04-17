/*
** EPITECH PROJECT, 2022
** music.c
** File description:
** music
*/

#include "my_rpg.h"

sfSound *set_music(sfSoundBuffer *buffer, float volume)
{
    sfSound *music = sfSound_create();

    sfSound_setBuffer(music, buffer);
    sfSound_setVolume(music, volume);

    return music;
}

sfSound *set_my_sound(sfSoundBuffer **buffer)
{
    sfSound *music;

    buffer[0] = sfSoundBuffer_createFromFile("./assets/saving.ogg");
    music = set_music(buffer[0], 50);

    return music;
}

void music_destroy(sfSound *music, sfSoundBuffer **buffer)
{
    sfSound_destroy(music);
    sfSoundBuffer_destroy(buffer[0]);

    return;
}

sfMusic *set_music_back(char *filepath)
{
    sfMusic *music = sfMusic_createFromFile(filepath);
    sfMusic_setVolume(music, 50);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);

    return music;
}
