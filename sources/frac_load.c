/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:14:42 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/30 22:58:01 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		*(int*)(img->data + ((x + y * WINX) * img->bpp)) = color;
}

void		load_fractol(t_wndw *wndw)
{
	wndw->frac->px = 0;
	wndw->frac->py = 0;
	while (wndw->frac->px < WINX && wndw->frac->py < WINY)
	{
		if (wndw->frac->type == 1)
			view_mandelbrot(wndw->frac, wndw);
		else if (wndw->frac->type == 2)
			view_julia(wndw->frac, wndw);
		else if (wndw->frac->type == 3)
			view_burningship(wndw->frac, wndw);
		if (++wndw->frac->px == WINX)
		{
			wndw->frac->px = 0;
			wndw->frac->py++;
		}
	}
	mlx_clear_window(wndw->mlx, wndw->win);
	mlx_put_image_to_window(wndw->mlx, wndw->win, wndw->img->image, 0, 0);
}
