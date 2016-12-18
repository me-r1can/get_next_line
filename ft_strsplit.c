/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlowe <nlowe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 15:47:10 by nlowe             #+#    #+#             */
/*   Updated: 2016/12/18 23:45:11 by nlowe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_word_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && *(s + 1) == c)
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		words;
	int		i;

	words = ft_word_count(s, c);
	i = 0;
	if(!(ret = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s && i < words)
	{
		if (*s == c)
			s++;
		else
		{
			ret[i] = ft_strndup(s, ft_wordlen(s, c));
			s = ft_strchr(s, c);
			i++;
		}
	}
	ret[i] = NULL;
	return (ret);
}
