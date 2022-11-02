/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:39:08 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/19 10:50:54 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i] != '\0')
	{
		dest[i] = src[i];
	}
	return (dest);
}

/*
int	main(void)
{
	char str[4] = "Hola";
	char str2[4];

	ft_strcpy(str2, str);
	for (int i = 0; i < 4; i++)
		printf("%c", str2[i]);
	return (0);
}
*/
