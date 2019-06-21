/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:54:28 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/21 00:14:15 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char to_find, int k)
{
	int	i;

	i = k + 1;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int		ft_check_base(char *base, int b)
{
	char	*pet;
	int		i;

	i = 0;
	pet = "+-";
	if (ft_strlen(base) < 2)
		return (0);
	while (i < b)
	{
		if (ft_strstr(base, base[i], i) != NULL)
			return (0);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (ft_strstr(base, pet[i], -1) != NULL)
			return (0);
		i++;
	}
	return (1);
}

void	ft_write_putnbr_base(long nbr, char *base, int b)
{
	int r;

	r = base[nbr % b];
	if (nbr / b > 0)
		ft_write_putnbr_base(nbr / b, base, b);
	write(1, &r, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	long	nb;

	nb = (long)nbr;
	b = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, &"-", 1);
		nb = -nb;
	}
	if (ft_check_base(base, b) == 1)
		ft_write_putnbr_base(nb, base, b);
}
