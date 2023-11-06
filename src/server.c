/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:00:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/02 12:24:50 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	handler(int sig)
{
	static int	c = 0;
	static int	bit = 0;

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
	ft_printf("   ________  ______   _____  _____\n");
	ft_printf("  / ___/ _ \\/ ___/ | / / _ \\/ ___/\n");
	ft_printf(" (__  )  __/ /   | |/ /  __/ /    \n");
	ft_printf("/____/\\___/_/    |___/\\___/_/      PID ---> | %d |\n", pid);
	ft_printf("\n--Print Area-----------------------------------------\n\n");
	while (1)
	{
		pause();
	}
}
