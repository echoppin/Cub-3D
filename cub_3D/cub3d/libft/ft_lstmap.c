/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:54:02 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 18:31:58 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*n_elem;

	n_lst = NULL;
	while (lst && f)
	{
		n_elem = ft_lstnew(f(lst->content));
		if (!(n_elem))
		{
			ft_lstclear(&n_lst, del);
			break ;
		}
		ft_lstadd_back(&n_lst, n_elem);
		lst = lst->next;
	}
	return (n_lst);
}
