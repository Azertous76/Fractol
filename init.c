/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:08:17 by abailleu          #+#    #+#             */
/*   Updated: 2023/10/09 15:08:19 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	malloc_error(void)
{
	perror("probleme avec malloc");
	exit(EXIT_FAILURE);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal ->mlx == NULL)
		malloc_error();
	fractal->win = mlx_new_window(fractal->mlx,
						WIDTH, HEIGHT, fractal->name);
	if (fractal->win == NULL)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	
	fractal->img.img_ptr = mlx_new_image(fractal->mlx,
						WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	//fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr,
	//						&fractal->img.bbp,
	//						&fractal->img.line_len,
	//						&fractal->img.endian);
	for (int i=200; i < 400;i++)
	{
		mlx_pixel_put(fractal->mlx, fractal->win, i, 100, 0xFFFFFF);
		for (int j=200; j < 400 && i == 400; j++)
		{
			mlx_pixel_put(fractal->mlx, fractal->win, i, 100, 0xFFFFFF);
		}
	}
	
}
