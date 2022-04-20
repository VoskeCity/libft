/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:06:32 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/20 15:36:49 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newel;
	
	if (!(newel = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	newlst = newel;
	lst = lst->next;
	while (lst)
	{
		if (!(newel = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&newel, del);
			return (0);
		}
		lst = lst->next;
	}
	return (newlst);
}
