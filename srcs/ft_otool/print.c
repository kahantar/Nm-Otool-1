/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:27:44 by nfruneau          #+#    #+#             */
/*   Updated: 2016/02/22 22:27:46 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_otool.h"

int				ft_error(char *s, char *s2)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(s2, 2);
	return (-1);
}

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

void			print_addr(long unsigned int addr)
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
	i = 17 - i;
	while (--i > 0)
		ft_putchar('0');
	ft_putaddr(addr);
	ft_putchar(' ');
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
