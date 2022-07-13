/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:25:34 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:31:32 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long long nb)
{
	long long	i;
	long long	res;
	int			sign;

	sign = 0;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		sign++;
	}
	res = nb;
	if (res > 9)
	{
		res = nb / 10;
		i = ft_intlen(res);
	}
	i += 1 + sign;
	return (i);
}
