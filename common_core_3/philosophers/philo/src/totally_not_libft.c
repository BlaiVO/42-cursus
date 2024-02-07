/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totally_not_libft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:52:06 by blvilarn          #+#    #+#             */
/*   Updated: 2024/02/07 17:27:57 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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
	if (!ft_isdigit(str[i]) && str[i] != '+')
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
	if (ft_atoi(str) == 0)
		return (0);
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
