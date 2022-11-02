/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:10:17 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/27 14:06:39 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size_wannabe;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	size_wannabe = i + j;
	j = 0;
	while (src[j] != '\0' && j < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (size_wannabe);
}

/*
int	main(void)
{
	char			dest[13] = "Hello ";
	char			dest1[13]= "Hello ";
	char			src[7] = "World!";
	unsigned int	num = 5;

	unsigned int n1 = ft_strlcat(dest, src, num);
	unsigned int n2 = strlcat(dest1, src, num);
	printf("%d: %s\n%d: %s\n", n1, dest, n2, dest1);
}
*/
