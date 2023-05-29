/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:42:56 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/17 23:13:59 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	addition(int def, double c_r, double c_i, t_data *data)
{
	double	distance;

	distance = 0.1;
	if (def == 1)
	{
		data->min_i += c_i * distance;
		data->max_i += c_i * distance;
	}
	else
	{
		data->min_r += c_r * distance;
		data->max_r += c_r * distance;
	}
}

static void	zoom(t_data *data, double c_r, double c_i, double zoom)
{
	data->max_r = c_r + (data->max_r - c_r) * zoom;
	data->min_r = c_r + (data->min_r - c_r) * zoom;
	data->min_i = c_i + (data->min_i - c_i) * zoom;
	data->max_i = c_i + (data->max_i - c_i) * zoom;
}

static void	subtract(int def, double c_r, double c_i, t_data *data)
{
	double	distance;

	distance = 0.1;
	if (def == 1)
	{
		data->min_i -= c_i * distance;
		data->max_i -= c_i * distance;
	}
	else
	{
		data->min_r -= c_r * distance;
		data->max_r -= c_r * distance;
	}
}

int	keycodes(int keycode, t_data *data)
{
	double	c_i;
	double	c_r;

	c_r = data->max_r - data->min_r;
	c_i = data->max_i - data->min_i;
	if (keycode == KEY_ESC)
	{
		close_esc(data);
		return (0);
	}
	else if (keycode == 124)
		subtract(0, c_r, c_i, data);
	else if (keycode == 123)
		addition(0, c_r, c_i, data);
	else if (keycode == 125)
		addition(1, c_r, c_i, data);
	else if (keycode == 126)
		subtract(1, c_r, c_i, data);
	else
		return (1);
	render(data);
	return (0);
}

int	mousecode(int button, int x, int y, t_data *data)
{
	double	c_r;
	double	c_i;

	printf("cordinate x= %d\n", x);
	printf("cordinate y= %d\n", y);
	printf("boton pulsado= %d\n", button);
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

/*	
	printf("el codigo es:%d\n", keycode);*/
