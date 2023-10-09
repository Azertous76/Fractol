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
#include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Faut rentrer sois \n\t\"./fractol mandelbrot\" ou \n\t\"./fractol julia <value_1> <value 2>\"\n   le sang sinon ca marche pas"

#define WIDTH  800
#define HEIGHT 800

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int	bbp;
	int	endian;
	int	line_len;
}			t_img;


typedef struct s_fractal
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;

}			t_fractal;

int	ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

void	fractal_init(t_fractal *fractal);
#endif
