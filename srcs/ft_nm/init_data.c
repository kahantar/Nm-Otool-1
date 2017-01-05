/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
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

void	free_file(t_file *file)
{
	while (file)
	{
		free(file->name);
		free(file);
		file = file->next;
	}
}

void	free_sect(t_sect *sect)
{
	while (sect)
	{
		free(sect->name);
		free(sect);
		sect = sect->next;
	}
}

void	free_arch(t_arch *arch)
{
	while (arch)
	{
		free(arch->name);
		free(arch);
		arch = arch->next;
	}
}

void	reset_data(t_data *data)
{
	if (data->file)
		free_file(data->file);
	data->file = NULL;
	if (data->sect)
		free_sect(data->sect);
	data->sect = NULL;
	if (data->arch)
		free_arch(data->arch);
	data->arch = NULL;
}

void	init_data(t_data *data, char **argv)
{
	data->arg_nbr = arg_nbr(argv);
	data->flag = init_flag(argv);
	data->file = NULL;
	data->sect = NULL;
	data->arch = NULL;
}
