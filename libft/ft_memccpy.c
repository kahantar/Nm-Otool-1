/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:01:38 by nfruneau          #+#    #+#             */
/*   Updated: 2013/11/30 19:35:12 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*tmp2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp2 != (unsigned char)c && n > 0)
	{
		*tmp = *tmp2;
		tmp++;
		tmp2++;
		n--;
	}
	if (*tmp2 == (unsigned char)c && n > 0)
	{
		*tmp = *tmp2;
		tmp++;
		return (tmp);
	}
	return (NULL);
}
