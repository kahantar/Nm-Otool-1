/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:12:03 by nfruneau          #+#    #+#             */
/*   Updated: 2015/01/26 18:12:05 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst->next == NULL)
	{
		lst = f(lst);
		tmp = ft_lstnew(lst->content, lst->content_size);
		if (tmp == NULL)
			return (NULL);
	}
	else
	{
		tmp2 = f(lst);
		tmp = ft_lstnew(tmp2->content, tmp2->content_size);
		if (tmp == NULL)
			return (NULL);
		tmp->next = ft_lstmap(lst->next, f);
	}
	return (tmp);
}
