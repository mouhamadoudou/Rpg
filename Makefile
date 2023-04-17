##
## EPITECH PROJECT, 2022
## Makefile 
## File description:
## Makefile
##

CC	=	gcc

SRC	=	./src/main.c 									\
		./src/window.c 									\
		./src/help.c 									\
		./src/create_object.c 							\
		./src/handle_map.c 								\
		./src/player/move_player.c 						\
		./src/free/free.c 								\
		./src/all_function_check_free.c 				\
		./src/lib.c 									\
		./src/manage_text.c 							\
		./src/handle_bar.c								\
		./src/dialog/call_dialog.c						\
		./src/dialog/create_composed_str.c				\
		./src/dialog/create_dialog.c					\
		./src/dialog/display_dialog.c					\
		./src/dialog/get_text_dialog.c					\
		./src/dialog/is_char_i.c						\
		./src/dialog/free_dialog_elem.c					\
		./src/player/anim_player.c						\
		./src/player/chose_anim_player.c				\
		./src/player/find_pos_player.c					\
		./src/get_content_file.c						\
		./src/pnj/get_all_pnj.c							\
		./src/my_str_to_word_array.c					\
		./src/pnj/check_pnj_around.c					\
		./src/menu/handle_background.c					\
		./src/menu/main_menu.c							\
		./src/button.c									\
		./src/menu/choice_skin.c						\
		./src/menu/settings.c							\
		./src/menu/cursor.c								\
		./src/spell/create_list_all_spell.c				\
		./src/spell/create_spell.c						\
		./src/item/create_list_all_item.c				\
		./src/item/create_item.c						\
		./src/mob/create_mob.c							\
		./src/mob/create_list_all_mob.c					\
		./src/mob/assign_spell_mob.c					\
		./src/mob/mob_item_drop.c						\
		./src/mob/mob_stat.c							\
		./src/mob/create_in_game_mob.c					\
		./src/mob/display_mob.c							\
		./src/mob/find_mob_pos.c						\
		./src/mob/attack_player.c						\
		./src/open_conf_file_get_info.c					\
		./src/getline_struct_fun.c						\
		./src/menu/pause_menu.c							\
		./src/menu/handle_btn_pause.c					\
		./src/init_all_elem.c							\
		./src/lib2.c									\
		./src/menu/stat_menu.c							\
		./src/event.c									\
		./src/menu/handle_sound.c 						\
		./src/thread_main_func_mob.c					\
		./src/launch_thread_detect.c					\
		./src/path_finding/a_star.c						\
		./src/path_finding/create_coords_for_a_star.c	\
		./src/path_finding/free_a_elem.c				\
		./src/path_finding/launch_thread_move.c			\
		./src/path_finding/move_function_mob.c			\
		./src/path_finding/move_in_diagonal.c			\
		./src/path_finding/move_in_window.c				\
		./src/path_finding/new_pos_in_paths.c			\
		./src/path_finding/remove_append.c				\
		./src/path_finding/score_a_star.c				\
		./src/path_finding/wait_move.c					\
		./src/path_finding/set_value_a_star.c			\
		./src/menu/how_to_play.c 						\
		./src/save.c									\
		./src/menu/save_menu.c							\
		./src/free/free_game_object_t.c					\
		./src/free/free_thread_data.c					\
		./src/free/free_mob_struct.c					\
		./src/menu/free_menu.c \
		./src/player/all_anim_player.c \
		./src/player/move_map.c \
		./src/create_bar.c \
		./src/display_map.c \
		./src/get_all_obj.c \
		./src/music.c \
		./src/particle.c \
		./src/player/player_attack.c \
		./src/game_loop.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CPPFLAGS =	-iquote ./include/

CFLAGS	=	-Wextra -Wall

LDFLAGS	=	-L./lib/

LDLIBS	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm \
			-lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(MAKE) -C ./lib/my/ clean
	$(RM) -f $(OBJ)

fclean: clean
	$(MAKE) -C ./lib/my/ fclean
	$(RM) -f $(NAME)

re:	fclean all

debug:	CFLAGS += -g3

debug:	all

.PHONY: all clean fclean debug re
