#include "../includes/wolf3d.h"

void			put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->mlx.size_line);
	e->mlx.pixel[i] = c;
	e->mlx.pixel[++i] = c >> 8;
	e->mlx.pixel[++i] = c >> 16;
}

unsigned int	get_color(t_env *e)
{
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->color_1);
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
			return (e->color_2);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->color_3);
	return (e->color_4);
}

unsigned int	add_smog(unsigned int c, double d)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = c;
	g = c >> 8;
	b = c >> 16;
	d = 7 / (100 / d);
	if (d > 0.9)
		d = 0.9;
	if (r > 0)
		r = r - (r * d);
	if (g > 0)
		g = g - (g * d);
	if (b > 0)
		b = b - (b * d);
	return ((r << 16) + (g << 8) + b);
}

void			draw_line(t_env *e, int x, int start, int end)
{
	int				i;
	unsigned int	c;

	c = get_color(e);
	c = add_smog(c, e->ray.dist);
	i = -1;
	while (++i < start + e->player.z)
		put_pxl(e, x, i, e->color_sky);
	i--;
	while (++i <= end + e->player.z && i < e->height)
		put_pxl(e, x, i, c);
	i--;
	while (++i < e->height)
		put_pxl(e, x, i, add_smog(e->color_ground, abs(i - e->height) * 0.040));
}
