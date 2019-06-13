/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:54:28 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/13 23:43:11 by mciupek          ###   ########.fr       */
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

char	*ft_strstr(char *str, char *to_find, int k)
{
	int	i;
	int j;

	i = k + 1;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j])
			{
				if (to_find[++j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (NULL);
}

int		ft_check_base(char *base)
{
	char *pet;
	int i;

	i = 0;
	pet = "+-\t\n\r\v\f ";
	if (ft_strlen(base) < 2)
		return (0);
	while (ft_strstr(base, &base[i], i) != NULL && i <= ft_strlen(base))
	{
		i++;
		return (0);
	}
	i = 0;
	while (ft_strstr(base, &pet[i], i) != NULL && i <= ft_strlen(pet))
	{
		i++;
		return (0);
	}
	return (1);
}

void	ft_write_putnbr_base(int nbr, char *base, int b)
{
	int r;
	
	r = base[nbr % b];
	if (nbr / b > 0)
		ft_write_putnbr_base(nbr / b, base, b);
	write(1, &r, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int b;

	b = ft_strlen(base);
	if (ft_check_base(base) == 1)
		ft_write_putnbr_base(nbr, base, b);
}

int		main(void)
{
	ft_putnbr_base(1286305, "poneyvif");
}
