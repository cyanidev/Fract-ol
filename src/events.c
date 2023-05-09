/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:56 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/09 23:44:05 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	keycodes(int keycode, t_data *data)
{
	double	distance;
	double	c_i;
	double	c_r;

	distance = 0.1;
	c_r = data->max_r - data->min_r;
	c_i = data->max_i - data->min_i;
	if (keycode == KEY_ESC)
	{
		close_esc(data);
		return (0);
	}
	else if (keycode == 124)
	{
		data->min_r -= c_r * distance;
		data->max_r -= c_r * distance;
	}
	else if (keycode == 123)
	{
		data->min_r += c_r * distance;
		data->max_r += c_r * distance;
	}
	else if (keycode == 126)
	{
		data->min_i += c_i * distance;
		data->max_i += c_i * distance;
	}
	else if (keycode == 125)
	{
		data->min_i -= c_i * distance;
		data->max_i -= c_i * distance;
	}
	else
		return (1);
	render(data);
	return (0);
}

int	mousecode(int button, int x, int y, t_data *data)
{
	double	c_r;
	double	c_i;

	c_r = data->min_r - data->max_r / 2.0;
	c_i = data->max_i - data->min_i / 2.0;
	if (button == 4)
		zoom(data, c_r, c_i, 0.9);
	else if (button == 5)
		zoom(data, c_r, c_i, 1.1);
	else
		return (1);
	render(data);
	return (0);
}

void	zoom(t_data *data, double c_r, double c_i, double zoom)
{
	data->max_r = c_r + (data->max_r - c_r) * zoom;
	data->min_r = c_r + (data->min_r - c_r) * zoom;
	data->min_i = c_i + (data->min_i - c_i) * zoom;
	data->max_i = c_i + (data->max_i - c_i) * zoom;
}

int	close_esc(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

/*	
	printf("el codigo es:%d\n", keycode);
	printf("cordinate x= %d\n", x);
	printf("cordinate y= %d\n", y);
	printf("boton pulsado= %d\n", button);*/