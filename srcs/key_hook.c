#include "../includes/wolf3d.h"

int	key_hook(int keycode, t_env *env)
{
	printf("%d\n", keycode);
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
	if (keycode == SWITCH_MUSIC)
	{
		system("killall mpg123");
		play_music();
	}
	if (keycode == MUTE)
		system("killall mpg123");
	if (keycode == SWITCH_TEXTURES)
	{
		env->switch_textures = !env->switch_textures;
		// mlx_destroy_image(env->mlx.mlx_init, env->mlx.image);
		// env->mlx.image = mlx_new_image(env->mlx.mlx_init, WIDTH, HEIGHT);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx.mlx_init, env->mlx.window);
		exit(0);
	}
	return (0);
}