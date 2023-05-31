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

void	selectjulia(char argv, t_data *f)
{
	if (argv == '1')
	{
		f->kr = 0.096667;
		f->ki = -0.613333;
	}
	else if (argv == '2')
	{
		f->kr = 0.183333;
		f->ki = 0.596667;
	}
	else if (argv == '3')
	{
		f->kr = -0.7269;
		f->ki = 0.1889;
	}
	else if (argv == '4')
	{
		f->kr = 0.28;
		f->ki = 0.008;
	}
	else if (argv == '5')
	{
		f->kr = -0.12;
		f->ki = -0.77;
	}
	else if (argv == '6')
	{
		f->kr = -1.476;
		f->ki = 0;
	}

}

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
		else if (ft_strncmp(argv[1], "J", 2) == 0 || ft_strncmp(argv[1], "JULIA", 5) == 0)
		{
			if (argc == 2)
			{
				f->kr = -0.766667;
				f->ki = -0.090000;
				f->code = 2;
			}
			else if (argc == 3)
			{
				if((argv[2][0] >= 48 && argv[2][0] <= 57) && argv[2][1] == '\0')
				{
					f->code = 2;
					selectjulia(argv[2][0], f);
				}
				else
					printf("Please enter a value between 0 and 9");
				
			}
		}
		else if (ft_strncmp(argv[1], "X", 2) == 0 || ft_strncmp(argv[1], "MANDELBOX", 9) == 0)
				f->code = 3;
		else if (ft_strncmp(argv[1], "T", 2) == 0 || ft_strncmp(argv[1], "TRICORN", 9) == 0)
				f->code = 4;
		else
			printf("ta mal");
;	}
	else
		printf("Utilization: please enter M or Mandelbrot for the same name set,"
					"J or Julia for the same name set additionaly kr and ki values"
					"between 2.0 and -2.0");
}
