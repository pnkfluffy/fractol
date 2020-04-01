/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnxtnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnkfluffy <pnkfluffy@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 05:20:11 by jfelty            #+#    #+#             */
/*   Updated: 2020/03/20 22:11:04 by pnkfluffy        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Takes a string and returns the next "convertable" number as seperated by
**	delimiter 'c' or spaces.
*/

int		ft_getnxtnbr(char *str, char c)
{
	int pos;
	int result;

	pos = 1;
	result = 0;
	while (*str != c && !ft_isspace(*str) && *str)
	{
		if (*str == '-')
			pos *= -1;
		if (*str == '+' || *str == '-')
			str++;
		while ((*str >= '0') && (*str <= '9'))
		{
			result = (result * 10) + (*str - '0');
			str++;
		}
	}
	return (result * pos);
}
