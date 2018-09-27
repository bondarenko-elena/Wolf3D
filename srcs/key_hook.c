#include "../includes/wolf3d.h"

int	key_hook(int keycode, t_env *env)
{
	int	random;

	srand(time(NULL));
	random = rand() % 2 + 1;

	printf("%d\n", keycode);
	if (keycode == KEY_UP || keycode == ARROW_UP || keycode == KEY_DOWN || keycode == ARROW_DOWN ||
		keycode == KEY_LEFT || keycode == ARROW_LEFT || keycode == KEY_RIGHT || keycode == ARROW_RIGHT ||
		keycode == KEY_JUMP)
		switch_moves(keycode, env);
	if (keycode == SWITCH_MUSIC || keycode == MUTE)
		switch_music(keycode);
	if (keycode == SWITCH_TEXTURES)
		env->switch_textures = random;
	if (keycode == RESET_TEXTURES)
		env->switch_textures = 0;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx.mlx_init, env->mlx.window);
		exit(0);
	}
	return (0);
}