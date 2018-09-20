#include "../includes/wolf3d.h"

void	move_up(t_env *e)
{
	if (e->map[(int)(e->player.pos.x + e->player.dir.x * e->player.speed_move)]
			[(int)e->player.pos.y] == 0)
		e->player.pos.x += e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y + e->player.dir.y *
				e->player.speed_move)] == 0)
		e->player.pos.y += e->player.dir.y * e->player.speed_move;
}

void	move_down(t_env *e)
{
	if (e->map[(int)(e->player.pos.x - e->player.dir.x * e->player.speed_move)]
			[(int)e->player.pos.y] == 0)
		e->player.pos.x -= e->player.dir.x * e->player.speed_move;
	if (e->map[(int)e->player.pos.x][(int)(e->player.pos.y - e->player.dir.y *
				e->player.speed_move)] == 0)
		e->player.pos.y -= e->player.dir.y * e->player.speed_move;
}

void	move_right(t_env *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(-e->player.speed_turn) -
		e->player.dir.y * sin(-e->player.speed_turn);
	e->player.dir.y = old.x * sin(-e->player.speed_turn) + e->player.dir.y *
		cos(-e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(-e->player.speed_turn) -
		e->player.plane.y * sin(-e->player.speed_turn);
	e->player.plane.y = old.x * sin(-e->player.speed_turn) + e->player.plane.y *
		cos(-e->player.speed_turn);
}

void	move_left(t_env *e)
{
	t_dxy	old;

	old.x = e->player.dir.x;
	e->player.dir.x = e->player.dir.x * cos(e->player.speed_turn) -
		e->player.dir.y * sin(e->player.speed_turn);
	e->player.dir.y = old.x * sin(e->player.speed_turn) + e->player.dir.y *
		cos(e->player.speed_turn);
	old.x = e->player.plane.x;
	e->player.plane.x = e->player.plane.x * cos(e->player.speed_turn) -
		e->player.plane.y * sin(e->player.speed_turn);
	e->player.plane.y = old.x * sin(e->player.speed_turn) + e->player.plane.y *
		cos(e->player.speed_turn);
}

void	move_jump(t_env *e)
{
	if (e->player.z >= 100)
		e->player.is_jump = 1;
	if (e->player.is_jump == 1)
		e->player.z -= 10;
	if (e->player.is_jump == 0)
		e->player.z += 10;
	if (e->player.is_jump == 1 && e->player.z == 0)
	{
		e->player.is_jump = 0;
		e->player.move_jump = 0;
	}
}
