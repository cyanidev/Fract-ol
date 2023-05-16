/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:29:47 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/15 03:04:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	painting(int size, t_data *data, int color)
{
	int		i;
	int		j;
	double	cr;
	double	ci;
	int		n;

	i = 0;
	n = 0;
	j = 0;
	cr = data->min_r + (data->max_r - data->min_r) * (double)j / WIDTH;
	ci = data->min_i + (data->max_i - data->min_i) * (double)i / HEIGHT;
	while (i < size)
	{
		j = 0;
		while (j < size)
			select(data, cr, ci, &n);
		color = get_color(n);
		my_mlx_pixel_put(data, j, i, color);
		j++;
	}
	i++;
}

static void	select(t_data data, double cr, double ci, int *n)
{
	if (data->code == 1)
		*n = mandelbrot(&data, cr, ci);
	else if (data->code == 3)
		*n = mandelbox(&data, cr, ci);
	else if (data->code == 2)
		*n = julia(&data);
}

static int get_color(int n)
{
	if (n == 60)
	{
	return 0x000000;
	}
	else {
	double t = 1.0 - ((double)n / 60.0); // Normalized value between 0 and 1
	double r, g, b;
	r = t; // Red increases from 0.0 to 1.0
	g = t; // Green increases from 0.0 to 1.0
	b = t; // Blue increases from 0.0 to 1.0
	return rgb_to_int(r, g, b);
	}
}

void painting(int size, t_data *data, int color)
{
    int i;
    int j;
    double cr;
    double ci;
    int n;

    i = 0;
    n = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            cr = data->min_r + (data->max_r - data->min_r) * (double)j / WIDTH;
            ci = data->min_i + (data->max_i - data->min_i) * (double)i / HEIGHT;
            select(data, cr, ci, &n);
            color = get_color(n);
            my_mlx_pixel_put(data, j, i, color);
            j++;
        }
        i++;
    }
}
