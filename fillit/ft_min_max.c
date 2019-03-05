/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:15:48 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 15:05:24 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_max(int x, int y, int z)
{
	if (x >= y)
	{
		if (x >= z)
			return (x);
		return (z);
	}
	else if (y >= z)
		return (y);
	return (z);
}

static int		ft_min(int x, int y, int z)
{
	if (x <= y)
	{
		if (x <= z)
			return (x);
		return (z);
	}
	else if (y <= z)
		return (y);
	return (z);
}

int				ft_min_max(int which_one, int x, int y, int z)
{
	if (which_one == 1)
		return (ft_min(x, y, z));
	else
		return (ft_max(x, y, z));
}
