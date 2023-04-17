/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create the list of all the items
*/
#include <stdlib.h>
#include "game_element.h"
#include "item.h"
#include "conf_file.h"
#include "my.h"

item_t **create_list_item(void)
{
    int i = 0;
    char ***info_all_item = create_info("conf/item.conf");
    item_t **list_item = NULL;

    if (info_all_item == NULL)
        return (NULL);
    list_item = malloc(sizeof(item_t *) * (size_t)
                    ((big_array_len(info_all_item)) + 1));
    if (list_item == NULL)
        return (NULL);
    while (i < (int)big_array_len(info_all_item)) {
        list_item[i] = create_item(info_all_item[i]);
        if (list_item[i] == NULL)
            return (NULL);
        ++i;
    }
    list_item[i] = NULL;
    free_3_array(info_all_item);
    free(info_all_item);
    return (list_item);
}
