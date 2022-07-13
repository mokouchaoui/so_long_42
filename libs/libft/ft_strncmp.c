/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:29:02 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:29 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char			*str1;
	char			*str2;
	size_t			i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (n == 0)
		return (0);
	while ((str1[i] == str2[i]) && (str1[i] || str2[i]) && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
