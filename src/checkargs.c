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
	int					i;
	static const double	julia_table[9][3] = {
	{'1', 0.096667, -0.613333},
	{'2', 0.183333, 0.596667},
	{'3', -0.7269, 0.1889},
	{'4', 0.28, 0.008},
	{'5', -0.12, -0.77},
	{'6', -1.476, 0},
	{'7', -0.79, 0.15},
	{'8', -0.162, 1.04},
	{'9', 0.3, 0.0}
	};

	i = 0;
	while (i < 9)
	{
		if (argv == julia_table[i][0])
		{
			f->kr = julia_table[i][1];
			f->ki = julia_table[i][2];
		}
		i++;
	}
}

void	twoargcs(char **argv, t_data *f)
{
	int	i;

	i = 0;
	while (ft_isalpha(argv[1][i]))
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			argv[1][i] -= 32;
		i++;
	}
	if (ft_strncmp(argv[1], "M", 2) == 0 || ft_strncmp(argv[1],
			"MANDELBROT", 10) == 0)
		f->code = 1;
	else if (ft_strncmp(argv[1], "X", 2) == 0 || ft_strncmp(argv[1],
			"MANDELBOX", 9) == 0)
		f->code = 3;
	else if (!ft_strncmp(argv[1], "T", 2) || !ft_strncmp(argv[1], "TRICORN", 9))
		f->code = 4;
	else if (!ft_strncmp(argv[1], "J", 2) || !ft_strncmp(argv[1], "JULIA", 5))
	{
		f->kr = -0.766667;
		f->ki = -0.090000;
		f->code = 2;
	}
	else
		printf("Not recognized fractal. ");
}

void	treeargcs(char **argv, t_data *f)
{
	int	i;

	i = 0;
	while (ft_isalpha(argv[1][i]))
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			argv[1][i] -= 32;
		i++;
	}
	if (ft_strncmp(argv[1], "J", 2) == 0 || ft_strncmp(argv[1],
			"JULIA", 5) == 0)
	{
		if ((argv[2][0] >= 49 && argv[2][0] <= 57) && argv[2][1] == '\0')
		{
			f->code = 2;
			selectjulia(argv[2][0], f);
		}
		else
			printf("Please enter a value between 1 and 9 without cero. ");
	}
}

void	checkargs(int argc, char **argv, t_data *f)
{
	if (argc == 2)
	{
		twoargcs(argv, f);
	}
	else if (argc == 3)
	{
		treeargcs(argv, f);
	}
	else if (argc == 1 || argc > 3)
		printf("Utilization: please enter M or Mandelbrot for the same name set"
			", J or Julia for the same name set; additionaly a number between"
			"1 and 9. EXTRA: X or Mandelbox, T or Tricorn for the same set. ");
}
