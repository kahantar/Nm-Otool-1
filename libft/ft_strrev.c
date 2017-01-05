/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 20:20:13 by nfruneau          #+#    #+#             */
/*   Updated: 2013/12/12 20:49:54 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (str == NULL)
		return (NULL);
	j = ft_strlen(str) - 1;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (j >= 0)
	{
		tmp[i] = str[j];
		i++;
		j--;
	}
	tmp[i] = '\0';
	return (tmp);
}
