/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blai <blai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:51:36 by blai              #+#    #+#             */
/*   Updated: 2023/08/23 17:51:38 by blai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	validate_pid(char *pid);
static void	send_string(unsigned char *str, pid_t pid);
static void	signal_hook(int sig);

int	g_returner = 1;

int	main(int argc, char **argv)
{
	pid_t		pid;	

	if (argc != 3 || !validate_pid(argv[1]))
		return (1);
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, signal_hook);
	send_int(ft_strlen(argv[2]), pid);
	send_int(getpid(), pid);
	send_string((unsigned char *)argv[2], pid);
	usleep(100);
	return (g_returner);
}

void	send_int(int n, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if ((n & (2147483648 >> i)) == 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		usleep(100);
		i++;
	}
}

static void	send_string(unsigned char *str, pid_t pid)
{
	int	i;
	int	bit_count;

	i = 0;
	while (str[i] != '\0')
	{
		bit_count = 0;
		while (bit_count < 8)
		{
			if ((str[i] & (128 >> bit_count)) == 0)
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			usleep(100);
			bit_count++;
		}
		i++;
	}
}

static int	validate_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i]))
			return (0);
		i++;
	}
	if (ft_strlen(pid) < 3 || ft_strlen(pid) > 5)
		return (0);
	return (1);
}

static void	signal_hook(int sig)
{
	if (sig == SIGUSR1)
		g_returner = 0;
}
