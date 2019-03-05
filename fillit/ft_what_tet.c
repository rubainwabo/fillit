/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_tet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:08:21 by krutten           #+#    #+#             */
/*   Updated: 2018/12/10 16:58:05 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_what_tet(t_seq *reader, char *buffer)
{
	int		i;
	int		p;
	int		x;
	int		vert;

	i = 0;
	p = 0;
	x = 0;
	vert = 0;
	while (buffer[i] != '#')
		i++;
	while (i + (++x) < 20)
	{
		if ((i + x) % 5 == 4)
			vert++;
		if (buffer[i + x] && buffer[i + x] == '#')
		{
			reader->points[p][0] = x - (vert * 5);
			reader->points[p++][1] = vert;
			reader->min = ft_min_max(1, reader->points[0][0],
					reader->points[1][0], reader->points[2][0]);
			reader->max = ft_min_max(2, reader->points[0][0],
					reader->points[1][0], reader->points[2][0]);
		}
	}
}
