/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:55 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:09 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			red_cross(t_env *env)
{
	if (env->ray->music_tumbler == 1)
		system("killall -9 afplay");
	exit(0);
	return (0);
}
