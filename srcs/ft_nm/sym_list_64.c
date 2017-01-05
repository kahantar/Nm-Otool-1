/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_list.c                                         :+:      :+:    :+:   */
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
#include <mach-o/nlist.h>
#include <stdlib.h>

char	get_type_by_sect(unsigned char s, t_data *data)
{
	t_sect	*sect;

	sect = data->sect;
	while (sect)
	{
		if (s == sect->sect_nbr)
		{
			if (!ft_strcmp(sect->name, SECT_DATA))
				return ('d');
			else if (!ft_strcmp(sect->name, SECT_BSS))
				return ('b');
			else if (!ft_strcmp(sect->name, SECT_TEXT))
				return ('t');
			else
				return ('s');
		}
		sect = sect->next;
	}
	return ('s');
}

char	get_type(unsigned char c, unsigned char s, t_data *data)
{
	unsigned char	a;

	a = c & N_TYPE;
	if (a == N_UNDF)
		a = 'u';
	else if (a == N_PBUD)
		a = 'u';
	else if (a == N_ABS)
		a = 'a';
	else if (a == N_SECT)
		a = get_type_by_sect(s, data);
	else if (a == N_INDR)
		a = 'i';
	else
		a = '?';
	if (c & N_EXT && a != '?')
		c = ft_toupper(a);
	else
		return (a);
	return (c);
}

int		add_elem2(void *ptr, char *stringtable, t_data *data)
{
	t_file			*tmp;
	struct nlist_64	array;

	array = *(struct nlist_64 *)ptr;
	if (get_type(array.n_type, array.n_sect, data) == '?'
		|| !ft_strlen(stringtable + array.n_un.n_strx))
		return (0);
	if ((tmp = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (ft_error("malloc error", NULL));
	tmp->name = ft_strdup(stringtable + array.n_un.n_strx);
	tmp->type = get_type(array.n_type, array.n_sect, data);
	tmp->value = 0;
	if (array.n_value)
		tmp->value = (unsigned long)array.n_value;
	tmp->show_addr = 0;
	if ((array.n_type & N_TYPE) != N_UNDF)
		tmp->show_addr = 1;
	tmp->arch = 64;
	tmp->next = NULL;
	if (data->file)
		sort_list(&data->file, tmp, data->flag);
	else
		data->file = tmp;
	return (0);
}

int		add_elem(void *sym2, char *ptr, t_data *data)
{
	int						i;
	char					*stringtable;
	struct nlist_64			*array;
	struct symtab_command	*sym;

	sym = sym2;
	i = 0;
	array = (void *)ptr + sym->symoff;
	stringtable = ptr + sym->stroff;
	while (i < (int)sym->nsyms)
	{
		if (add_elem2(&array[i], stringtable, data) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int		get_syms(char *ptr, t_data *data)
{
	int						i;
	int						ncmds;
	struct load_command		*lc;
	struct mach_header_64	*header;
	struct symtab_command	*sym;

	i = 0;
	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			if (add_elem(sym, ptr, data) == -1)
				return (-1);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
