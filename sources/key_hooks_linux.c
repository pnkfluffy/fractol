/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_linux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnkfluffy <pnkfluffy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:05:50 by jfelty            #+#    #+#             */
/*   Updated: 2020/03/25 09:49:42 by pnkfluffy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
	else if ((key >= 12 && key <= 14) || (key >= 0 && key <= 2) || key == 8)
		change_color(wndw->frac, key);
	else if (key == 46)
		wndw->frac->active_mouse = (wndw->frac->active_mouse == 1) ? 0 : 1;
	else if (key >= 123 && key <= 126)
		scroll(key, wndw->pos);
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
		zoom(button == 4 || button == 1 ? 0 : 1, wndw->pos);
	load_fractol(wndw);
	return (0);
}

int			hook_active_mouse(int x, int y, t_wndw *wndw)
{
	if (wndw->frac->type == 2 && wndw->frac->active_mouse == 1)
	{
		wndw->frac->fn = x * 2.5 / WINX;
		wndw->frac->fi = y * 2.5 / WINX;
		load_fractol(wndw);
	}
	return (0);
}
z