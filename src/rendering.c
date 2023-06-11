/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:29:47 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/18 00:27:50 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	selectfractal(t_data *data, double cr, double ci)
{
	if (data->code == 1)
		return (mandelbrot(cr, ci));
	else if (data->code == 3)
		return (mandelbox(data, cr, ci));
	else if (data->code == 4)
		return (tricorn(cr, ci));
	else if (data->code == 2)
		return (julia(data, cr, ci));
	return (0);
}

static int	get_color(int n)
{

	if (n >= 60)
		return (0x000000);
	else
		return (0xFFFFFF);
}

void	painting(t_data *data, int color)
{
	int		i;
	int		j;
	double	cr;
	double	ci;
	int		n;

	i = 0;
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			cr = data->min_r + (data->max_r - data->min_r) * (double)j / WIDTH;
			ci = data->min_i + (data->max_i - data->min_i) * (double)i / HEIGHT;
			n = selectfractal(data, cr, ci);
			color = get_color(n);
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}
