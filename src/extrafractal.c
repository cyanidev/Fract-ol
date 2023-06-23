/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrafractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:36:21 by marvin            #+#    #+#             */
/*   Updated: 2023/05/17 23:15:45 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	box_fold(double v) //reflects the vector component back to a range between -1 and 1
{
	if (v > 1)
		v = 2 - v;
	else if (v < -1)
		v = -2 - v;
	return (v);
}
//box_fold performs a folding operation on a given value. 
//It takes the value 'v' and folds it back to a range between -1 and 1. If 'v' 
//is greater than 1, it reflects it back by subtracting it from 2. If 'v' is
//less than -1, it reflects it back by adding 2.

static double	ball_fold(double r, double m)
{
	if (m < r)
		m = m / (r * r);
	else if (m < 1)
		m = 1 / (m * m);
	return (m);
}
//ball_fold' is another folding operation applied specifically to the radius
//value 'm'. It adjusts the folding behavior based on the radius value 
//relative to 'r'. If 'm' is less than 'r', it performs a scaling operation
//by dividing 'm' by the square of 'r'. If 'm' is between 'r' and 1, 
//it performs a different scaling operation by dividing 1 by the square of 'm'.
//adjusts the folding behavior based on the magnitude of the vectors. 
//It performs different scaling operations depending on whether the magnitude is 
//less than a certain radius value 'r' or within a range between 'r' and 1. 

//These folding operations help shape the behavior and patterns of 
//the Mandelbox fractal by modifying the vector values and adjusting the 
//folding behavior based on certain conditions and scaling factors.

int	mandelbox(t_data *f, double cr, double ci)
{
	int		n;
	double	vr;
	double	vi;
	double	mag;

	vr = cr;
	vi = ci;
	mag = 0;
	n = 0;
	// 'vr' and 'vi' represent the real and imaginary components of a complex vector, respectively.
	while (n < 60)
	{
		vr = f->fx * box_fold(vr);
		vi = f->fx * box_fold(vi);
		mag = sqrt(vr * vr + vi * vi);
		vr = vr * f->sx * ball_fold(f->rx, mag) + cr;
		vi = vi * f->sx * ball_fold(f->rx, mag) + ci;
		if (sqrt(mag) > 2)
			break ;
		n++;
	}
	return (n);
}
