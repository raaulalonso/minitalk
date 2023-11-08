/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:13:19 by raalonso          #+#    #+#             */
/*   Updated: 2023/11/08 18:47:54 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*str2;

	str = (char *)src;
	str2 = (char *)dst;
	if (src < dst)
	{
		str2 += (len - 1);
		str += (len - 1);
		while (len)
		{
			*str2 = *str;
			len--;
			str2--;
			str--;
		}
	}
	else
	{
		ft_memcpy(str2, str, len);
	}
	return (dst);
}
