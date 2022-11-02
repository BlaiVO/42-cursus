/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:25:54 by blvilarn          #+#    #+#             */
/*   Updated: 2022/07/19 16:45:52 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		if (!(*str >= 'a' && *str <= 'z' ) && !(*str >= 'A' && *str <= 'Z'))
			return (0);
		str++;
	}
	return (1);
}

/*
int main(void)
{
	printf("%d", ft_str_is_alpha("HolaSocElBlai"));
	printf("%d", ft_str_is_alpha("H0l4 S0( e1 B14i"));

	return (0);
}
*/
