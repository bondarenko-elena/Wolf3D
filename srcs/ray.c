#include "../includes/wolf3d.h"

static void		ray_draw(t_env *e, int x)
{
	int		height;
	int		start;
	int		end;

	height = (int)(e->height / e->ray.dist);
	start = -height / 2 + e->height / 2;
	if (start < 0)
		start = 0;
	end = height / 2 + e->height / 2;
	if (end >= e->height)
		end = e->height - 1;
	draw_line(e, x, start, end);
}

static void		ray_cal_dist(t_env *e)
{
	while (e->ray.hit == 0)
	{
		if (e->ray.side.x < e->ray.side.y)
		{
			e->ray.side.x += e->ray.delta.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.hit_side = 0;
		}
		else
		{
			e->ray.side.y += e->ray.delta.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.hit_side = 1;
		}
		if (e->map[e->ray.map.x][e->ray.map.y] > 0)
		{
			e->ray.hit = 1;
			if (e->ray.hit_side == 0)
				e->ray.dist = (e->ray.map.x - e->ray.pos.x + (1 - e->ray.step.x)
						/ 2) / e->ray.dir.x;
			else
				e->ray.dist = (e->ray.map.y - e->ray.pos.y + (1 - e->ray.step.y)
						/ 2) / e->ray.dir.y;
		}
	}
}

static void		ray_cal_step_side(t_env *e)
{
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.side.x = (e->ray.pos.x - (int)e->ray.pos.x) * e->ray.delta.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.side.x = ((int)e->ray.pos.x + 1 - e->ray.pos.x) * e->ray.delta.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.side.y = (e->ray.pos.y - (int)e->ray.pos.y) * e->ray.delta.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.side.y = ((int)e->ray.pos.y + 1 - e->ray.pos.y) * e->ray.delta.y;
	}
}

static void		ray_init(t_env *e, int x)
{
	e->ray.map.x = (int)e->ray.pos.x;
	e->ray.map.y = (int)e->ray.pos.y;
	e->ray.cam = 2 * x / (double)e->width - 1;
	e->ray.dir.x = e->player.dir.x + e->player.plane.x * e->ray.cam;
	e->ray.dir.y = e->player.dir.y + e->player.plane.y * e->ray.cam;
	e->ray.delta.x = sqrt(1 + (e->ray.dir.y * e->ray.dir.y) /
			(e->ray.dir.x * e->ray.dir.x));
	e->ray.delta.y = sqrt(1 + (e->ray.dir.x * e->ray.dir.x) /
			(e->ray.dir.y * e->ray.dir.y));
	e->ray.hit = 0;
	e->ray.dist = -1;
	e->ray.hit_side = -1;
}

void			ray_casting(t_env *e)
{
	int		x;

	x = -1;
	e->ray.pos.x = e->player.pos.x;
	e->ray.pos.y = e->player.pos.y;
	while (++x < e->width)
	{
		ray_init(e, x);
		ray_cal_step_side(e);
		ray_cal_dist(e);
		ray_draw(e, x);
	}
}
