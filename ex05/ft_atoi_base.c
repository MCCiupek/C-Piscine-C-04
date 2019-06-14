/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:09:49 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/14 16:55:28 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strstr(char *str, char c)
{
	int	i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_spaces(char *str)
{
	int i;

	i = 0;
	while ((str[i] < '0' || str [i] > '9') && str[i] != '-' && str[i] != '+')
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != '\v' && 
				str[i] != '\f' && str[i] != '\r' && str[i] != ' ')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int 	i;
	int 	k;
	int 	signe;
	int		b;
	long	nb;
	long	bp;

	i = ft_spaces(str);
	signe = 1;
	nb = 0;
	bp = 1;
	k = 0;
	b = ft_strlen(base);
	if (i == -1)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (ft_strstr(base, &str[i + k]) != -1)
		k++;
	while (--k + 1 >= 0)
	{
		nb = nb + ft_strstr(base, &str[i + k]) * bp;
		bp = bp * b;
	}
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return ((int)signe * nb);
}

int 	main(int argc, char **argv)
{
	int nb;

	if (argc != 3)
		return (0);

	nb = ft_atoi_base(argv[1], argv[2]);
	printf("ft = %d", nb);
}

