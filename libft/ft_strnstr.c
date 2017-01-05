/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:47:51 by nfruneau          #+#    #+#             */
/*   Updated: 2013/11/30 18:08:01 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (NULL);
	if (s2[0] == '\0')
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s2[j] && s1[i + j] == s2[j] && (i + j) < n)
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
