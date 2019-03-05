/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 22:14:54 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 13:41:04 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetrim(char *buffer, int bound)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < bound)
	{
		if (buffer[i] == '#')
		{
			if ((i + 1) % 5 < 4 && buffer[i + 1] == '#')
				count++;
			if ((i - 1) % 5 >= 0 && buffer[i - 1] == '#')
				count++;
			if (i < 15 && buffer[i + 5] == '#')
				count++;
			if (i >= 5 && buffer[i - 5] == '#')
				count++;
		}
		i++;
	}
	return ((count == 6 || count == 8));
}
