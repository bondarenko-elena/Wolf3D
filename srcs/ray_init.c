#include "../includes/wolf3d.h"

void ray_init(t_env *env, int x)
{
	// mapX and mapY represent the current square of the map the ray is in, which box of the map we're in
	env->ray.map.x = (int)env->ray.position.x;
	env->ray.map.y = (int)env->ray.position.y;
	//	x-coordinate in camera space
	/*
	cameraX is the x-coordinate on the camera plane that the current x-coordinate of the screen represents, done this way so that the right side of the screen will get coordinate 1, the center of the screen gets coordinate 0, and the left side of the screen gets coordinate -1. Out of this, the direction of the ray can be calculated as was explained earlier: as the sum of the direction vector, and a part of the plane vector. This has to be done both for the x and y coordinate of the vector (since adding two vectors is adding their x-coordinates, and adding their y-coordinates)
	*/
	env->ray.camera = 2 * x / (double)env->width - 1;
	//  the direction of the ray can be calculated as the sum of the direction vector, and a part of the plane vector
	env->ray.direction.x = env->player.direction.x + env->player.plane.x * env->ray.camera;
	env->ray.direction.y = env->player.direction.y + env->player.plane.y * env->ray.camera;
	// env->ray.delta.x and env->ray.delta.y are the distance the ray has to travel to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
	// length of ray from one x or y-side to next x or y-side
	env->ray.delta.x = sqrt(1 + (env->ray.direction.y * env->ray.direction.y) /
			(env->ray.direction.x * env->ray.direction.x));
	env->ray.delta.y = sqrt(1 + (env->ray.direction.x * env->ray.direction.x) /
			(env->ray.direction.y * env->ray.direction.y));
	env->ray.hit = 0;  //was there a wall hit?
	env->ray.distance = -1;
	//was a NS or a EW wall hit?
	env->ray.hit_side = -1;
}