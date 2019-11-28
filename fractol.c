/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:23:22 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/27 17:26:27 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_img		*new_im(t_wndw *wndw)
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

int			get_type(char **av)
{
	if (!ft_strcmp(av[1], "mandelbrot"))
		return (1);
	else if (!ft_strcmp(av[1], "julia"))
		return (2);
	else if (!ft_strcmp(av[1], "burningship"))
		return (3);
	else
		return (0);
}

t_wndw		*initialize_wndw(char **av)
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
	wndw->frac->type = get_type(av);
	wndw->frac->color = 0x000000;
	wndw->frac->active_mouse = 0;
	wndw->img = new_im(wndw);
	mlx_hook(wndw->win, 6, 0, hook_active_mouse, wndw);
	mlx_key_hook(wndw->win, hook_key, wndw);
	mlx_mouse_hook(wndw->win, hook_mouse, wndw);
	return (wndw);
}

int			main(int ac, char **av)
{
	t_wndw	*wndw;

	if (ac < 2 || (!ft_strcmp(av[1], "mandelbrot") &&
	!ft_strcmp(av[1], "julia") && !ft_strcmp(av[1], "burningship")))
	{
		ft_printf("usage: ./fractol [fractolname]\n");
		ft_printf("\t[mandelbrot] [julia] [burningship]");
		return (0);
	}
	wndw = initialize_wndw(av);
	load_fractol(wndw);
	mlx_loop(wndw->mlx);
	return (0);
}
