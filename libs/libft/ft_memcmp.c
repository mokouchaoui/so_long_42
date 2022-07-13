/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:27:15 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:47 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*sp1;
	const unsigned char	*sp2;

	sp1 = (const unsigned char *)s1;
	sp2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (sp1[i] != sp2[i])
			return ((int)sp1[i] - (int)sp2[i]);
		i++;
	}
	return (0);
}
