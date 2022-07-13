/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:06:23 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:06:27 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isspace(char *str)
{
	int	i;

	i = 0;
	if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *src)
{
	int		i;
	int		nb;
	int		sign;
	char	*str;

	str = (char *)src;
	nb = 0;
	sign = 1;
	i = 0;
	while (isspace(&str[i]) != 0)
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
