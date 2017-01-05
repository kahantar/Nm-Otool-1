/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 20:13:57 by nfruneau          #+#    #+#             */
/*   Updated: 2014/01/12 17:34:04 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * ft_strlen(s));
	while (ft_isspace(s[i]))
		i++;
	k = ft_strlen(s) - 1;
	while (ft_isspace(s[k]))
		k--;
	while (i <= k)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	if (str == NULL)
		return (NULL);
	return (str);
}
