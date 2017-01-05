/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:06:16 by nfruneau          #+#    #+#             */
/*   Updated: 2014/01/12 17:30:58 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	tmp = str;
	while (i < n)
	{
		tmp[i] = c;
		i++;
	}
	return (str);
}
