/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:17:11 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:17:16 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * 
 * @param n 
 * @return intlen
 */
int	ft_putunnbr(unsigned int n)
{
	char	c;
	int		intlen;

	intlen = ft_intlen((long long)n);
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		ft_putunnbr((n / 10));
		ft_putunnbr((n % 10));
	}
	return (intlen);
}
