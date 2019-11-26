/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:07:42 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:42:21 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>
# include <pthread.h>

# define WINX 500
# define WINY 500
# define MAXCOLOR 16777215
# define ZOOM 1.5

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
	int				type;
	int				color;
    int             px;
    int             py;
	int				p;
	int				p_max;
	double			wx;
	double			wy;
    double          fn;
    double          fi;
    double          tmp;
}                   t_frac;

typedef struct		s_pos
{
	double			zoom;
    double          fx;
    double          fy;
	int				mouse_x;
	int				mouse_y;
}					t_pos;

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
	t_pos			*pos;
}					t_wndw;

/*
**		fractol.c
*/

void		img_pixel_put(t_img *img, int x, int y, int color);
t_img		*new_im(t_wndw *wndw);
t_wndw		*initialize_wndw(char **av);
int			get_type(char **av);
int			main();

/*
**		key_hooks.c
*/

void		reset_pos(t_pos *pos, t_frac *frac);
void		zoom(int in, t_pos *pos);
int			hook_key(int key, t_wndw *wndw);
int			hook_mouse(int button, int x, int y, t_wndw *wndw);

/*
**		frac_math.c
*/

void		view_mandelbrot(t_frac *frac, t_wndw *wndw);
void		view_julia(t_frac *frac, t_wndw *wndw);
void		view_burningship(t_frac *frac, t_wndw *wndw);

/*
**		misc
*/

void		load_fractol(t_wndw *wndw);
void		img_pixel_put(t_img *img, int x, int y, int color);

#endif
