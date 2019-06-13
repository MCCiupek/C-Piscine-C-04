/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:49:56 by mciupek           #+#    #+#             */
/*   Updated: 2019/06/13 19:51:10 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	len_s;

	i = 0;
	len = ft_len(dest);
	len_s = ft_len(src);
	if (len > size)
		return (len_s);
	while (i < size - len)
	{
		if (src[i] == '\0')
		{
			dest[len + i] = '\0';
			return (len + i + 1);
		}
		else
		{
			if (i == size - len - 1)
				dest[len + i] = '\0';
			else
				dest[len + i] = src[i];
		}
		i++;
	}
	return (len + len_s);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	unsigned int n = 10;
	char src[4] = "1234";
	char dest[16] = "abc";
	printf("ft_strlcat = %lu, %s\n", strlcat(dest, src, n), dest);
}
