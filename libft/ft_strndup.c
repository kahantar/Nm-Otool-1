/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:57:35 by nfruneau          #+#    #+#             */
/*   Updated: 2013/12/07 21:22:58 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *str, size_t i)
{
	size_t	j;
	char	*str2;

	j = 0;
	if (str == NULL)
		return (NULL);
	str2 = (char *)malloc(sizeof(char) * i + 1);
	while (str[j] && j < i)
	{
		str2[j] = str[j];
		j++;
	}
	str2[j] = '\0';
	if (str2 == NULL)
		return (NULL);
	return (str2);
}
