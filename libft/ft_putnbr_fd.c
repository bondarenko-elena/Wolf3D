/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:09:21 by olbondar          #+#    #+#             */
/*   Updated: 2017/12/02 16:29:25 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
if (n < 0)
{
ft_putchar_fd('-', fd);
if (n <= -10)
ft_putnbr_fd(n / -10, fd);
ft_putchar_fd(-(n % 10) + '0', fd);
}
else if (n >= 10)
{
ft_putnbr_fd(n / 10, fd);
ft_putchar_fd((n % 10) + '0', fd);
}
else
ft_putchar_fd(n + '0', fd);
}
