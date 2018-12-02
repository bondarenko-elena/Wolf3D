/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:48 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_line(char *str)
{
	int		i;
	char	**line;

	line = ft_strsplit(str, ' ');
	i = 0;
	while (line[i])
	{
		if (!(ft_atoi(line[i]) >= 0 && ft_atoi(line[i]) <= 9))
		{
			free_tab_char(line);
			map_error();
		}
		i++;
	}
	free_tab_char(line);
	return (1);
}
