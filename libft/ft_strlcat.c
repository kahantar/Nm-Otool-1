/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:39:02 by nfruneau          #+#    #+#             */
/*   Updated: 2013/11/30 18:06:37 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp1;
	char	*tmp2;

	if (dest == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	if (i > size)
		return (size + ft_strlen(src));
	j = 0;
	tmp1 = (char *)dest;
	tmp2 = (char *)src;
	len = ft_strlen(dest) + ft_strlen(src);
	while ((i + j) < size - 1 && tmp2[j])
	{
		tmp1[i + j] = tmp2[j];
		j++;
	}
	tmp1[i + j] = '\0';
	return (len);
}
