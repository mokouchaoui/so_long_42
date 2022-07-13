/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:27:11 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:49 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*sp;
	size_t		i;

	i = 0;
	sp = (const char *)s;
	while (i < n)
	{
		if (sp[i] == (char)c)
			return ((void *) s + i);
		i++;
	}
	return ((void *)0);
}
