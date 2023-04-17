/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** includer
*/

#pragma once

    #include "rpg_struct.h"
    #include "game_element.h"

int get_player_dead(player_t *player);
void player_attack(player_t *player, program_elem_t *all_elem);
void snow(int test, sfCircleShape *circle, sfVector2f position,
        window_elem_t *elem_win);

sfMusic *set_music_back(char *filepath);

void free_settings(sfSprite *opacity, sfSprite *cursor, sfSprite **sound,
                sfText **text);
void free_text_tuto(bool active_menu, sfText **content, int nb_text);
int create_texture(int id, sfVector2f *pos, sfIntRect *rect, map_t *object);
void free_main_menu(char **map, button_t *all_btn, sfSprite *opa, sfText *logo);
int go_up(player_t *player);
int go_left(player_t *player);
void go_right(player_t *player);
int go_atck1(player_t *player);
int go_atck2(player_t *player);
void move_pos_map_y(map_t **all_texture, bot_t **mob_in_map, npc_t *all_pnj,
                    int increment);
void move_pos_map_x(map_t **all_texture, bot_t **mob_in_map, npc_t *all_pnj,
                    int increment);
void manage_event_dialog(sfEvent *event, program_elem_t *all_elem);

void loop_cursor(int *can_move_cursor, int *choice_skin, sfSprite *cursor, 
            program_elem_t *all_elem);
char *concat_nb_n_path(char *path_1, int nb, char *path_2);
int get_nb_file(char *filepath);
char *my_strcpy_index(char *dest, char *src, int j);
int saved_game(map_t **bg, sfText *logo_game, program_elem_t *all_elem);
int nb_dig_int(int nb);
void save_game(program_elem_t *all_elem);
void display_all_text(sfText **txt, int nb_txt, sfRenderWindow *window);
void get_how_to_play(program_elem_t *all_elem);

sfSprite **set_sound(void);
void display_sound(sfSprite **sound, window_elem_t elem_win);

char *int_to_str(int nb);
void get_stat_loop(program_elem_t *all_elem);
void display_background_pause(program_elem_t *all_elem, sfSprite *opacity);
void detect_end_pause(int *pressed, window_elem_t *elem_win, bool *active_menu, int num_key);
button_t *set_btn_pause(void);
bool click_btn_pause(button_t *btn, bool *go_to_menu, program_elem_t *all_elem);
void free_pause_menu(sfSprite *opacity, sfText *pause_txt, button_t *btn);
button_t fill_button(int (*pt_fct)(map_t **bg, sfText *logo_game, program_elem_t *all_elem), sfVector2f pos, char *content_text);
int pause_menu(program_elem_t *all_elem);

sfSprite *set_opacity(void);
void destroy_all(sfText **text, player_t **skin, sfSprite *opa, sfSprite *cur);
sfSprite *set_cursor(void);
void handle_move_cursor(int *can_move_cursor, int *choice_skin, sfSprite *cursor);
void move_cursor(int *skin, sfSprite *cursor, int *can_move_cursor);
int settings_loop(map_t **bg, sfText *logo_game, program_elem_t *all_elem);
int choice_skin_loop(map_t **bg, sfText *logo_game, program_elem_t *all_elem);
int click_btn(button_t *btn, program_elem_t *all_elem, map_t **bg, sfText *logo_game);
void hover_btn(button_t *btn, window_elem_t elem_win, int nb, int width);
void display_btn(button_t *btn, int nb, sfRenderWindow *window);
button_t *set_all_btn(void);
void get_main_menu(program_elem_t *all_elem, sfText *logo_game, int *skin);
void move_background(map_t **background);

void display_pnj(npc_t *all_pnj, sfRenderWindow *window);
int create_pnj(int id, sfVector2f *pos, sfIntRect *rect, npc_t *object);
npc_t *get_all_pnj(void);
char *get_content_file(char *filepath);
bool check_pnj_around(npc_t *all_pnj, int dir);

int *find_current_tile(map_t **all_texture);
bool check_around(map_t **all_texture, int dir, int *index, npc_t *all_pnj);
void get_direction(player_t *player);
player_t *load_player(char *filepath);
void get_direction(player_t *player);
void get_anim_player(player_t *player);

void free_pnj(npc_t *pnj);
void free_map(map_t **map);
void free_bar(sfSprite **mana_bar, sfSprite **life_bar);
sfSprite **create_bar(int chose, char *filepath);
void display_bar(sfSprite **mana_bar, sfSprite **life_bar, sfRenderWindow *window);
player_t creat_objet(void);
player_t reserved();
void  display_player(sfRenderWindow *window, player_t *player);
void set_sf(player_t *tab);

sfText *create_text(char *str, sfColor *color, int scale, sfVector2f *pos);
int my_strlen_w_coma(char *str);
void display_text(sfRenderWindow *window, sfText **all_text, int nb);
int m_getnbr(char *line, int j);
program_elem_t *set_all_elem(void);
map_t **get_all_obj(char **map, int x, int y);
int get_nb_line(char *filepath);
void move_player(map_t **all_texture, bot_t **mob_in_map, npc_t *all_pnj);
void close_window(sfRenderWindow *window, sfEvent event);
void m_strcpy(char *dest, char *src);
void display_texture(map_t **tab_obj, sfRenderWindow *window);
sfRenderWindow *handle_window(void);
void help(void);
char **str_to_word_array(char *str, char separator);
char **get_map(char *filepath);
void display_error(char *str);
int get_col_map(map_t *map);
void handle_event(program_elem_t *all_elem);
int my_getnbr(char const *str);
void free_array(void *array);
void compute_bar(player_t *player, sfSprite **bar, int chose);
