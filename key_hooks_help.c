/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:16:40 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/27 17:24:55 by jfelty           ###   ########.fr       */
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
	if (rgb == 12 || rgb == 0)
		frac->color += (rgb == 12) ? 0x110000 : -0x110000;
	else if (rgb == 13 || rgb == 1)
		frac->color += (rgb == 13) ? 0x001100 : -0x001100;
	else if (rgb == 14 || rgb == 2)
		frac->color += (rgb == 14) ? 0x000011 : -0x000011;
	else if (rgb == 8)
		frac->color = 0x000000;
	ft_printf("%x\n", frac->color);
}

/*
**	BADASS COLORSETS
**	790fff
**	ee22ff
*/

void	zoom(int in, t_pos *pos)
{
	if (in)
	{
		pos->fx = (pos->mouse_x / pos->zoom + pos->fx) - \
		(pos->mouse_x / (pos->zoom * ZOOM));
		pos->fy = (pos->mouse_y / pos->zoom + pos->fy) - \
		(pos->mouse_y / (pos->zoom * ZOOM));
		pos->zoom *= ZOOM;
	}
	else
	{
		pos->fx = (pos->mouse_x / pos->zoom + pos->fx) - \
		(pos->mouse_x / (pos->zoom / ZOOM));
		pos->fy = (pos->mouse_y / pos->zoom + pos->fy) - \
		(pos->mouse_y / (pos->zoom / ZOOM));
		pos->zoom /= ZOOM;
	}
}
