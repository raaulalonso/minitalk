/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:00:30 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/01 20:58:37 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minitalk.h"

void	send_binary(char c, int pid)
{
	int		i;
	char	bit;
	
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

int	main(int argc, char **argv)
{
	int	pid;
	char *str;
	int i;
	
	if (argc != 3)
	{
		ft_printf("Error: Invalid arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) != 0)
	{
		ft_printf("Error: Invalid PID\n");
		return (0);
	}
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
}