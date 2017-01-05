/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 14:39:26 by nfruneau          #+#    #+#             */
/*   Updated: 2015/01/28 12:50:37 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_otool.h"

void	sort_rev_ascii(t_file **file, t_file *tmp)
{
	t_file	*tmp2;

	tmp2 = *file;
	if (ft_strcmp(tmp->name, tmp2->name) > 0)
	{
		tmp->next = tmp2;
		*file = tmp;
		return ;
	}
	while (tmp2->next)
	{
		if (ft_strcmp(tmp->name, tmp2->next->name) > 0)
		{
			tmp->next = tmp2->next;
			tmp2->next = tmp;
			return ;
		}
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
}

void	sort_ascii(t_file **file, t_file *tmp)
{
	t_file	*tmp2;

	tmp2 = *file;
	if (ft_strcmp(tmp->name, tmp2->name) < 0)
	{
		tmp->next = tmp2;
		*file = tmp;
		return ;
	}
	while (tmp2->next)
	{
		if (ft_strcmp(tmp->name, tmp2->next->name) < 0)
		{
			tmp->next = tmp2->next;
			tmp2->next = tmp;
			return ;
		}
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
}

void	no_sort(t_file **file, t_file *tmp)
{
	t_file	*tmp2;

	tmp2 = *file;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
}

void	sort_list(t_file **file, t_file *tmp, t_flag flag)
{
	if (*file)
	{
		if (flag.r == 1)
			sort_rev_ascii(file, tmp);
		else if (flag.p == 1)
			no_sort(file, tmp);
		else
			sort_ascii(file, tmp);
	}
}
