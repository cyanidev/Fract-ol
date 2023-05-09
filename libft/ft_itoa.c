/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:54:48 by afelicia          #+#    #+#             */
/*   Updated: 2021/12/14 20:00:24 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nb)
{
	unsigned int	length;
	int				base;

	if (nb < 0)
		length = 2;
	else
		length = 1;
	base = nb / 10;
	while (base)
	{
		base /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nbr;

	len = ft_intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	nbr = n;
	str[len] = '\0';
	while (len-- > 0)
	{
		if (nbr < 0)
			str[len] = -(nbr % 10) + 48;
		else
			str[len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
