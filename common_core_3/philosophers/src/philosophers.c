/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:43:25 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/27 17:45:32 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static t_params	get_params(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5)
	{
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 5 && argc != 6)
		return (1);
	return (0);
}
