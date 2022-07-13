/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:26:39 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:31:09 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst1;

	if (!lst || !f)
		return ;
	lst1 = lst;
	while (lst1)
	{
		f(lst1->content);
		lst1 = lst1->next;
	}
}
