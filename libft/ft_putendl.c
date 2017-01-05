/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:31:39 by nfruneau          #+#    #+#             */
/*   Updated: 2013/12/08 20:38:33 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl(const char *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
	write(1, "\n", 1);
}
