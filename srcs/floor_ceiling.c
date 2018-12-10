#include "../includes/wolf3d.h"

void	floor_ceiling(t_env *env, int x)
{
	int y;

	y = env->ray->end + 1;
	env->ray->dist_player = 0.0;
	env->ray->dist_wall = env->ray->perp_wall_d;
	while (y++ < SCREEN_HEIGHT)
	{
		env->ray->curr_dist = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
		env->ray->weight = (env->ray->curr_dist - env->ray->dist_player) /
									(env->ray->dist_wall - env->ray->dist_player);
		env->ray->curr_fl_x = env->ray->weight * env->ray->fl_wall_x +
									(1.0 - env->ray->weight) * env->ray->pos_x;
		env->ray->curr_fl_y = env->ray->weight * env->ray->fl_wall_y +
									(1.0 - env->ray->weight) * env->ray->pos_y;
		env->ray->fl_tex_x = (int)(env->ray->curr_fl_x * TEXTURE_WIDTH) % TEXTURE_WIDTH;
		env->ray->fl_tex_y = (int)(env->ray->curr_fl_y * TEXTURE_HEIGHT) % TEXTURE_HEIGHT;
		// choice_fc(env, x, y);
	}
}