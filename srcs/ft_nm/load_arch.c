/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
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
#include <mach-o/ranlib.h>
#include <mach-o/fat.h>
#include <ar.h>

int		load_arch_64(char *argv, char *ptr, t_data data, int display)
{
	if (get_sect_64(ptr, &data) == -1)
		return (-1);
	if (get_syms(ptr, &data) == -1)
		return (-1);
	print_file(argv, data, display);
	return (0);
}

int		load_arch_32(char *argv, char *ptr, t_data data, int display)
{
	if (get_sect_32(ptr, &data) == -1)
		return (-1);
	if (get_syms_32(ptr, &data) == -1)
		return (-1);
	print_file(argv, data, display);
	return (0);
}

void	load_archive(char *argv, char *ptr, t_data data)
{
	int				i;
	int				size;
	struct ar_hdr	*hd;
	struct ranlib	*ran;

	i = 0;
	hd = (void *)ptr + SARMAG;
	size = *((int *)((void*)hd + sizeof(*hd) + get_size(hd->ar_name)));
	size = size / sizeof(struct ranlib);
	ran = (void*)hd + sizeof(*hd) + get_size(hd->ar_name) + 4;
	while (i < size)
	{
		handle_ar(ptr, &data, ran[i].ran_un.ran_strx, ran[i].ran_off);
		i++;
	}
	print_ar(argv, ptr, data);
}

int		load_arch(char *argv, char *ptr, t_data data, int display)
{
	unsigned int	magic_number;

	magic_number = *(unsigned int *)ptr;
	if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		handle_fat(argv, ptr, data);
	else if (magic_number == MH_MAGIC_64)
		return (load_arch_64(argv, ptr, data, display));
	else if (!ft_strncmp(ptr, ARMAG, SARMAG))
		load_archive(argv, ptr, data);
	else if (magic_number == MH_MAGIC)
		return (load_arch_32(argv, ptr, data, display));
	else if (magic_number == MH_CIGAM || magic_number == MH_CIGAM_64)
		ft_putendl("big endian format not supported");
	else
		return (ft_error(NULL, "file format not valid"));
	return (0);
}
