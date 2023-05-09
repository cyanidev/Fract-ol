/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <afelicia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:33:15 by afelicia          #+#    #+#             */
/*   Updated: 2021/12/22 16:52:31 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*memoria;

	memoria = malloc(size * count);
	if (memoria == NULL)
		return (NULL);
	ft_bzero(memoria, count * size);
	return (memoria);
}
