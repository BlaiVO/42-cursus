/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:57:33 by blvilarn          #+#    #+#             */
/*   Updated: 2023/01/12 20:05:59 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("ft_bytes = %d\n", ft_printf("%p ", (void *)-1));
	printf("bytes = %d\n", printf("%p ", (void *)-1));
}
