/*
** EPITECH PROJECT, 2021
** macro.h
** File description:
** macro
*/

#pragma once

#define ABS(value) (((value) < (0)) ? (-value) : (value))
#define WINDOW_L tab_obj[i][j].pos.x >= -128
#define WINDOW_R tab_obj[i][j].pos.x <= 1928
#define WINDOW_D tab_obj[i][j].pos.y <= 1328
#define WINDOW_T tab_obj[i][j].pos.y >= -128
#define UP sfKeyboard_isKeyPressed(sfKeyUp)
#define RIGHT sfKeyboard_isKeyPressed(sfKeyRight)
#define LEFT sfKeyboard_isKeyPressed(sfKeyLeft)
#define DOWN sfKeyboard_isKeyPressed(sfKeyDown)
#define LOW_ATCK sfKeyboard_isKeyPressed(sfKeyNum1)
#define BIG_ATCK sfKeyboard_isKeyPressed(sfKeyNum2)
#define ESC sfKeyboard_isKeyPressed(sfKeyEscape)
#define ENTER sfKeyboard_isKeyPressed(sfKeyEnter)
#define ERROR (-1)
#define NB_MOB_ON_MAP (1)
