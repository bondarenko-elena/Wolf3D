/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:49 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_walls_exist(t_ray *ray)
{
	int i;

	i = 0;
	while (i < ray->map_width)
	{
		if (ray->map[0][i] == 0 || ray->map[ray->map_height - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < ray->map_height)
	{
		if (ray->map[i][0] == 0 || ray->map[i][ray->map_width - 1] == 0)
			return (0);
		i++;
	}
	return (1);
}
