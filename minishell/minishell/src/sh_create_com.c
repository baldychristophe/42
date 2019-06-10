/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_create_com.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:43:34 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/12 18:49:12 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int		ft_next_d(char *s, char d)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return (i);
		i++;
	}
	return (i);
}

static int		ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int		ft_len_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char			**mod_strsplit(char const *s, char c, char d)
{
	size_t	i[3];
	char	**str;

	str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (str == NULL || s == NULL)
		return (NULL);
	i[1] = 0;
	i[0] = 0;
	while (s[i[0]])
	{
		if (s[i[0]] == c)
			i[0]++;
		else if (s[i[0]] != '\0')
		{
			str[i[1]] = ft_strsub(s, i[0], ft_len_word(&s[i[0]], c));
			i[0] = i[0] + ft_len_word(&s[i[0]], c);
			i[1]++;
		}
	}
	str[i[1]] = NULL;
	return (str);
}
