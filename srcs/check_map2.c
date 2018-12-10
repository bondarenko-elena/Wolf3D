/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:49 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:33:10 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		check_map2(int length, char **str_splitted, char *str)
{
	int i;

	i = 0;
	while (i < length)
	{
		if (check_line(str_splitted[i]) != 1)
		{
			free_tab_char(str_splitted);
			free(str);
			return (0);
		}
		i++;
	}
	free(str);
	free_tab_char(str_splitted);
	return (1);
}
