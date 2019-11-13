/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:23:22 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/13 15:50:08 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		*(int*)(img->data + ((x + y * WINX) * img->bpp)) = color;
}

int			hook_key(int key, t_wndw *wndw)
{
	ft_putnbr(key);
	ft_putchar(' ');
	if (key == 53)
		exit(1);
	if (wndw->frac->tmp)
		wndw->frac->tmp = 0;
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
	wndw->img = new_im(wndw);
	mlx_key_hook(wndw->win, hook_key, wndw);
	return (wndw);
}

void		view_mandlebrot(t_frac *frac, t_wndw *wndw)
{
	frac->px = 0;
	frac->py = 0;
	frac->p_max = 500;

	while (frac->px < WINX && frac->py < WINY)
	{
		frac->fx = -2.0f;
		frac->fy = -2.0f;
		frac->wx = 0;
		frac->wy = 0;
		frac->p = 0;
		frac->fn = frac->px / (500 + frac->fx);
		frac->fi = frac->py / (500 + frac->fy);

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
			img_pixel_put(wndw->img, frac->px, frac->py, (0x008080 * frac->p));

		frac->px++;
		if (frac->px == WINX)
		{
			frac->px = 0;
			frac->py++;
		}
	}
	mlx_put_image_to_window(wndw->mlx, wndw->win, wndw->img->image, 0, 0);
}

int			main()
{
	t_wndw	*wndw;

	wndw = initialize_wndw();
	
	view_mandlebrot(wndw->frac, wndw);

	// img_pixel_put(wndw->img, 0, 0, 0xFFFFFF);
	// mlx_put_image_to_window(wndw->mlx, wndw->win, wndw->img->image, 0, 0);
	mlx_loop(wndw->mlx);
	return (0);
}
