#include "../includes/wolf3d.h"

/*
Now the actual DDA starts. It's a loop that increments the ray with 1 square every time, until a wall is hit. Each time, either it jumps a square in the x-direction (with stepX) or a square in the y-direction (with stepY), it always jumps 1 square at once. If the ray's direction would be the x-direction, the loop will only have to jump a square in the x-direction everytime, because the ray will never change its y-direction. If the ray is a bit sloped to the y-direction, then every so many jumps in the x-direction, the ray will have to jump one square in the y-direction. If the ray is exactly the y-direction, it never has to jump in the x-direction, etc...
sideDistX and sideDistY get incremented with deltaDistX with every jump in their direction, and mapX and mapY get incremented with stepX and stepY respectively.

When the ray has hit a wall, the loop ends, and then we'll know whether an x-side or y-side of a wall was hit in the variable "side", and what wall was hit with mapX and mapY. We won't know exactly where the wall was hit however, but that's not needed in this case because we won't use textured walls for now.
*/

void		ray_calculate_distance(t_env *env)
{
	//perform DDA
	while (env->ray.hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (env->ray.side.x < env->ray.side.y)
		{
			env->ray.side.x += env->ray.delta.x;
			env->ray.map.x += env->ray.step.x;
			env->ray.hit_side = 0;
		}
		else
		{
			env->ray.side.y += env->ray.delta.y;
			env->ray.map.y += env->ray.step.y;
			env->ray.hit_side = 1;
		}
		//Check if ray has hit a wall
		if (env->map[env->ray.map.x][env->ray.map.y] > 0)
		{
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			env->ray.hit = 1;
			if (env->ray.hit_side == 0)
				env->ray.distance = (env->ray.map.x - env->ray.position.x + (1 - env->ray.step.x) / 2) / env->ray.direction.x;
			else
				env->ray.distance = (env->ray.map.y - env->ray.position.y + (1 - env->ray.step.y) / 2) / env->ray.direction.y;
		}
	}
}