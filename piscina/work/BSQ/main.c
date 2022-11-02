/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrodri2 <alrodri2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:35:54 by alrodri2          #+#    #+#             */
/*   Updated: 2022/07/26 06:39:58 by alrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 1)
	{
		while (i <= argc)
		{
			//1 - Preprocessing map
			//2 - Algorithm
			i++;
		}
	}
	else
		write(1, "No map found", 12);
}
