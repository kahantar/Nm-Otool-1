/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:55:40 by nfruneau          #+#    #+#             */
/*   Updated: 2014/01/31 16:50:51 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strneg(int n, int i, int j)
{
	int		val;
	char	*str;

	n = -n;
	val = n;
	while (val > 9)
	{
		val = val / 10;
		i++;
	}
	str = (char *)malloc(sizeof(*str) * i + 2);
	while (j < i)
	{
		str[j] = n % 10 + 48;
		n = n / 10;
		j++;
	}
	str[j] = '-';
	j++;
	str[j] = '\0';
	str = ft_strrev(str);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_strpos(int n, int i, int j)
{
	int		val;
	char	*str;

	val = n;
	while (val > 9)
	{
		val = val / 10;
		i++;
	}
	str = (char *)malloc(sizeof(*str) * i + 1);
	while (j < i)
	{
		str[j] = n % 10 + 48;
		n = n / 10;
		j++;
	}
	str[j] = '\0';
	str = ft_strrev(str);
	if (str == NULL)
		return (NULL);
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	int		val;
	char	*str;

	i = 1;
	j = 0;
	val = n;
	str = ft_strnew(0);
	if (val == -2147483648)
		return (ft_strdup("-2147483648"));
	if (val < 0)
		return (ft_strneg(n, i, j));
	if (val >= 0)
		return (ft_strpos(n, i, j));
	return (str);
}
