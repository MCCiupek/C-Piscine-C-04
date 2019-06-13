/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:38:35 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/13 21:53:19 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int		ft_atoi(char *str)
{
	int 	i;
	int 	signe;
	long	nb;

	i = ft_spaces(str);
	if (i == -1)
		return (0);
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
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return ((int)signe * nb);
}

int 	main(int argc, char **argv)
{
	int nb;
	int nb1;
	
	if (argc != 2)
		return (0);

	nb = ft_atoi(argv[1]);
	nb1 = atoi(argv[1]);
	printf("%c\n", argv[1][0]); 
	printf("ft = %d\natoi = %d", nb, nb1);
}
