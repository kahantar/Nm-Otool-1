/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 22:27:44 by nfruneau          #+#    #+#             */
/*   Updated: 2016/02/22 22:27:46 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/ft_otool.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

int		skip_flags(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-' || ft_strcmp(argv[i], "-") == 0)
			return (i);
		else if (ft_strcmp(argv[i], "--") == 0)
			return (i + 1);
		i++;
	}
	return (i);
}

int		arg_nbr(char **argv)
{
	int		i;
	int		j;

	j = 0;
	i = skip_flags(argv);
	while (argv[i++])
		j++;
	return (j);
}

int		ft_otool(char *argv, t_data data)
{
	int			fd;
	struct stat	buf;
	char		*ptr;

	if ((fd = open(argv, O_RDONLY)) < 0)
		return (ft_error("open failure: ", argv));
	if (fstat(fd, &buf) < 0)
		return (ft_error("fstat failure: ", argv));
	if (S_ISREG(buf.st_mode) || S_ISLNK(buf.st_mode) || S_ISSOCK(buf.st_mode))
	{
		if ((ptr = mmap(0, buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0))
			== MAP_FAILED)
			return (ft_error("mmap failure: ", argv));
		if (load_arch(argv, ptr, data, 1) == -1)
			return (-1);
		if (munmap(ptr, buf.st_size) < 0)
			return (ft_error("munmap error: ", argv));
	}
	else
		return (ft_error(argv, " is not a binary file"));
	return (0);
}

int		main(int argc, char **argv)
{
	int			i;
	t_data		data;

	i = 0;
	if (argc < 2)
		return (ft_error(NULL, "missing argument"));
	if (parse_cmd(argv) == 1)
	{
		init_data(&data, argv);
		i = skip_flags(argv);
		while (i < argc)
		{
			if (argv[i][0] != '-')
			{
				if (ft_otool(argv[i], data) == -1 && i == (argc - 1))
					return (-1);
				reset_data(&data);
			}
			i++;
		}
	}
	return (0);
}
