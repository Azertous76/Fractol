/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:43:34 by abailleu          #+#    #+#             */
/*   Updated: 2023/10/10 19:43:35 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int	i;
	int	color;
	
	
	i = 0;
	z.x = (0.0);
	z.y = (0.0);
	
	c.x = map(x, -2, 2, WIDTH);
	c.y = map(y, 2, -2, HEIGHT);
	
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y + z.y) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
}


void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while(y++ < HEIGHT)
	{
		x = -1;
		while(x++ < WIDTH)
		{
			handle_pixel(x, y, fractal);
		
		}	
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0, 0);
}
