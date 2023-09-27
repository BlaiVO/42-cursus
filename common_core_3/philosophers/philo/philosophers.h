/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:22:14 by blvilarn          #+#    #+#             */
/*   Updated: 2023/09/27 19:38:07 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_params
{
	int	n;
	int	ttd;
	int	tte;
	int	tts;
	int	eat_limit;
}	t_params;

//(not) libft
int	ft_iswhitespace(int c);
int	ft_isnum(char *str);
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
