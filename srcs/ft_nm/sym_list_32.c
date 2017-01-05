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

int		add_elem2_32(void *ptr, char *stringtable, t_data *data)
{
	t_file			*tmp;
	struct nlist	array;

	array = *(struct nlist *)ptr;
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
	tmp->arch = 32;
	tmp->next = NULL;
	if (data->file)
		sort_list(&data->file, tmp, data->flag);
	else
		data->file = tmp;
	return (0);
}

int		add_elem_32(void *sym2, char *ptr, t_data *data)
{
	int						i;
	char					*stringtable;
	struct nlist			*array;
	struct symtab_command	*sym;

	sym = sym2;
	i = 0;
	array = (void *)ptr + sym->symoff;
	stringtable = ptr + sym->stroff;
	while (i < (int)sym->nsyms)
	{
		if (add_elem2_32(&array[i], stringtable, data) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int		get_syms_32(char *ptr, t_data *data)
{
	int						i;
	int						ncmds;
	struct load_command		*lc;
	struct mach_header		*header;
	struct symtab_command	*sym;

	i = 0;
	header = (struct mach_header *)ptr;
	ncmds = header->ncmds;
	lc = (void *)ptr + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *)lc;
			if (add_elem_32(sym, ptr, data) == -1)
				return (-1);
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
		i++;
	}
	return (0);
}
