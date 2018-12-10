# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olbondar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/18 09:35:49 by olbondar          #+#    #+#              #
#    Updated: 2018/10/18 09:36:01 by olbondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := wolf3d

SRC :=	add_smog.c \
		calculate_distance.c \
		calculate_step_side.c \
		check_file.c \
		check_line.c \
		check_map.c \
		check_map2.c \
		check_walls_exist.c \
		default_wall.c \
		define_color1.c \
		define_color2.c \
		display_text.c \
		do_magic.c \
		draw.c \
		free_struct.c \
		free_tab_char.c \
		free_tab_int.c \
		get_color_tex.c \
		get_data_addr.c \
		init_env.c \
		init_map_size.c \
		init_textures.c \
		init_window.c \
		key_press.c \
		key_press_init.c \
		key_release.c \
		main.c \
		malloc_error.c \
		map_error.c \
		move_down.c \
		move_left.c \
		move_right.c \
		move_up.c \
		moves.c \
		open_file.c \
		play_music.c \
		print_keycode.c \
		ray_casting.c \
		ray_init.c \
		read_error.c \
		read_file.c \
		read_map.c \
		red_cross.c \
		redraw.c \
		rotate_left.c \
		rotate_right.c \
		textured_wall.c \

CC := gcc
SRC := $(addprefix srcs/,$(SRC))
OBJ := $(SRC:.c=.o)
HEADLIB := libft/
HEADMLX := /usr/local/include
CFLAGS := -Wall -Wextra -Werror
LIBMLX := /usr/local/lib
FRAMEWS := -lmlx -framework OpenGL -framework AppKit

all: create_lib $(NAME)

create_lib:
	@make -C libft

$(NAME): $(OBJ)
	@CC -o $(NAME) $(OBJ) libft/libft.a -L $(LIBMLX) $(FRAMEWS)
	@echo "\033[32mWolf3D is ready.\033[0m"

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $< -I $(HEADLIB) -I $(HEADMLX) -I includes

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft

re: @fclean all

.PHONY: create_lib all clean fclean re
