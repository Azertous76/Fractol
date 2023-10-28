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

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}

int	key_handle(int keysym, t_fractal *fractal)
{
	if (keysym == 65307)
		close_handler(fractal);
	else if (keysym == 65361)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 65363)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 65362)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 65364)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 97)
	{
		fractal->colors2 = HOT_PINK;
	}
	else if (keysym == 115)
	{
		fractal->colors1 = LIME_SHOCK;
		fractal->colors2 = LAVA_RED;
	}
	else if (keysym == 65451)
		fractal->iterations_definition += 10;
	else if (keysym == 65453)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}
