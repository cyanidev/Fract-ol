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

static void	selectfractal(t_data *data, double cr, double ci, int *n)
{
	if (data->code == 1)
		*n = mandelbrot(cr, ci);
	else if (data->code == 3)
		*n = mandelbox(data, cr, ci);
	else if (data->code == 4)
		*n = tricorn(cr, ci);
	else if (data->code == 2)
		*n = julia(data, cr, ci);
}

void hsv_to_rgb(double h, double s, double v, double *r, double *g, double *b)
{
    double c = v * s;
    double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
    double m = v - c;

    double r1, g1, b1;
    if (h < 60) {
        r1 = c;
        g1 = x;
        b1 = 0;
    } else if (h < 120) {
        r1 = x;
        g1 = c;
        b1 = 0;
    } else if (h < 180) {
        r1 = 0;
        g1 = c;
        b1 = x;
    } else if (h < 240) {
        r1 = 0;
        g1 = x;
        b1 = c;
    } else if (h < 300) {
        r1 = x;
        g1 = 0;
        b1 = c;
    } else {
        r1 = c;
        g1 = 0;
        b1 = x;
    }

    *r = (r1 + m);
    *g = (g1 + m);
    *b = (b1 + m);
}

/*static int get_color(int n)
{
	double	r;
	double	g;
	double	b;

	if (n == 60)
		return 0x000000;
	else if (n < 60 / 2) 
	{
		double t = (double)n / (60 / 2 - 1); // Normalized value between 0 and 1
		r = t; // Red increases from 0.0 to 1.0
		g = 0.0;
		b = 0.0; // black background
		return rgb_to_int(r, g, b);
	}
	else
	{
		double	t = (double)(n - 60 / 2) / (60 - 1);
		r = 1.0;
		g = t;
		b = 1.0 - t;
		return (rgb_to_int(r, g , b));
	}
}*/

int	get_color(int n)
{
    double hue, sat, val;
    if (n == 60)
        return 0x000000;

    // Calculate hue based on number of iterations
    hue = ((double)n / 60) * 360.0;

    // Set saturation and value to 1.0 for full intensity colors
    sat = 1.0;
    val = 1.0;

    // Convert HSV color to RGB and return as integer
    double r, g, b;
    hsv_to_rgb(hue, sat, val, &r, &g, &b);
    return rgb_to_int(r, g, b);
}

void	painting(int size, t_data *data, int color)
{
	int		i;
	int		j;
	double	cr;
	double	ci;
	int		n;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			cr = data->min_r + (data->max_r - data->min_r) * (double)j / WIDTH;
			ci = data->min_i + (data->max_i - data->min_i) * (double)i / HEIGHT;
			n = 0;
			selectfractal(data, cr, ci, &n);
			color = get_color(n);
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}
