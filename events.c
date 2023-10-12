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

int close_handler(t_fractal *fractal)
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
	else if(keysym == XK_Left)
	{
		fractal->shift_x -= (0.5 * fractal->zoom);
	}
	else if(keysym == XK_Right)
	{
		fractal->shift_x += (0.5 * fractal->zoom);
	}
	else if(keysym == XK_Up)
	{
		fractal->shift_y += (0.5 * fractal->zoom);
	}
	else if(keysym == XK_Down)
	{
	fractal->shift_y -= (0.5 * fractal->zoom);
	}
	else if(keysym == XK_KP_Add)
	{
		fractal->iterations_definition += 10;
	}
	else if(keysym ==  XK_KP_Subtract)
	{
		fractal->iterations_definition -= 10;
	}
	fractal_render(fractal);
}

int mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if(button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
}

/*int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = map(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = map(y, 2, -2, HEIGHT) * fractal->zoom + fractal->shift_y;
		fractal_render(fractal);
	}
}*/
