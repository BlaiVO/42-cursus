/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:35:08 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/05 11:39:39 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(const char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || \
		c == '\v' || c == '\f')
		return (1);
	return (0);
}
