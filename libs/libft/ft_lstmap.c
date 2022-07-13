/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:26:55 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:30:56 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!lst || !f)
		return (NULL);
	tmp1 = lst;
	tmp2 = ft_lstnew(f(lst->content));
	while (tmp1->next)
	{
		tmp3 = ft_lstnew(f(tmp1->next->content));
		if (!tmp2)
		{
			ft_lstclear(&tmp2, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp2, tmp3);
		tmp1 = tmp1->next;
	}
	return (tmp2);
}
