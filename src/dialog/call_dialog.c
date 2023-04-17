/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function to call the correct dialog
*/
#include "dialog.h"

static bool is_not_speakable(int i, npc_t *npc)
{
    if (my_strcmp(npc[i].name, "old_man") != 0 &&
        my_strcmp(npc[i].name, "villager_4") != 0) {
        return (true);
    }
    return (false);
}

dialog_t *call_dialog(npc_t *npc, sfVector2f *player_pos)
{
    int i = 0;
    char **name = NULL;
    char **dialog_list = NULL;
    dialog_t *dialog_elem = NULL;

    while (i < NB_NPC) {
        if (npc[i].texture->cord.x + 100 >= player_pos->x
            && npc[i].texture->cord.x - 100 <= player_pos->x &&
            npc[i].texture->cord.y + 100 >= player_pos->y &&
            npc[i].texture->cord.y - 100 <= player_pos->y)
            break;
        ++i;
    }
    if (i == NB_NPC || is_not_speakable(i, npc) == true)
        return (NULL);
    if ((dialog_list = get_npc_dialog(&name, &npc[i])) == NULL)
        return (NULL);
    dialog_elem = create_dialog(name, dialog_list);
    if (dialog_elem == NULL)
        return (NULL);
    dialog_elem->npc_nb = i;
    free_array(name);
    free_array(dialog_list);
    return (dialog_elem);
}
