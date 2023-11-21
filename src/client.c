/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:00:30 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/21 08:30:10 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

/**
 * @brief Sends a character in binary format to a process with a given PID.
 * 
 * @param c The character to be sent.
 * @param pid The process ID of the receiving process.
 */
void send_binary(char c, int pid)
{
	int i;
	char bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR1);
		else if (bit == 0)
			kill(pid, SIGUSR2);
		i--;
		usleep(50);
	}
}

/**
 * @brief Checks if a process with the given PID exists.
 * 
 * @param pid The process ID to be checked.
 */
void check_pid(int pid)
{
	if (kill(pid, 0) != 0)
	{
		ft_printf("Error: Invalid PID\n");
		exit(1);
	}
}

/**
 * @brief The main function of the client program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return int Returns 0 on successful execution.
 */
int main(int argc, char **argv)
{
	int pid;
	char *str;
	int i;

	if (argc != 3)
	{
		ft_printf("Error: Invalid arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	check_pid(pid);
	str = ft_strdup(argv[2]);
	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		send_binary(str[i], pid);
		i++;
	}
	free(str);
	return (0);
}
