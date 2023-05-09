/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:45:45 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/03 19:07:53 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 53
# define WIDTH 900
# define HEIGHT 900

/*   *****KEYCODES******

	 ESC = 53
	 UP = 126
	 DOWN = 125
	 RIGHT = 124
	 LEFT = 123
	 SPACE = 49
	 M = 46
	 J = 38
	 ENTER 36
	 1 = 18
	 2 = 19
	 3 = 20
	 4 = 21
	 5 = 23
	 6 = 22
	 7 = 26
	 8 = 28
	 9 = 25
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	double min_r;
	double max_r;
	double min_i;
	double max_i;
    double	kr;
	double	ki;
	double	sx;
	double	rx;
	double	fx;
}	t_data;

int	color_converter(const char *str);

#endif
