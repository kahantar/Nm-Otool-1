/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 14:39:26 by nfruneau          #+#    #+#             */
/*   Updated: 2015/01/28 12:50:37 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_otool.h"

t_flag	new_flag(void)
{
	t_flag	flag;

	flag.r = 0;
	flag.j = 0;
	flag.p = 0;
	flag.u = 0;
	flag.up_u = 0;
	return (flag);
}

t_flag	set_flag(t_flag flag, char c)
{
	if (c == 'j')
		flag.j = 1;
	else if (c == 'u')
		flag.u = 1;
	else if (c == 'U')
		flag.up_u = 1;
	else if (c == 'r' && flag.p == 0)
		flag.r = 1;
	else if (c == 'p')
	{
		flag.p = 1;
		flag.r = 0;
	}
	return (flag);
}

t_flag	init_flag(char **argv)
{
	int		i;
	int		j;
	t_flag	flag;

	i = 1;
	flag = new_flag();
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--") == 0)
			return (flag);
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j])
			{
				flag = set_flag(flag, argv[i][j]);
				j++;
			}
		}
		i++;
	}
	return (flag);
}

int		is_flag(char c)
{
	if (c == 'r' || c == 'u' || c == 'U' || c == 'j' || c == 'p')
		return (1);
	else
		return (-1);
}

int		parse_cmd(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--") == 0)
			return (1);
		j = 1;
		if (argv[i][0] == '-')
		{
			while (argv[i][j])
			{
				if (is_flag(argv[i][j]) == 1)
					j++;
				else
					return (ft_error("illegal option: ", argv[i]));
			}
		}
		else
			return (1);
		i++;
	}
	return (1);
}
