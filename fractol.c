/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:23:22 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/23 19:41:07 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	reset_pos(t_pos *pos, t_frac *frac);

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		*(int*)(img->data + ((x + y * WINX) * img->bpp)) = color;
}

void		view_mandlebrot(t_frac *frac, t_wndw *wndw)
{
	mlx_clear_window(wndw->mlx, wndw->win);
	frac->px = 0;
	frac->py = 0;

	while (frac->px < WINX && frac->py < WINY)
	{
		frac->wx = 0;
		frac->wy = 0;
		frac->p = 0;
		frac->fn = frac->px / wndw->pos->zoom + wndw->pos->fx;
		frac->fi = frac->py / wndw->pos->zoom + wndw->pos->fy;
		// frac->fn = frac->px / ((WINX / wndw->pos->zoom) - frac->fx) - (wndw->pos->zoom / 3 * 2);
		// frac->fi = frac->py / ((WINY / wndw->pos->zoom) - frac->fy) - (wndw->pos->zoom / 2);

		while (frac->wx * frac->wx + frac->wy * frac->wy < 4 && frac->p < frac->p_max)
		{
			frac->tmp = frac->wx * frac->wx - frac->wy * frac->wy + frac->fn;
			frac->wy = 2 * frac->wx * frac->wy + frac->fi;
			frac->wx = frac->tmp;
			frac->p++;
		}

		if (frac->p == frac->p_max)
			img_pixel_put(wndw->img, frac->px, frac->py, 0xFFFFFF);
		else
			img_pixel_put(wndw->img, frac->px, frac->py, 0x088000 - frac->p * frac->p_max);
		if (++frac->px == WINX)
		{
			frac->px = 0;
			frac->py++;
		}
	}
	mlx_put_image_to_window(wndw->mlx, wndw->win, wndw->img->image, 0, 0);
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
	else if (key == 15)
		reset_pos(wndw->pos, wndw->frac);
	else if (key == 53)
		exit(1);
	ft_printf("%d\n", wndw->frac->p_max);
	view_mandlebrot(wndw->frac, wndw);
	return (0);
}

int			hook_mouse(int button, int x, int y, t_wndw *wndw)
{
	ft_printf("%d@x%dy%d ", button, x, y);
	wndw->pos->mouse_x = x;
	wndw->pos->mouse_y = y;
	if (button == 4 || button == 1 || button == 5 || button == 2)
		zoom (button == 4 || button == 1 ? 0 : 1, wndw->pos);
	view_mandlebrot(wndw->frac, wndw);
	return (0);
}

t_img	*new_im(t_wndw *wndw)
{
	t_img *image;

	if (!(image = ft_memalloc(sizeof(t_img))))
		return (NULL);
	if (!(image->image = mlx_new_image(wndw->mlx, WINX, WINY)))
		return (NULL);
	image->data = mlx_get_data_addr(image->image, &image->bpp, &image->linesize,
		&image->end);
	image->bpp /= 8;
	return (image);
}

void	reset_pos(t_pos *pos, t_frac *frac)
{
	pos->zoom = WINY / 4;
	pos->mouse_x = 0;
	pos->mouse_y = 0;
	pos->fx = -2.0f;
	pos->fy = -2.0f;
	frac->p_max = 30;
}

t_wndw		*initialize_wndw()
{
	t_wndw	*wndw;

	if (!(wndw = ft_memalloc(sizeof(t_wndw))))
		return (NULL);
	if (!(wndw->mlx = mlx_init()))
		return (NULL);
	if (!(wndw->win = mlx_new_window(wndw->mlx, WINX, WINY, "fractol")))
		return (NULL);
	if (!(wndw->frac = ft_memalloc(sizeof(t_frac))))
		return (NULL);
	if (!(wndw->pos = ft_memalloc(sizeof(t_pos))))
		return (NULL);
	reset_pos(wndw->pos, wndw->frac);
	wndw->img = new_im(wndw);
	mlx_key_hook(wndw->win, hook_key, wndw);
	mlx_mouse_hook(wndw->win, hook_mouse, wndw);
	return (wndw);
}

int			main()
{
	t_wndw	*wndw;

	wndw = initialize_wndw();
	
	view_mandlebrot(wndw->frac, wndw);

	// mlx_put_image_to_window(wndw->mlx, wndw->win, wndw->img->image, 0, 0);
	mlx_loop(wndw->mlx);
	return (0);
}
