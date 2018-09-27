#include "../includes/wolf3d.h"

int	key_hook(int keycode, t_env *env)
{
	printf("%d\n", keycode);
	if (keycode == KEY_UP || keycode == ARROW_UP || keycode == KEY_DOWN || keycode == ARROW_DOWN ||
		keycode == KEY_LEFT || keycode == ARROW_LEFT || keycode == KEY_RIGHT || keycode == ARROW_RIGHT ||
		keycode == KEY_JUMP)
		switch_moves(keycode, env);
	if (keycode == SWITCH_MUSIC || keycode == MUTE)
		switch_music(keycode);

	if (keycode == SWITCH_TEXTURES || keycode == ONE || keycode == ONE_NUMPAD || keycode == TWO || keycode == TWO_NUMPAD
		|| keycode == THREE || keycode == THREE_NUMPAD || keycode == FOUR || keycode == THREE_NUMPAD
		|| keycode == FOUR || keycode == FOUR_NUMPAD || keycode == FIVE || keycode == FIVE_NUMPAD
		|| keycode == SIX || keycode == SIX_NUMPAD || keycode == RESET_TEXTURES)
		env->switch_textures = switch_textures(keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx.mlx_init, env->mlx.window);
		exit(0);
	}
	return (0);
}