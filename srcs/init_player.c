#include "../includes/wolf3d.h"

void		init_player(t_env *e)
{
	e->player.position.x = 0;
	e->player.position.y = 0;
	e->player.direction.x = -1;
	e->player.direction.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	e->player.speed_turn = 0.05;
	e->player.speed_move = 0.05;
	e->player.move_up = 0;
	e->player.move_down = 0;
	e->player.move_right = 0;
	e->player.move_left = 0;
	e->player.move_jump = 0;
	e->player.is_jump = 0;
}