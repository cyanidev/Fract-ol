/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:29:20 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/17 23:21:54 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	zr_n;
	double	zi_n;
	int		n;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < 60 && (zr * zr - zi * zi) < 4)
	{
		zr_n = zr * zr - zi * zi + cr;
		zi_n = 2 * zr * zi + ci;
		zr = zr_n;
		zi = zi_n;
		n++;
	}
	return (n);
}

int	julia(t_data *data)
{
	double	zr;
	double	zi;
	double	zr_n;
	double	zi_n;
	int		n;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < 60 && (zr * zr - zi * zi) < 4)
	{
		zr_n = zr * zr - zi * zi + data->kr;
		zi_n = 2 * zr * zi + data->ki;
		zr = zr_n;
		zi = zi_n;
		n++;
	}
	return (n);
}

int	tricorn(double cr, double ci)
{
	double	zr;
	double	zi;
	double	zr_n;
	double	zi_n;
	int		n;

	zr = cr;
	zi = ci;
	n = 0;
	while (n < 60 && (zr * zr - zi * zi) < 4)
	{
		zr_n = zr * zr - zi * zi + cr;
		zi_n = 2 * zr * zi + ci;
		zr = zr_n;
		zi = zi_n;
		n++;
	}
	return (n);
}
// c is the number we want to test for
//si la formula es mayor a 4 no es parte del set si es menor es parte
//original formula is √(Zr^2 + Zi^2) > 2 but when you square a square
// root you simplify the expression and we need to do it in both sides
// it would be 2^2 = 4 i.e = (√16)^2 = 4^2 = 16 :)
