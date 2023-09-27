/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:42:34 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/27 17:43:39 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || \
		c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}