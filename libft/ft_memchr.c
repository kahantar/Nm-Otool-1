/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:31:27 by nfruneau          #+#    #+#             */
/*   Updated: 2014/01/12 17:30:03 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cpy;
	unsigned char	*tmp;

	i = 0;
	cpy = c;
	tmp = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	while (i < n)
	{
		if (tmp[i] == cpy)
			return (tmp + i);
		i++;
	}
	return (NULL);
}
