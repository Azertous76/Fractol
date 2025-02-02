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

void	mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandel_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y + z.y) > fractal->escape_value)
		{
			color = map(i, fractal->colors1, fractal->colors2,
					fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	handle_burning_ship_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.x = z.x;
	c.y = z.y;
	while (i < fractal->iterations_definition)
	{
		z = absolute_complex(z);
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, fractal->colors1, fractal->colors2,
					fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractal->img, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (y++ < HEIGHT)
	{
		x = -1;
		while (x++ < WIDTH)
		{
			if (!ft_strncmp(fractal->name, "mandelbrot", 10))
			{
				handle_pixel(x, y, fractal);
			}
			else if (!ft_strncmp(fractal->name, "julia", 5))
			{
				handle_pixel(x, y, fractal);
			}
			else if (!ft_strncmp(fractal->name, "burningship", 10))
			{
				handle_burning_ship_pixel(x, y, fractal);
			}
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img_ptr, 0,
		0);
}
