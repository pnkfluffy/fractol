/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:23:22 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/11 16:39:53 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WINX && y >= 0 && y < WINY)
		*(int*)(img->data + ((x + y * WINX) * img->bpp)) = color;
}

int			hook_key(int key, t_grid *grid)
{
	ft_putnbr(key);
	ft_putchar(' ');
	if (key == 53)
		exit(1);
	grid->max_x++;
	return (0);
}

t_img	*new_im(t_grid *grid)
{
	t_img *image;

	if (!(image = ft_memalloc(sizeof(t_img))))
		return (NULL);
	if (!(image->image = mlx_new_image(grid->mlx, WINX, WINY)))
		return (NULL);
	image->data = mlx_get_data_addr(image->image, &image->bpp, &image->linesize,
		&image->end);
	image->bpp /= 8;
	return (image);
}

t_grid		*initialize_grid()
{
	t_grid	*grid;

	if (!(grid = ft_memalloc(sizeof(t_grid))))
		return (NULL);
	if (!(grid->mlx = mlx_init()))
		return (0);
	if (!(grid->win = mlx_new_window(grid->mlx, WINX, WINY, "fractol")))
		return (0);
	grid->max_x = WINX;
	grid->max_y = WINY;
	grid->img = new_im(grid);
	mlx_key_hook(grid->win, hook_key, grid);
	return (grid);
}

int			main()
{
	t_grid	*grid;

	grid = initialize_grid();
	img_pixel_put(grid->img, 250, 250, 0xFFFFFF);
	mlx_put_image_to_window(grid->mlx, grid->win, grid->img->image, 0, 0);
	mlx_loop(grid->mlx);
	return (0);
}
