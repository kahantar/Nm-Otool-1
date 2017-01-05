/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arch_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:27:44 by nfruneau          #+#    #+#             */
/*   Updated: 2016/02/22 22:27:46 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_nm.h"
#include <stdlib.h>
#include <ar.h>

int		get_size(char *name)
{
	int		x;
	char	*word;

	word = ft_strchr(name, '/') + 1;
	x = ft_atoi(word);
	return (x);
}

char	*get_ar_name(char *name)
{
	int		len;

	len = ft_strlen(ARFMAG);
	return (ft_strstr(name, ARFMAG) + len);
}

void	sort_ar(t_arch *arch, t_arch *tmp)
{
	t_arch	*tmp2;

	tmp2 = arch;
	if (tmp->off < tmp2->off)
	{
		tmp->next = tmp2;
		arch = tmp;
		return ;
	}
	while (tmp2->next)
	{
		if (tmp->off < tmp2->next->off)
		{
			tmp->next = tmp2->next;
			tmp2->next = tmp;
			return ;
		}
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
}

int		handle_ar(char *ptr, t_data *data, uint32_t r_strx, uint32_t r_off)
{
	t_arch			*ar;
	struct ar_hdr	*arch;

	arch = (void *)ptr + r_off;
	if ((ar = (t_arch *)malloc(sizeof(t_arch))) == NULL)
		return (ft_error("malloc error", NULL));
	ar->name = ft_strdup(get_ar_name(arch->ar_name));
	ar->strx = r_strx;
	ar->off = r_off;
	ar->next = NULL;
	if (!data->arch)
		data->arch = ar;
	else
		sort_ar(data->arch, ar);
	return (0);
}

void	print_ar(char *argv, char *ptr, t_data data)
{
	t_arch			*ar;
	struct ar_hdr	*arch;

	ar = data.arch;
	ft_putendl("");
	while (ar)
	{
		arch = (void *)ptr + ar->off;
		ft_putstr(argv);
		ft_putstr("(");
		ft_putstr(ar->name);
		ft_putstr("):\n");
		load_arch(argv, (void *)arch + sizeof(*arch) + get_size(arch->ar_name)
				, data, 0);
		if (ar->next)
			ft_putendl("");
		ar = ar->next;
	}
}
