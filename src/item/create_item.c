/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** create a item from conf file
*/
#include <stdlib.h>
#include "item.h"
#include "my_rpg.h"
#include "my.h"

static int set_csfml_elem_item(char **item_info, item_t *item)
{
    item->name = sfText_create();
    item->description = sfText_create();
    if (item->name == NULL || item->description == NULL)
        return (-1);
    sfText_setString(item->name, (const char *)item_info[ITEM_NAME]);
    sfText_setString(item->description, (const char *)item_info[ITEM_DESC]);
    return (0);
}

static void set_effect_item(char **item_info, item_t *item)
{
    item->effect.regen_hp = my_getnbr(item_info[ITEM_REGEN_HP]);
    item->effect.regen_mp = my_getnbr(item_info[ITEM_REGEN_MP]);
    item->effect.mana = my_getnbr(item_info[ITEM_MANA]);
    item->effect.luck = my_getnbr(item_info[ITEM_LUCK]);
    item->effect.speed = my_getnbr(item_info[ITEM_SPEED]);
    item->effect.hp = my_getnbr(item_info[ITEM_HP]);
    item->effect.resistance = my_getnbr(item_info[ITEM_RESISTANCE]);
    item->effect.attack = my_getnbr(item_info[ITEM_ATTACK]);
}

item_t *create_item(char **item_data)
{
    item_t *item = malloc(sizeof(item_t) * 1);

    if (item == NULL)
        return (NULL);
    item->id = my_strdup(item_data[ITEM_ID]);
    if (set_csfml_elem_item(item_data, item) == -1)
        return (NULL);
    set_effect_item(item_data, item);
    set_effect_item(item_data, item);
    item->value = my_getnbr(item_data[ITEM_VALUE]);
    return (item);
}
