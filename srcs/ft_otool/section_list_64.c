/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section_list_64.c                                  :+:      :+:    :+:   */
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

char	read_tab(int i)
{
	char	*tab;

	tab = "0123456789abcdefghijklmnopqrstuvwxyz";
	return (tab[i]);
}

char	*ft_itoa_base(int val, int base, int output_size)
{
	char			buffer[output_size + 1];
	char			*p;
	unsigned int	unsigned_val;

	unsigned_val = (unsigned int)val;
	if (base > 36 || base < 2)
		return (NULL);
	buffer[output_size] = 0;
	p = buffer + output_size - 1;
	*p = '0';
	if (unsigned_val > 0)
	{
		while (unsigned_val > 0)
		{
			*p-- = read_tab(unsigned_val % base);
			unsigned_val = unsigned_val / base;
			if (p < buffer)
				break ;
		}
		p++;
	}
	while (p > buffer)
		*--p = '0';
	return (ft_strdup(p));
}

int		print_section(struct section_64 *section, char *ptr)
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
			print_addr(addr);
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

int		add_section(void *lc, t_data *data, char *ptr)
{
	int							i;
	int							nsects;
	struct segment_command_64	*seg;
	struct section_64			*sec;

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
			if (print_section(sec, ptr + sec->offset) == -1)
				return (-1);
		}
		sec = (void *)sec + sizeof(*sec);
		i++;
	}
	return (0);
}

int		get_sect_64(char *ptr, t_data *data)
{
	int							i;
	int							ncmds;
	struct load_command			*lc;
	struct mach_header_64		*header;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			if (add_section(lc, data, ptr) == -1)
				return (-1);
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
