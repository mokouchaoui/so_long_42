/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:29:26 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:25 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) - start) < len)
		len = (ft_strlen(s) - start);
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(*s));
	if (!str)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && j < ft_strlen(s))
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
