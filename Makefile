# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 14:28:57 by olbondar          #+#    #+#              #
#    Updated: 2017/12/02 16:34:53 by olbondar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Wolf3D
SRC := main.c \
		check_file.c \
		pre_init_env.c \
		post_init_env.c \
		malloc_error.c \
		open_file.c \
		read_file.c \
		event.c \
		key_hook.c \
		expose_hook.c \
		display.c \
		put_pixel.c \
		init_player.c \
		
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
	@gcc -o $(NAME) $(OBJ) libft/libft.a -L $(LIBMLX) $(FRAMEWS)
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
