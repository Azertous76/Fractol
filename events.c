/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:26:33 by abailleu          #+#    #+#             */
/*   Updated: 2023/10/10 21:26:35 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int key_handle(int keysym, t_fractal *fractal)
{
	if(keysym == XK_Escape)
	{
		close_handler(fractal);
	}
	/*else if(keysym == XK_Left)
	{
		
	}
	else if(keysym == XK_Right)
	{
		
	}
	else if(keysym == XK_Up)
	{
		
	}
	else if(keysym == XK_Down)
	{
	
	}
	else if(keysym == XK_plus)
	{
		
	}
	else if(keysym == XK_minus)
	{
		
	}*/
}
