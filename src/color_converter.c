/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelicia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:16:20 by afelicia          #+#    #+#             */
/*   Updated: 2023/05/03 19:06:23 by afelicia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define RED_SHIFT 16
//#define GREEN_SHIFT 8
//#define BLUE_SHIFT 0

#include "fractol.h"
#include <stdio.h>

// cada pixel tiene 3 vallores red, green, blue que controla el color final
// cada color tiene un valor desde 0 a 255 para representar la intensidad
// con difernetes intensidades de estos tres clores podemos tener diferentes 
// colores finales, 255 es el tamaño maximo de unsigned char 255 = 1111 1111
//8 bits por color, 24 en total. un color hexadecimal es un unsigned int de 32bits
//representa los 3 colores del pixel y su transparencia "alpha"
//0xAARRGGBB si el alpha esta al maximo el color es opaco, si está en cero
//es totalmente transparente FF B3 26 ED (FF=1111 1111=255) (B3=1011 001=179)
//(ED=1110 1101= 237) 
int	color_converter(const char *str)
{
	int	i;
	int	n;
	int	result;

	i = 0;
	n = 0;
	result = 0;
	while(str[i])//A4
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = str[i] - 'A' + 10;
		else
			printf("bad color input");
		i++;
		result = result * 16 + n;
	}
	return (result);
}

/*int rgb_to_int(double r, double g, double b)
{
    int color = 0;
    color |= (int)(b * 255);
    color |= (int)(g * 255) << 8;
    color |= (int)(r * 255) << 16;
    return (color);
}

int	main()
{
	char *str = "FF2E00";
	int	result = color_converter(str);
	printf("%d", result);
}*/
