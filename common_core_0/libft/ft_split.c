/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:46:48 by blvilarn          #+#    #+#             */
/*   Updated: 2024/08/21 15:49:29 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	counter;
	int	last_del;

	i = 0;
	counter = 0;
	last_del = 1;
	while (s && s[i] != '\0')
	{
		if (s[i] == c)
			last_del = 1;
		else
		{
			if (last_del)
			{
				last_del = 0;
				counter++;
			}
		}
		i++;
	}
	return (counter);
}

static char	*get_word(int *i, char const *s, char c)
{
	int		len;
	int		y;
	char	*word;

	len = 0;
	y = *i;
	while (s[y] != c && s[y] != '\0')
	{
		len++;
		y++;
	}
	word = ft_substr(s, *i, len);
	*i = y;
	return (word);
}

static char	**free_the_words(int cword, char **strings)
{
	int	i;

	i = 0;
	while (i < cword)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	int				cword;
	int				i;
	const int		words = count_words(s, c);

	if (!s)
		return (NULL);
	cword = 0;
	strings = ft_calloc(words + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s) && s[i] != '\0' && cword < words)
	{
		if (s[i] != c)
		{
			strings[cword] = get_word(&i, s, c);
			if (!strings[cword])
				return (free_the_words(cword, strings));
			cword++;
		}
		else
			i++;
	}
	return (strings);
}
