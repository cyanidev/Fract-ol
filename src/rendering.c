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

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
	int	bcolor;
	int	red;
	int	green;
	int	blue;

	bcolor = 0xD2F559;
	if (n == MAX_ITERATION)
		return (0x000000);
	else if (n < MAX_ITERATION / 2)
	{
		red = ((bcolor >> 16) & 0xFF) * n / (MAX_ITERATION / 2);
		green = ((bcolor >> 8) & 0xFF) * n / (MAX_ITERATION / 2);
		blue = (bcolor & 0xFF) * n / (MAX_ITERATION / 2);
		return ((red << 16) | (green << 8) | blue);
	}
	else if (n < MAX_ITERATION * 3 / 4)
		return (0xFFFB00);
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
/*It calculates the memory address of the pixel in the image buffer based
on the given x and y coordinates and the properties of the image 
(line_length and bits_per_pixel).
line_length represents the number of bytes occupied by each line of pixels in 
the image buffer. bits_per_pixel represents the number of bits used to 
represent each pixel. It assigns the calculated memory address to the dst 
pointer which points to the location in the image buffer where 
the pixel color will be stored.
It assigns the color value to the memory location pointed by dst, which effectively 
sets the color of the pixel in the image buffer.
By using this function, you can set the color of individual pixels in an 
image buffer, allowing you to create images or render graphics by manipulating 
the pixel colors. The scaling the color values based on the iteration count 
n relative to the maximum iteration value MAX_ITERATION. The color values 
(red, green, blue) are multiplied by n, which represents the current iteration 
count. Then, the result is divided by (MAX_ITERATION / 2), which represents 
half of the maximum iteration count. This division ensures that the color 
values scale proportionally based on how close the current iteration count is 
to the halfway point of the maximum iterations. If n is less than 
(MAX_ITERATION / 2), the result will be less than 1.0, resulting in a darker 
color. If n is greater than (MAX_ITERATION / 2), the result will be greater 
than 1.0, resulting in a lighter color. By applying this scaling factor, 
the color values are gradually transitioned from black to the specified 
color (bcolor) as the iteration count progresses.*/