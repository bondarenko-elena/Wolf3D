#include "../includes/wolf3d.h"

void	def_floor_ceiling(t_env *env)
{
	if (env->ray->wall == 0 && env->ray->ray_dir_x > 0)
	{
		env->ray->fl_wall_x = env->ray->map_x;
		env->ray->fl_wall_y = env->ray->map_y + env->ray->wall;
	}
	else if (env->ray->wall == 0 && env->ray->ray_dir_x < 0)
	{
		env->ray->fl_wall_x = env->ray->map_x + 1.0;
		env->ray->fl_wall_y = env->ray->map_y + env->ray->wall;
	}
	else if (env->ray->wall == 1 && env->ray->ray_dir_y > 0)
	{
		env->ray->fl_wall_x = env->ray->map_x + env->ray->wall;
		env->ray->fl_wall_y = env->ray->map_y;
	}
	else
	{
		env->ray->fl_wall_x = env->ray->map_x + env->ray->wall;
		env->ray->fl_wall_y = env->ray->map_y + 1.0;
	}
	if (env->ray->end < 0)
		env->ray->end = SCREEN_HEIGHT;
}