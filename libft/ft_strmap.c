/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:50:32 by nfruneau          #+#    #+#             */
/*   Updated: 2014/01/12 17:31:38 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s));
	while (i < ft_strlen(s))
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	if (str == NULL)
		return (NULL);
	return (str);
}
