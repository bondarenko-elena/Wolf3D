/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 16:05:37 by olbondar          #+#    #+#             */
/*   Updated: 2017/11/25 16:20:25 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	size_t			i;
	int				is_negative;
	long long int	number;
	long long int	tmp;

	i = 0;
	is_negative = 1;
	number = 0;
	tmp = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	(str[i] == 45) ? is_negative = -1 : is_negative;
	(str[i] == 45 || str[i] == 43) ? i++ : i;
	while (str[i] >= 48 && str[i] <= 57)
	{
		tmp = number;
		number = number * 10 + (str[i] - 48);
		if (tmp > number && is_negative == 1)
			return (-1);
		else if (tmp > number && is_negative == -1)
			return (0);
		i++;
	}
	return (number * is_negative);
}
