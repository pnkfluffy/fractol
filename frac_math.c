/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:04:37 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 20:57:36 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void		view_mandelbrot(t_frac *frac, t_wndw *wndw)
{
	frac->wx = 0;
	frac->wy = 0;
	frac->p = 0;
	frac->fn = frac->px / wndw->pos->zoom + wndw->pos->fx;
	frac->fi = frac->py / wndw->pos->zoom + wndw->pos->fy;
	while (frac->wx * frac->wx + frac->wy * frac->wy < 4 && frac->p < frac->p_max)
	{
		frac->tmp = frac->wx * frac->wx - frac->wy * frac->wy + frac->fn;
		frac->wy = 2 * frac->wx * frac->wy + frac->fi;
		frac->wx = frac->tmp;
		++frac->p;
	}
	if (frac->p == frac->p_max)
		img_pixel_put(wndw->img, frac->px, frac->py, 0xFFFFFF);
	else
		img_pixel_put(wndw->img, frac->px, frac->py, frac->p * frac->color);
}

void		view_julia(t_frac *frac, t_wndw *wndw)
{
	frac->fn = 0.30;
	frac->fi = 0.01;
	frac->p = 0;
	frac->wx = frac->px / wndw->pos->zoom + wndw->pos->fx;
	frac->wy = frac->py / wndw->pos->zoom + wndw->pos->fy;
	while (frac->wx * frac->wx + frac->wy * frac->wy < 4 && frac->p < frac->p_max)
	{
		frac->tmp = frac->wx * frac->wx - frac->wy * frac->wy;
		frac->wy = 2 * frac->wx * frac->wy + frac->fi;
		frac->wx = frac->tmp + frac->fn;
		frac->p++;
	}
	if (frac->p == frac->p_max)
		img_pixel_put(wndw->img, frac->px, frac->py, 0xFFFFFF);
	else
		img_pixel_put(wndw->img, frac->px, frac->py, frac->p * frac->color);
		// img_pixel_put(wndw->img, frac->px, frac->py, 0x000088 - frac->p * frac->p_max);
}

void		view_burningship(t_frac *frac, t_wndw *wndw)
{
	frac->wx = 0;
	frac->wy = 0;
	frac->p = 0;
	frac->fn = frac->px / wndw->pos->zoom + wndw->pos->fx;
	frac->fi = frac->py / wndw->pos->zoom + wndw->pos->fy;
	while (frac->wx * frac->wx + frac->wy * frac->wy < 4 && frac->p < frac->p_max)
	{
		frac->tmp = frac->wx * frac->wx - frac->wy * frac->wy + frac->fn;
		frac->wy = ft_dblpower(2 * frac->wx * frac->wy, 2) + frac->fi;
		frac->wx = frac->tmp;
		++frac->p;
	}
	if (frac->p == frac->p_max)
		img_pixel_put(wndw->img, frac->px, frac->py, 0xFFFFFF);
	else
		img_pixel_put(wndw->img, frac->px, frac->py, frac->p * frac->color);
}

//790fff
//ee22ff