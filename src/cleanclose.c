/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanclose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:19:44 by marvin            #+#    #+#             */
/*   Updated: 2023/05/10 22:19:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_esc(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win && data->mlx)
		mlx_destroy_window(data->mlx, data->win);
	exit (0);
}

void ret_error(char *error_msg)
{
	perror(error_msg);
	exit(EXIT_FAILURE);
}
