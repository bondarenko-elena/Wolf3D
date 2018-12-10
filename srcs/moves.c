/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		moves(t_env *env)
{
	if (env->up == 1)
		move_up(env);
	if (env->down == 1)
		move_down(env);
	if (env->left == 1)
		move_left(env);
	if (env->right == 1)
		move_right(env);
	if (env->rot_left == 1)
		rotate_left(env);
	if (env->rot_right == 1)
		rotate_right(env);
	redraw(env);
	return (0);
}
