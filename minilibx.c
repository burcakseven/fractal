/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buseven <buseven@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:00:02 by ksancako          #+#    #+#             */
/*   Updated: 2022/11/22 17:21:13 by buseven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	create_image(t_vars *s_vars, t_imgdata *s_img)
{
	s_img->img = mlx_new_image(s_vars->mlx_ptr, WIDTH, HEIGHT);
	s_img->addr = mlx_get_data_addr(s_img->img,
			&s_img->bits_per_pixel, &s_img->line_length, &s_img->endian);
}

void	my_mlx_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
