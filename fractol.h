/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:07:42 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/11 16:39:47 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <unistd.h>

# define WINX 500
# define WINY 500
# define MAXCOLOR 16777215

typedef struct		s_img
{
	int				end;
	int				bpp;
	int				linesize;
	char			*data;
	void			*image;
}					t_img;

typedef struct		s_grid
{
	double			max_x;
	double			max_y;
	void			*mlx;
	void			*win;
	struct s_img	*img;
}					t_grid;

#endif
