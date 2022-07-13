/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:28:03 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:41 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char const c, char sp)
{
	if (c == sp)
		return (1);
	return (0);
}

static char	**free_all(char **s_splited)
{
	int	i;

	i = 0;
	while (s_splited[i] == NULL)
	{
		free(s_splited[i]);
		i++;
	}
	free(s_splited);
	return (NULL);
}

static int	size_or_cntwrd(char const *s, char sp, size_t start, int b)
{
	if (b == 1)
	{
		b = 0;
		start = 0;
		while (*s)
		{
			if (*s != sp && start == 0)
			{
				start = 1;
				b++;
			}
			else if (*s == sp)
				start = 0;
			s++;
		}
		return (b);
	}
	b = 0;
	while (is_sep(s[start], sp) == 0 && s[start] != '\0')
	{
		start++;
		b++;
	}
	return (b);
}

static char	**make_line(char const *s, char c, char **tab_split, size_t nword)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i] && n < nword)
	{
		while (s[i] == c)
			i++;
		if (n < nword)
		tab_split[n] = ft_substr(s, i, size_or_cntwrd(s, c, i, 0));
		if (!tab_split[n])
			return (free_all(tab_split));
		while (s[i] && s[i] != c)
			i++;
		n++;
	}
	tab_split[n] = 0;
	return (tab_split);
}

char	**ft_split(char const *s, char c)
{
	size_t	nword;
	char	**tab_split;

	if (!s)
		return (NULL);
	nword = (size_or_cntwrd(s, c, 0, 1));
	tab_split = (char **)malloc(sizeof(char *) * (nword + 1));
	if (!tab_split)
		return (NULL);
	tab_split = make_line(s, c, tab_split, nword);
	return (tab_split);
}
