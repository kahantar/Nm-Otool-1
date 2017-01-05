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
#include "../../includes/ft_otool.h"
#include <mach-o/loader.h>
#include <stdlib.h>

void		print_addr_32(long unsigned int addr)
{
	int					i;
	long unsigned int	j;

	i = 0;
	j = addr;
	while (j > 0)
	{
		j /= 16;
		i++;
	}
	i = 9 - i;
	while (--i > 0)
		ft_putchar('0');
	ft_putaddr(addr);
	ft_putchar(' ');
}

int			print_section_32(struct section *section, char *ptr)
{
	unsigned int		i;
	char				*str;
	long unsigned int	addr;

	i = 0;
	addr = (long unsigned int)section->addr;
	while (i < section->size)
	{
		if (i == 0 || i % 16 == 0)
		{
			if (i != 0)
				addr += 16;
			print_addr_32(addr);
		}
		str = ft_itoa_base(ptr[i], 16, 2);
		ft_putstr(str);
		ft_putchar(' ');
		free(str);
		if ((i + 1) % 16 == 0 && (i + 1) < section->size)
			ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	return (0);
}

int			add_section_32(void *lc, t_data *data, char *ptr)
{
	int							i;
	int							nsects;
	struct segment_command		*seg;
	struct section				*sec;

	(void)data;
	i = 0;
	seg = lc;
	nsects = seg->nsects;
	sec = (void *)seg + sizeof(*seg);
	while (i < nsects)
	{
		if (!ft_strcmp(sec->segname, "__TEXT")
			&& !ft_strcmp(sec->sectname, "__text"))
		{
			ft_putendl("(__TEXT,__text) section");
			if (print_section_32(sec, ptr + sec->offset) == -1)
				return (-1);
		}
		sec = (void *)sec + sizeof(*sec);
		i++;
	}
	return (0);
}

int			get_sect_32(char *ptr, t_data *data)
{
	int							i;
	int							ncmds;
	struct load_command			*lc;
	struct mach_header			*header;

	i = 0;
	header = (struct mach_header *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			if (add_section_32(lc, data, ptr) == -1)
				return (-1);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
