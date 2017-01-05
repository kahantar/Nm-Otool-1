/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_list_32.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:27:44 by nfruneau          #+#    #+#             */
/*   Updated: 2016/02/22 22:27:46 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_nm.h"
#include <mach-o/loader.h>
#include <stdlib.h>

int		add_section2_32(void *ptr, t_data *data)
{
	t_sect				*sec;
	t_sect				*sec2;
	struct section		*section;

	sec2 = data->sect;
	section = (struct section *)ptr;
	if ((sec = (t_sect *)malloc(sizeof(t_sect))) == NULL)
		return (ft_error("malloc error", NULL));
	sec->name = ft_strdup(section->sectname);
	sec->next = NULL;
	if (data->sect)
	{
		while (sec2->next)
			sec2 = sec2->next;
		sec->sect_nbr = sec2->sect_nbr + 1;
		sec2->next = sec;
	}
	else
	{
		sec->sect_nbr = 1;
		data->sect = sec;
	}
	return (0);
}

int		add_section_32(void *lc, t_data *data)
{
	int							i;
	int							nsects;
	struct segment_command		*seg;
	struct section				*sec;

	i = 0;
	seg = lc;
	nsects = seg->nsects;
	sec = (void *)seg + sizeof(*seg);
	while (i < nsects)
	{
		if (add_section2_32(sec, data) == -1)
			return (-1);
		sec = (void *)sec + sizeof(*sec);
		i++;
	}
	return (0);
}

int		get_sect_32(char *ptr, t_data *data)
{
	int						i;
	int						ncmds;
	struct load_command		*lc;
	struct mach_header		*header;

	i = 0;
	header = (struct mach_header *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			if (add_section_32(lc, data) == -1)
				return (-1);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
