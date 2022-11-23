/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buseven <buseven@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:00:16 by ksancako          #+#    #+#             */
/*   Updated: 2022/11/22 17:09:12 by buseven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_hook(int keycode, int x, int y, t_vars *s_vars)
{
	if (keycode == 4)
	{
		s_vars->zoom -= 0.2;
		s_vars->zo_rate = pow(2, s_vars->zoom);
		design_image(s_vars, x, y);
	}
	if (keycode == 5)
	{
		s_vars->zoom += 0.2;
		s_vars->zo_rate = pow(2, s_vars->zoom);
		design_image(s_vars, x, y);
	}
	if (keycode == 1)
	{
		change_palette(s_vars, 0);
	}
	return (1);
}

void	change_palette(t_vars *s_vars, int setup)
{
	static int	paletset = 0;

	if (paletset % 8 == 0)
		s_vars->pallette = 123123;
	else if (paletset % 8 == 1)
		s_vars->pallette = 29000;
	else if (paletset % 8 == 2)
		s_vars->pallette = 602000;
	else if (paletset % 8 == 3)
		s_vars->pallette = 1120000;
	else if (paletset % 8 == 4)
		s_vars->pallette = 420000;
	else if (paletset % 8 == 5)
		s_vars->pallette = 965000;
	else if (paletset % 8 == 6)
		s_vars->pallette = 1320000;
	else if (paletset % 8 == 7)
		s_vars->pallette = 756321;
	paletset++;
	if (!setup)
		design_image(s_vars, s_vars->base.posx, s_vars->base.posy);
}
