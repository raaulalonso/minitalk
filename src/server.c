/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:00:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/01 20:31:13 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	handler(int sig)
{
	static int c = 0;
	static int bit = 0;
	
	if (sig == SIGUSR1)
	{
		c <<= 1;
		c += 1;
		bit++;
	}
	if (sig == SIGUSR2)
	{
		c <<= 1;
		bit++;
	}
	if (bit == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	int	pid;
	signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
	
	pid = getpid();
	ft_printf("PID ---->>> | %d |\n", pid);
	ft_printf("--Print Area-------------------------------------------------\n");
	while (1)
	{
		pause();
	}
}