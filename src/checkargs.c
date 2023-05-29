/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:45:19 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/18 00:22:47 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	checkargs(int argc, char **argv, t_data *f) 
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
		if (ft_strncmp(argv[1], "M", 2) == 0 || ft_strncmp(argv[1], "MANDELBROT", 10) == 0)
				f->code = 1;
		else if (ft_strncmp(argv[1], "J", 1) == 0 || ft_strncmp(argv[1], "JULIA", 5) == 0)
		{
			if (argc == 2)
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
			f->code = 2;
		}
		else if (ft_strncmp(argv[1], "X", 1) == 0 || ft_strncmp(argv[1], "MANDELBOX", 9) == 0)
				f->code = 3;
		else
			printf("ta mal");
;	}
	else
		printf("Utilization: please enter M or Mandelbrot for the same name set,"
					"J or Julia for the same name set additionaly kr and ki values"
					"between 2.0 and -2.0");
}

