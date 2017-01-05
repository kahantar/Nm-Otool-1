/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:50:44 by nfruneau          #+#    #+#             */
/*   Updated: 2014/02/04 12:10:16 by nfruneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_create_word(char const *s, int count_str, int count_word)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (count_word + 1));
	if (str == NULL)
		return (NULL);
	while (i + count_str < count_str + count_word)
	{
		str[i] = s[i + count_str];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**ft_cpy_word(char **tab, char const *s, char c)
{
	int		count_str;
	int		count_word;
	int		count_tab;

	count_str = 0;
	count_word = 0;
	count_tab = 0;
	while (s[count_str] != 0)
	{
		while (s[count_str] == c)
			count_str++;
		while (s[count_str + count_word] != c && s[count_str + count_word] != 0)
			count_word++;
		if (count_word > 0)
		{
			tab[count_tab] = ft_create_word(s, count_str, count_word);
			if (tab[count_tab] == NULL)
				return (NULL);
			count_tab++;
		}
		count_str += count_word;
		count_word = 0;
	}
	tab[count_tab] = 0;
	return (tab);
}

static char	**ft_memalloc_tab(char const *s, char c)
{
	int		i;
	int		j;
	int		count_nbr_w;
	char	**tab;

	i = 0;
	j = 0;
	count_nbr_w = 0;
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != 0)
			j++;
		if (j > 0)
			count_nbr_w++;
		i = i + j;
		j = 0;
	}
	tab = (char **)malloc(sizeof(char *) * (count_nbr_w + 1));
	if (tab == NULL)
		return (NULL);
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (s && c)
	{
		tab = ft_memalloc_tab(s, c);
		if (tab == NULL)
			return (NULL);
		tab = ft_cpy_word(tab, s, c);
		if (tab == NULL)
			return (NULL);
		else
			return (tab);
	}
	return (NULL);
}
