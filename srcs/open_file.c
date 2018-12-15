/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:46:16 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	open_file(t_env *env, char *filename)
{
	if ((env->fd = open(filename, O_DIRECTORY)) >= 0)
		map_error();
	if ((env->fd = open(filename, O_RDONLY)) < 0)
		map_error();
	return (1);
}
