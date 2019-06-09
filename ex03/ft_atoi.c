/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:38:35 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/09 13:13:15 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_spaces(char *str)
{
	int i;

	i = 0;
	while ((str[i] < '0' || str [i] > '9') && str[i] != '-' && str[i] != '+')
	{
		if (str[i] != '\t' || str[i] != '\n' || str[i] != '\v' || 
			str[i] != '\f' || str[i] != '\r' || str[i] != ' ')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int i;
	int signe;
	int nb;

	if (ft_spaces(str) == -1)
		return (0);
	else
		i = ft_spaces(str);
	signe = 1;
	nb = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (nb >= -2147483648 && nb <= 2147483647)
		return (signe * nb);
	else
		return (0);
}

int 	main(int nb_arg, char **str)
{
	int nb;
	
	if (nb_arg == 0)
		return (0);

	nb = ft_atoi(str[1]);
	printf("%d", nb);
}
