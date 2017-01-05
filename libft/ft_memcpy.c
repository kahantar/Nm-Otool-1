/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:01:38 by nfruneau          #+#    #+#             */
/*   Updated: 2014/01/12 17:30:38 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp2;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (i < n)
	{
		tmp[i] = tmp2[i];
		i++;
	}
	return (s1);
}
