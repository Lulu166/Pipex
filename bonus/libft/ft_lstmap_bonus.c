/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luhumber <luhumber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:32:56 by luhumber          #+#    #+#             */
/*   Updated: 2022/11/16 15:59:58 by luhumber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_cpy;
	t_list	*lst_temp;

	if (lst && f && del)
	{
		lst_cpy = NULL;
		while (lst)
		{
			lst_temp = ft_lstnew(f(lst->content));
			if (!lst_temp)
			{
				ft_lstclear(&lst_cpy, del);
				return (NULL);
			}
			ft_lstadd_back(&lst_cpy, lst_temp);
			lst = lst->next;
		}
		return (lst_cpy);
	}
	return (NULL);
}
