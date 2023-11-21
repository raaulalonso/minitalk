/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:00:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/21 08:31:53 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

/**
 * @brief Signal handler function for handling SIGUSR1 and SIGUSR2 signals.
 *        It converts the received signals into a character and prints it.
 *        It keeps track of the bits received to form a complete character.
 * 
 * @param sig The signal number received.
 */
void handler(int sig)
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

/**
 * @brief The main function of the server program.
 * 
 * This function sets up signal handlers for SIGUSR1 and SIGUSR2 signals.
 * It also prints the process ID (PID) and a banner.
 * The function then enters an infinite loop, waiting for signals to arrive.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(void)
{
	int pid;

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
