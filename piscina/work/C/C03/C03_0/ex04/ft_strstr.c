/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:22:01 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/26 15:59:06 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str + i - j);
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*haystack = "Like finding a needle in a haystack";
	char	*needle = "needle";

	printf("%s\n", strstr(haystack, needle));
	printf("%s\n", ft_strstr(haystack, needle));
	return (0);
}
*/
