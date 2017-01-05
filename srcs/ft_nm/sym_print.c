/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sym_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:27:44 by nfruneau          #+#    #+#             */
/*   Updated: 2016/02/22 22:27:46 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_nm.h"

unsigned long	ft_ullen(unsigned long n)
{
	int		i;

	i = 0;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void			ft_putaddr(unsigned long n)
{
	int			i;
	char		hex[13];
	static char	tab[] = "0123456789abcdef";

	ft_bzero(hex, 13);
	i = ft_ullen(n);
	while (n > 0)
	{
		hex[i] = tab[n % 16];
		n /= 16;
		i--;
	}
	hex[12] = '\0';
	ft_putstr(hex);
}

void			print_zeros(int i, unsigned long j)
{
	if (j > 0)
		i -= ft_ullen(j) + 1;
	while (--i > 0)
		ft_putchar('0');
}

void			print_file2(t_file *file, t_flag flag, int info)
{
	if (!ft_strncmp(file->name, "radr:", 5) || file->type == 'u')
		return ;
	if (info && !flag.j)
	{
		if (file->show_addr)
		{
			if (file->arch == 64)
				print_zeros(17, file->value);
			else if (file->arch == 32)
				print_zeros(9, file->value);
			if (file->value > 0)
				ft_putaddr(file->value);
		}
		else if (file->arch == 32)
			ft_putstr("        ");
		else
			ft_putstr("                ");
		ft_putchar(' ');
		ft_putchar(file->type);
		ft_putchar(' ');
	}
	ft_putendl(file->name);
}

void			print_file(char *argv, t_data data, int display)
{
	t_file	*tmp;

	tmp = data.file;
	if (data.arg_nbr > 1 && display)
	{
		ft_putchar('\n');
		ft_putstr(argv);
		ft_putstr(":\n");
	}
	while (tmp)
	{
		if (data.flag.u && data.flag.up_u)
			;
		else if (!data.flag.u && !data.flag.up_u)
			print_file2(tmp, data.flag, 1);
		else if (data.flag.up_u && (tmp->type == 'T' || tmp->type == 't'))
			print_file2(tmp, data.flag, 1);
		else if (data.flag.u && tmp->type == 'U')
			print_file2(tmp, data.flag, 0);
		tmp = tmp->next;
	}
}
