/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 10:09:49 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/21 01:08:28 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strstr(char *str, char to_find, int k)
{
	int		i;

	i = k + 1;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_base(char *base)
{
	char	*pet;
	int		i;
	int		len_base;

	len_base = 0;
	i = 0;
	pet = "+-\t\n\r\v\f ";
	while (base[len_base] != '\0')
		len_base++;
	while (i <= len_base)
	{
		if (ft_strstr(base, base[i], i) != -1)
			return (0);
		i++;
	}
	i = 0;
	while (i <= 8)
	{
		if (ft_strstr(base, pet[i], -1) != -1)
			return (0);
		i++;
	}
	return (len_base);
}

int		ft_spaces(char *str, char *base)
{
	int		i;

	i = 0;
	while ((ft_strstr(base, str[i], -1) == -1) &&
			str[i] != '-' && str[i] != '+')
	{
		if (str[i] != '\t' && str[i] != '\n' && str[i] != '\v' &&
				str[i] != '\f' && str[i] != '\r' && str[i] != ' ')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_convert(char *str, char *base, int i, int b)
{
	int		len_nb;
	int		b_pow;
	int		nb;

	len_nb = 0;
	b_pow = 1;
	nb = 0;
	while (ft_strstr(base, str[i + len_nb], -1) != -1)
		len_nb++;
	while (--len_nb + 1 > 0)
	{
		nb = nb + ft_strstr(base, str[i + len_nb], -1) * b_pow;
		b_pow = b_pow * b;
	}
	return (nb);
}

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		signe;
	int		b;
	int		nb;

	nb = 0;
	i = ft_spaces(str, base);
	signe = 1;
	b = ft_check_base(base);
	if (b < 2 || i == -1)
		return (0);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = signe * -1;
		i++;
	}
	nb = signe * ft_convert(str, base, i, b);
	return (nb);
}
