/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:25:12 by blvilarn          #+#    #+#             */
/*   Updated: 2024/01/22 16:29:18 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	signal_hook(int sig);
static void	get_str(int sig, unsigned char *str, int bit_count);
static void	end_transmission(char *str, int *bit_count, int *len, int *pid);

int	main(void)
{
	ft_printf("%i\n", getpid());
	signal(SIGUSR1, signal_hook);
	signal(SIGUSR2, signal_hook);
	while ("Pedra")
		pause();
}

static void	signal_hook(int sig)
{
	static int				bit_count = -1;
	static int				len = 0;
	static int				pid = 0;
	static unsigned char	*str = NULL;

	if (++bit_count < 32)
		len = get_int(sig, bit_count, len);
	if (bit_count == 31)
	{
		str = ft_calloc(len + 1, sizeof(char));
		if (!str)
			exit(1);
	}
	if (bit_count >= 32 && bit_count < 64)
		pid = get_int(sig, bit_count - 32, pid);
	if (bit_count >= 64)
		get_str(sig, str, bit_count - 63);
	if (bit_count == 63 + len * 8)
		end_transmission((char *)str, &bit_count, &len, &pid);
}

int	get_int(int sig, int i, int n)
{
	if (sig == SIGUSR1)
		n = (n | (2147483648 >> i));
	return (n);
}

static void	get_str(int sig, unsigned char *str, int bit_count)
{
	static unsigned char	c = 0;
	static int				i = 0;

	if (sig == SIGUSR1)
		c |= 128 >> i;
	i++;
	if (bit_count % 8 == 0)
	{
		str[bit_count / 8 - 1] = c;
		c = 0;
		i = 0;
	}
}

static void	end_transmission(char *str, int *bit_count, int *len, int *pid)
{
	kill(*pid, SIGUSR1);
	ft_printf("%s\n", str);
	deep_free(&str);
	*bit_count = -1;
	*len = 0;
	*pid = 0;
}
