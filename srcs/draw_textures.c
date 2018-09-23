#include "../includes/wolf3d.h"

void draw_textures(t_env *env, int x)

	int		y;
	double	d;
	double	e;
	double	gap;

	d = WIDTH * 0.18;
	e = (WIDTH - 2 * d) / 2;
	y = (int)d;
	while (--y > 0)
	{
		x = (int)(d * 2);
		while (--x > 0)
		{
			gap = (d - x) * (d - x) + (d - y) * (d - y);
			if (gap < d * d * 0.5 && gap > d * d * 0.4)
				mlx_pixel_put(env->mlx.mlx_init, WIN, (int)(x + e), (int)(100 + y), 0x001111FF);
			else if (gap < d * d * 0.6 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), 0x00BBFFBB);
			else if (gap < d * d * 0.7 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), 0x00FFBC00);
			else if (gap < d * d * 0.8 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), 0x00FF0000);
		}
	}