/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:43:42 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/12 13:42:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	checkargs(int argc, char **argv)
{
	int	i;

	i = 0;
	if(argc > 1)
	{
		while(ft_isalpha(argv[1][i]))
		{
			if(argv[1][i] >= 'a' && argv[1][i] <= 'z')
				argv[1][i] -= 32; 
			i++;
		}
		if (ft_strncmp(argv[1], "M") == 0 || ft_strncmp(argv[1], "MANDELBROT") == 0)
				return (1);
		else if (ft_strncmp(argv[1], "J") == 0 || ft_strncmp(argv[1], "JULIA") == 0)
		{
			if (argc == 1)
			{
				f->kr = -0.766667;
				f->ki = -0.090000;
			}
			else
			{
				if (f->kr > 2.0 || f->kr < -2.0)
					printf("Please enter a kr value between 2.0 and -2.0");
				if (f->ki > 2.0 || f->ki < -2.0)
					printf("Please enter a ki value between 2.0 and -2.0");
			}
			return (2);
		}
		else if (ft_strncmp(argv[1], "X") == 0 || ft_strncmp(argv[1], "MANDELBOX") == 0)
				return (3);
	}
	printf("Utilization: please enter M or Mandelbrot for the same name set,
				J or Julia for the same name set additionaly kr and ki values between 2.0 and -2.0");
	return (0);
}

