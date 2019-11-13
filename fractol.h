/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:07:42 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/13 15:09:06 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>

# define WINX 1000
# define WINY 1000
# define MAXCOLOR 16777215

/*
**	px = pixel x, x on the screen
**	p = permutations
**	wx = windowx (only double for math) 
**	fx = function x
**	fn = funtion num
**	fi = funtion imaginary num
*/

typedef struct      s_frac
{
    int             px;
    int             py;
	int				p;
	int				p_max;
	double			wx;
	double			wy;
    double          fx;
    double          fy;
    double          fn;
    double          fi;
    double          tmp;
}                   t_frac;

typedef struct		s_img
{
	int				end;
	int				bpp;
	int				linesize;
	char			*data;
	void			*image;
}					t_img;
typedef struct		s_wndw
{
	void			*mlx;
	void			*win;
	t_img			*img;
    t_frac			*frac;
}					t_wndw;

#endif

// fx = x1;
// fy = y1;
// fn = c.n;
// fi = c.i;
// wx = z.n;
// wy = z.i;