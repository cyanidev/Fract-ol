/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:08:57 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/09 22:14:53 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	f;
	int		n;

	n = checkargs(argc, argv);
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractol");
	if (f.win == NULL)
		ret_error("window fail");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	if (f.img == NULL)
		ret_error("Cannot create an image");
	f.addr = mlx_get_data_addr(f.img, &f.bits_per_pixel, &f.line_length,
			&f.endian);
	if (f.addr == NULL)
		ret_error("The pointer to the iamge failed");
	init(&f, n);
	render(&f);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, close_esc, &f);
	mlx_key_hook(f.win, keycodes, &f);
	mlx_mouse_hook(f.win, mousecode, &f);
	mlx_loop(f.mlx);
	return (0);
}

void	init(t_data *data, int n)
{
	if (n == 1)
	{
		data->min_r = -2.0;
		data->max_r = 1.0;
		data->min_i = -1.5;
	}
	else if (n == 3)
	{
		data->min_r = -4.0;
		data->max_r = 4.0;
		data->min_i = -4.0;
	}
	else if (n == 2)
	{
		data->min_r = -2.0;
		data->max_r = 2.0;
		data->min_i = -2.0;
	}
	data->max_i = data->min_i + (data->max_r - data->min_r) * HEIGHT / WIDTH;
}

void	nullinit(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->min_r = 0;
	data->max_r = 0;
	data->min_i = 0;
	data->max_i = 0;
    data->kr = 0;
	data->ki = 0;
	data->sx = 0;
	data->rx = 0;
	data->fx = 0;
}
/*
	data->sx = 2.0;
	data->rx = 0.5;
	data->fx = 1.0;
*/