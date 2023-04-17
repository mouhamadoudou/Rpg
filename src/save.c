/*
** EPITECH PROJECT, 2022
** save.c
** File description:
** save
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "my_rpg.h"
#include "my.h"

char *my_strcpy_index(char *dest, char *src, int j)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    return dest;
}

char *concat_nb_n_path(char *path_1, int nb, char *path_2)
{
    int len = my_strlen(path_1) + my_strlen(path_2) + nb_dig_int(nb);
    char *final_str = malloc(sizeof(char) * (len + 1));

    my_strcpy_index(final_str, path_1, 0);
    my_strcpy_index(final_str, int_to_str(nb), my_strlen(path_1));
    my_strcpy_index(final_str, path_2, len - my_strlen(path_2));

    final_str[len] = '\0';
    return final_str + 1;
}


int get_nb_file(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *dp;
    int file_count = 0;

    if (dir == NULL)
        return 0;
    dp = readdir(dir);
    while (dp != NULL) {
        if (dp->d_type == DT_REG)
            file_count++;
        dp = readdir(dir);
    }
    closedir(dir);
    return file_count;
}

void save_game(program_elem_t *all_elem)
{
    int nb_file = get_nb_file("./save");
    char *filepath = concat_nb_n_path("../save/game", nb_file + 1, ".legend");
    int fd = open(filepath, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    int init_pos_x = all_elem->elem_win->map[0]->pos.x;
    int init_pos_y = all_elem->elem_win->map[0]->pos.y;

    write(fd, int_to_str(all_elem->elem_game->player->skin), nb_dig_int(all_elem->elem_game->player->skin));
    write(fd, "\n", 1);
    write(fd, int_to_str(init_pos_x), nb_dig_int(init_pos_x));
    write(fd, "\n", 1);
    write(fd, int_to_str(init_pos_y), nb_dig_int(init_pos_y));
    close(fd);
    return;
}