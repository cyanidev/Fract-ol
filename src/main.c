/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:47:05 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/12 03:25:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	init(t_data *data);
void painting(int size, t_point cur, t_data *data, int width, int height);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ret_error(char *error_msg);
void	render(t_data *data);
int	keycodes(int keycode, t_data *data);
int	mousecode(int button, int x, int y, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void painting(int size, t_point cur, t_data *data, int width, int height)
{
	int color;
	int x;	
	int y;
	int i;
	int j;
	double cr;
	double ci;
	double zr;
	double zr_n;
	double zi;
	double zi_n;
	int n;

	y = cur.y - size / 2;
	x = cur.x - size / 2;
	i = y;
	while(i < y + size)
	{
		j = x;
		while(j < x + size)
		{
			cr = data->min_r + (data->max_r - data->min_r) * (double)j / (double)width;
			ci = data->min_i + (data->max_i - data->min_i) * (double)i / (double)height;
			zr = 0;
			zi = 0;
			n = 0;
			//si la formula es mayor a 4 no es parte del set si es menor es parte del set
			//original formula is √(Zr^2 + Zi^2) > 2 but when you square a square root you simplify the
			//expression and we need to do it in both sides it would be 2^2 = 4 i.e = (√16)^2 = 4^2 = 16 :) 
			while (n < 60 && (zr * zr + zi * zi) < 4) //la magnitud del complex number excede el limite 2
			{
				zr_n = zr * zr - zi * zi + cr; // c is the number we want to test for 
				zi_n = 2 * zr * zi + ci;
				zr = zr_n;
				zi = zi_n;
				n++;
			}
			if(n == 60)
				color = 0x000000;
				//color = 0xC031F6;//pink
			/*else
				color = color_converter("FF0000") * i / 60;*/
			else if (n >= 0 && n <= 60 / 2 -1)
			{
				int endv;
				int startv;
				//endv = color_converter("00FFFF");
				//startv = color_converter("000000");
				endv = 0x00FFFF;
				startv = 0x000000;
				color = (endv - startv) * i / 60 + startv;
				//color = 0x000000;
				//color = 0x00FFFF;
			}
			else if(n >= 60 / 2 && n <= 60 -1)
			{
				color = 0xFFFFFF;
			}

				//color = color_converter("FF0000") * i / size;
				//color = 0xFFFFFF; //white
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void ret_error(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}

int close_esc(t_data *data)
{
	if(data->img)
		mlx_destroy_image(data->mlx, data->img);
	if(data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	render(t_data *data)
{
	t_point cur = {WIDTH / 2, HEIGHT / 2}; //centro	
	mlx_clear_window(data->mlx, data->win);
	painting(900, cur, data, WIDTH, HEIGHT);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	keycodes(int keycode, t_data *data)
{
	double distance = 0.1;
	double c_i;
	double c_r;

	c_r = data->max_r - data->min_r;
	c_i = data->max_i - data->min_i;
	//edge values modified by distance in a direction
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

int	mousecode(int button, int x, int y, t_data *data)
{
	printf("cordinate x= %d\n", x);
	printf("cordinate y= %d\n", y);
	printf("boton pulsado= %d\n", button);
	double zoom;
	double	c_ra;
	double	c_r;
	double	c_ia;
	double	c_i;
	double distance = 0.1;

	c_ra = data->max_r - data->min_r;
	c_ia = data->max_i - data->min_i;
	c_r = data->min_r - data->max_r / 2.0;
	c_i = data->max_i - data->min_i / 2.0;
	if(button == 4) // zoom in 
	{
		zoom = 0.9;
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		data->max_r = c_r + (data->max_r - c_r) * zoom;
		data->min_r = c_r + (data->min_r - c_r) * zoom;
		data->min_i = c_i + (data->min_i - c_i) * zoom;
		data->max_i = c_i + (data->max_i - c_i) * zoom;
		if (x < 0)
		{
			data->min_r += c_ra * distance;
			data->max_r += c_ra * distance;
		}
		else if (x > 0) // izq
		{
			data->min_r -= c_ra * distance;
			data->max_r -= c_ra * distance;
		}
		if(y < 0)
		{
			data->min_i += c_ia * distance;
			data->max_i += c_ia * distance;
		}
		else if(y > 0)
		{
			data->min_i -= c_ia * distance;
			data->max_i -= c_ia * distance;
		}
	}
	else if (button== 5) // zoom out
	{
		zoom = 1.1;
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		data->max_r = c_r + (data->max_r - c_r) * zoom;
		data->min_r = c_r + (data->min_r - c_r) * zoom;
		data->min_i = c_i + (data->min_i - c_i) * zoom;
		data->max_i = c_i + (data->max_i - c_i) * zoom;
		if (x < 0)
		{
			data->min_r -= c_ra * distance;
			data->max_r -= c_ra * distance;
		}
		else if (x > 0)
		{
			data->min_r += c_ra * distance;
			data->max_r += c_ra * distance;
		}
		if(y < 0)
		{
			data->min_i += c_ia * distance;
			data->max_i += c_ia * distance;
		}
		else if(y > 0)
		{
			data->min_i -= c_ia * distance;
			data->max_i -= c_ia * distance;
		}
	}
	else
		return(1);
	render(data);
	return(0);
}
void	init(t_data *data)
{
	/*
	julia
	data->min_r = -2.0;
	data->max_r = 2.0;
	data->min_i = -2.0;
	data->max_i = data->min_i + (data->max_r - data->min_r) * HEIGHT / WIDTH;*/
	data->min_r = -2.0;
	data->max_r = 1.0;
	data->min_i = -1.5;
	data->max_i = data->min_i + (data->max_r - data->min_r) * HEIGHT / WIDTH;
	data->sx = 2.0;
	data->rx = 0.5;
	data->fx = 1.0;
	data->kr = -0.766667;
	data->ki = -0.090000;
}

int	main()
{
	int	height = 900; //alto
	int width = 900; //ancho
	t_data img = {0};
	//t_point cur = {width / 2, height / 2}; //centro
	/*img.min_r = -2.0; //real axis izquierda x = 0 //-2.0
	img.max_r = 1.0; //real axis derecha y = 900 //1.0
	img.min_i = -1.5;//imaginary axis arriba y = 0 // -1.5
	img.max_i = img.min_i + (img.max_r - img.min_r) * height / width; //imaginary y = 898 puede ser 1.5 
	//pero se calcula para cambiar los valores del alto y ancho 
	//de la ventana para no distorcionar el fractal
*/
	
	img.mlx = mlx_init(); // initialice mlx
	img.win = mlx_new_window(img.mlx, width, height, "Fract'ol"); // create a window
	if(img.win == NULL)
		ret_error("fallo jeje");
	img.img = mlx_new_image(img.mlx, width, height);
	if(img.img == NULL)
		ret_error("no se creo la imegn ps");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	if(img.addr == NULL)
		ret_error("no se proceso el puntero de la imagen");

	init(&img);
	render(&img);
	//init(&img);
	//painting(900, cur, &img, width, height);

	//mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, EVENT_CLOSE_BTN, 0, close_esc, &img); // 0 because x_mask is ignored on macos
	mlx_key_hook(img.win, keycodes, &img);
	mlx_mouse_hook(img.win, mousecode, &img);
	mlx_loop(img.mlx); // infinite loop
	return(0);
}


