/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:42:34 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/28 17:44:00 by blvilarn         ###   ########.fr       */
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

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
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
	if (str[i] == '+')
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

int	ft_atoi(const char *str)
{
	int	num;
	int	zrs;
	int	i;

	num = 0;
	zrs = 1;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		zrs = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	num *= zrs;
	return (num);
}
