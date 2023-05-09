/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:29:47 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/09 17:29:57 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	painting(int size, t_data *data)
{
	int		i;
	int		j;
	double	cr;
	double	ci;
    int     n;

	cr = data->min_r + (data->max_r - data->min_r) * (double)j / WIDTH;
	ci = data->min_i + (data->max_i - data->min_i) * (double)i / HEIGHT;
    while(i < y + size)
    {
        j = x;
        while(j < x + size)
        {
            n = mandelbrot(&data, cr, ci);
        }
        if (n == 60)
            color = 0x000000;
        else if (n >= 0 && n < = 60 / 2 - 1)
        {
            color = 0xc031F6;
        }
        else if (n >= 60 / 2 && n <= 60 - 1)
        {
            color = 0xFFFFFF;
        }
        my_mlx_pixel_put(data, j, i, color);
        j++;
    }
    i++;
}

void keycodes(int keycode, t_data *data)
{
    double  distance = 0.1;
    double  c_i;
    double  c_r;

    c_r = data->max_r - data->min_r;
	c_i = data->max_i - data->min_i;
    printf("el codigo es:%d\n", keycode);
	if(keycode == KEY_ESC)
	{
		close_esc(data);
		return (0);
	}
	else if(keycode == 124) // der rght
	{
		data->min_r -= c_r * distance;
		data->max_r -= c_r * distance;
	}
	else if(keycode == 123)// izq left 
	{
		data->min_r += c_r * distance;
		data->max_r += c_r * distance;
	}
	else if(keycode == 126) // up
	{
		data->min_i += c_i * distance;
		data->max_i += c_i * distance;
	}
	else if(keycode == 125) // down
	{
		data->min_i -= c_i * distance;
		data->max_i -= c_i * distance;
	}
	else
		return(1);
	render(data);
	return (0);
}