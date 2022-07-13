/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:26:12 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:31:15 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(long long nb, int i)
{
	long long	res;

	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	res = nb;
	if (res > 9)
	{
		res = nb / 10;
		i = intlen(res, i);
	}
	i++;
	return (i);
}

static char	*putnbr(long long nb, int len, char *str)
{
	int		sign;

	str[intlen(nb, 0)] = '\0';
	sign = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign = -1;
	}
	while (len > 1)
	{
		len--;
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign == -1)
		str[0] = '-';
	if (sign == 0)
		str[0] = nb + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = intlen(n, 0);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = putnbr(n, len, str);
	return (str);
}
