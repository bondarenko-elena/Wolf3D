#include "../includes/wolf3d.h"

void switch_moves(int keycode, t_env *env)
{
	if (keycode == KEY_UP || keycode == ARROW_UP)
		env->player.move_up = !env->player.move_up;
	if (keycode == KEY_DOWN || keycode == ARROW_DOWN)
		env->player.move_down = !env->player.move_down;
	if (keycode == KEY_LEFT || keycode == ARROW_LEFT)
		env->player.move_left = !env->player.move_left;
	if (keycode == KEY_RIGHT || keycode == ARROW_RIGHT)
		env->player.move_right = !env->player.move_right;
	if (keycode == KEY_JUMP && env->player.move_jump == 0)
	{
		system("mpg123  music/jump.mp3 &");
		env->player.move_jump = 1;
	}
}