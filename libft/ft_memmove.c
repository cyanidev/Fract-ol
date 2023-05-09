/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:50:24 by afelicia          #+#    #+#             */
/*   Updated: 2023/03/05 20:44:52 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (cdest < csrc)
	{
		ft_memcpy(cdest, csrc, n);
	}
	else
	{
		i = n;
		while (i > 0)
		{
			cdest[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dest);
}

/*
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src > dest)
		ft_memcpy((char *)dest, (char *)src, n);
	while (n > 0)
	{
		(char *)dest[n - 1] = (char *)src[n -1];
		n--;
	}
	return (dest);
} */
