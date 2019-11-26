/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:05:50 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 20:19:20 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	reset_pos(t_pos *pos, t_frac *frac)
{
	pos->zoom = WINY / 4;
	pos->mouse_x = 0;
	pos->mouse_y = 0;
	pos->fx = -2.0;
	pos->fy = -2.0;
	frac->p_max = 30;
}

void	change_color(t_frac *frac, int rgb)
{
	int	red;
	int grn;
	int blu;

	red = frac->color >> 16;
	grn = frac->color >> 8;
	blu = frac->color;
	if (rgb == 12 || rgb == 0)
		frac->color += (rgb == 12) ? 0x110000 : -0x110000;
	if (rgb == 13 || rgb == 1)
		frac->color += (rgb == 13) ? 0x001100 : -0x001100;
	if (rgb == 14 || rgb == 2)
		frac->color += (rgb == 14) ? 0x000011 : -0x000011;

	// if (rgb == 12 || rgb == 0)
	// 	red += (rgb == 12) ? 0x11 : -0x11;
	// if (rgb == 13 || rgb == 1)
	// 	grn += (rgb == 13) ? 0x11 : -0x11;
	// if (rgb == 14 || rgb == 2)
	// 	blu += (rgb == 14) ? 0x11 : -0x11;
	
	// frac->color = ((red << 16) | (grn << 8) | blu);


	// if (rgb == 12)
	// 	frac->color += 1048576;
	// else if (rgb == 13)
	// 	frac->color += 4096;
	// else if (rgb == 14)
	// 	frac->color += 16;
	// else if (rgb == 0)
	// 	frac->color -= 1048576;
	// else if (rgb == 1)
	// 	frac->color -= 4096;
	// else if (rgb == 2)
	// 	frac->color -= 16;
	ft_printf("%x\n", frac->color);
}

void		zoom(int in, t_pos *pos)
{
	if (in)
	{
		pos->fx = (pos->mouse_x / pos->zoom + pos->fx) - (pos->mouse_x / (pos->zoom * ZOOM));
		pos->fy = (pos->mouse_y / pos->zoom + pos->fy) - (pos->mouse_y / (pos->zoom * ZOOM));
		pos->zoom *= ZOOM;
	}
	else
	{
		pos->fx = (pos->mouse_x / pos->zoom + pos->fx) - (pos->mouse_x / (pos->zoom / ZOOM));
		pos->fy = (pos->mouse_y / pos->zoom + pos->fy) - (pos->mouse_y / (pos->zoom / ZOOM));
		pos->zoom /= ZOOM;
	}
}

int			hook_key(int key, t_wndw *wndw)
{
	ft_putnbr(key);
	ft_putchar(' ');
	if (key == 24 || (key == 27 && wndw->frac->p_max > 5))
		wndw->frac->p_max += (key == 24) ? 5 : -5;
	else if (key == 30 || (key == 33 && wndw->frac->p_max > 1))
		wndw->frac->p_max += (key == 30) ? 1 : -1;
	else if (key == 15 || key == 48)
	{
		reset_pos(wndw->pos, wndw->frac);
		if (key == 48)
			wndw->frac->type += wndw->frac->type != 3 ? 1 : -2;
	}
	if ((key >= 12 && key <= 14) || (key >= 0 && key <= 2))
		change_color(wndw->frac, key);
	else if (key == 53)
		exit(1);
	load_fractol(wndw);
	return (0);
}

int			hook_mouse(int button, int x, int y, t_wndw *wndw)
{
	ft_printf("%d@x%dy%d ", button, x, y);
	wndw->pos->mouse_x = x;
	wndw->pos->mouse_y = y;
	if (button == 4 || button == 1 || button == 5 || button == 2)
		zoom (button == 4 || button == 1 ? 0 : 1, wndw->pos);
	load_fractol(wndw);
	return (0);
}
