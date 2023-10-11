/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abailleu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:55:18 by abailleu          #+#    #+#             */
/*   Updated: 2023/10/09 13:55:22 by abailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Faut rentrer sois \n\t\"./fractol mandelbrot\" ou \n\t\"./fractol julia <value_1> <value 2>\"\n   le sang sinon ca marche pas"

#define WIDTH  800
#define HEIGHT 800

#define BLACK       0x000000  
#define WHITE       0xFFFFFF  
#define RED         0xFF0000  
#define GREEN       0x00FF00  
#define BLUE        0x0000FF  


#define MAGENTA_BURST   0xFF00FF  
#define LIME_SHOCK      0xCCFF00
#define NEON_ORANGE     0xFF6600
#define PSYCHEDELIC_PURPLE 0x660066
#define AQUA_DREAM      0x33CCCC
#define HOT_PINK        0xFF66B2
#define ELECTRIC_BLUE   0x0066FF
#define LAVA_RED        0xFF3300

typedef struct s_complex
{
	double x;
	double y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int	bpp;
	int	endian;
	int	line_len;
}			t_img;


typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_value;
	int	iterations_definition;

}			t_fractal;

int	ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

static	void	malloc_error(void);
void	fractal_init(t_fractal *fractal);
static void event_init(t_fractal *fractal);
void	data_init(t_fractal *fractal);

int key_handle(int keysym, t_fractal *fractal);
void close_handler(t_fractal *fractal);

static void my_pixel_put(int x, int y, t_img *img, int color);
static void	handle_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);

double map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
#endif
