#include "../includes/wolf3d.h"

void	key_move(int k, t_env *e)
{
	printf("%d\n", k);
	if (k == KEY_UP)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_DOWN)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_LEFT)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_RIGHT)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_JUMP && e->player.move_jump == 0)
		e->player.move_jump = 1;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx_init, e->mlx.window);
		exit(0);
	}
}

int		key_press(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}

int		key_hook(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}
