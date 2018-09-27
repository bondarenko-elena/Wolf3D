NAME := Wolf3D

SRC := add_smog.c \
		check_file.c \
		draw_line.c \
		display_text.c \
		event.c \
		get_position.c \
		get_color.c \
		init_env.c \
		init_player.c \
		key_hook.c \
		loop_hook.c \
		main.c \
		map_error.c \
		malloc_error.c \
		move_left.c \
		move_right.c \
		move_up.c \
		move_down.c \
		move_jump.c \
		open_file.c \
		put_pixel.c \
		play_music.c \
		read_file.c \
		read_line.c \
		ray_casting.c \
		ray_draw.c \
		ray_calculate_distance.c \
		ray_calculate_step_side.c \
		ray_init.c \
		switch_moves.c \
		switch_music.c \
		switch_textures.c \ 

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
