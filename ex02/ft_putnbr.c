/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 11:52:41 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/13 12:08:14 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_posneg(int nb)
{
	if (nb < 0)
	{
		write(1, &"-", 1);
		return (-nb);
	}
	else
		return (nb);
}

void	ft_write_nbr(int nb)
{
	int r;

	r = nb % 10;
	if (nb / 10 != 0)
	{
		ft_write_nbr(nb / 10);
	}
	ft_putchar(r + '0');
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, &"-2147483648", 11);
	else
	{
		nb = ft_posneg(nb);
		ft_write_nbr(nb);
	}
}
