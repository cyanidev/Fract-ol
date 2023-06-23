/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:08:57 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/18 00:29:35 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init(t_data *f)
{
	if ((f->code == 1) || (f->code == 4)) //mandelbrot or tricorn porque el centro esta situado un poco a la derecha
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	}
	else if (f->code == 3) //mandelbox mas grande
	{
		f->min_r = -4.0;
		f->max_r = 4.0;
		f->min_i = -4.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
		f->sx = 2.0; //another scaling factor that is used in the calculation of the new vector values during the iteration process.
		f->rx = 0.5; //represents a radius value used in the ball folding operation. It influences the folding behavior based on the magnitude of the vectors.
		f->fx = 1.0; //a scaling factor that affects the folding operation applied to the vectors 'vr' and 'vi' in the Mandelbox fractal calculation.
	}
	else if (f->code == 2) //julia central
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
		//puede ser 1.5 pero se calcula para cambiar los valores del alto y ancho 
		//de la ventana para no distorcionar el fractal.
	}
}

void	render(t_data *data)
{
	int	color;

	color = 0;
	mlx_clear_window(data->mlx, data->win); // this might be needed in each movement because were alocating with put_image_to_window
	painting(data, color); // iterates through each pixel on the screen
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

static void	nullinit(t_data *data)
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
	data->code = 0;
}

void	windowinit(t_data *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (f->win == NULL)
		ret_error("window fail");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img == NULL)
		ret_error("Cannot create an image");
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length,
			&f->endian);
	if (f->addr == NULL)
		ret_error("The pointer to the image failed");
}

int	main(int argc, char **argv)
{
	t_data	f;

	nullinit(&f);
	checkargs(argc, argv, &f);
	if (argc > 1 && f.code != 0)
	{	
		windowinit(&f);
		init(&f);
		render(&f);
		mlx_hook(f.win, EVENT_CLOSE_BTN, 0, close_esc, &f); // 0 because x_mask is ignored on macos
		mlx_key_hook(f.win, keycodes, &f);
		mlx_mouse_hook(f.win, mousecode, &f);
		mlx_loop(f.mlx);
	}
	else
		printf("Error: run the program to see utilization");
	return (0);
}
