/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:09:49 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/15 02:16:34 by mciupek          ###   ########.fr       */
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

int		ft_strstr(char *str, char c, int k)
{
	int	i;

	i = k;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_base(char *base)
{
	char	*pet;
	int		i;

	i = 0;
	pet = "+-\t\n\r\v\f ";
	if (ft_strlen(base) < 2)
		return (0);
	while (ft_strstr(base, base[i], i + 1) != -1 && i <= ft_strlen(base))
	{
		i++;
		return (0);
	}
	i = 0;
	while (ft_strstr(base, pet[i], i + 1) != -1 && i <= ft_strlen(pet))
	{
		i++;
		return (0);
	}
	return (1);
}

int		ft_spaces(char *str)
{
	int i;

	i = 0;
	while ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
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
	int		i;
	int 	k;
	int 	signe;
	long	nb;
	long	bp;

	i = ft_spaces(str);
	signe = 1;
	nb = 0;
	bp = 1;
	k = 0;
	if (ft_check_base(base) != 1 || i == -1)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (ft_strstr(base, str[i + k], 0) != -1)
		k++;
	while (--k >= 0)
	{
		nb = nb + ft_strstr(base, str[i + k], 0) * bp;
		bp = bp * ft_strlen(base);
	}
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return ((int)signe * nb);
}

int		main(int argc, char **argv)
{
	int nb;

	if (argc != 3)
		return (0);
	nb = ft_atoi_base(argv[1], argv[2]);
	printf("ft = %d", nb);
}
