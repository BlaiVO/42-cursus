/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:43:25 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/27 20:11:16 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static t_params	get_params(int argc, char **args)
{
	int			i;
	t_params	params;

	i = 0;
	params.n = -1;
	while (i < argc)
	{
		if (!ft_isnum(args[i]))
			return (params);
		i++;
	}
	params.n = ft_atoi(args[0]);
	params.ttd = ft_atoi(args[1]);
	params.tte = ft_atoi(args[2]);
	params.tts = ft_atoi(args[3]);
	params.eat_limit = -1;
	if (argc == 5)
		params.eat_limit = ft_atoi(args[4]);
	return (params);
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (argc != 5 && argc != 6)
		return (1);
	params = get_params(argc - 1, &argv[1]);
	if (params.n == -1)
		return (1);
	return (0);
}
