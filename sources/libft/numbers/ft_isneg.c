/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isneg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnkfluffy <pnkfluffy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:16:37 by jfelty            #+#    #+#             */
/*   Updated: 2020/03/20 22:25:01 by pnkfluffy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			ft_isneg(int64_t a)
{
	if (a < 0)
		return (1);
	return (0);
}
