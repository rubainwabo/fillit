/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krutten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:50:48 by krutten           #+#    #+#             */
/*   Updated: 2018/12/10 17:04:59 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_try(t_seq *t, char *grid, int coord, int size)
{
	int		a;
	int		b;
	int		c;

	a = coord + t->points[0][0] + (t->points[0][1] * size);
	b = coord + t->points[1][0] + (t->points[1][1] * size);
	c = coord + t->points[2][0] + (t->points[2][1] * size);
	if (grid[c] && (coord % size + t->min >= 0) &&
			(coord % size + t->max < size))
	{
		if (grid[a] == '.' && grid[b] == '.' && grid[c] == '.')
		{
			grid[coord] = t->letter;
			grid[a] = t->letter;
			grid[b] = t->letter;
			grid[c] = t->letter;
			return (1);
		}
	}
	return (0);
}

static char		*ft_alloc_grid(int size)
{
	char	*grid;
	int		i;

	if (!(grid = (char *)malloc((size * size) + 1)))
		return (0);
	i = 0;
	while (i < size * size)
		grid[i++] = '.';
	grid[i] = '\0';
	return (grid);
}

static void		ft_wipe(t_seq *t, char *grid, int coord, int size)
{
	grid[coord] = '.';
	grid[coord + t->points[0][0] + (t->points[0][1] * size)] = '.';
	grid[coord + t->points[1][0] + (t->points[1][1] * size)] = '.';
	grid[coord + t->points[2][0] + (t->points[2][1] * size)] = '.';
}

static int		ft_recurse(t_seq *t, char *grid, int coord, int size)
{
	if (!(t->next))
		return (1);
	while (grid[coord] != '.' && coord < size * size)
		coord++;
	while (coord < size * size)
	{
		if (grid[coord] == '.' && ft_try(t, grid, coord, size))
		{
			if (ft_recurse(t->next, grid, 0, size))
				return (1);
		}
		if (grid[coord] == t->letter)
			ft_wipe(t, grid, coord, size);
		coord++;
	}
	return (0);
}

int				ft_solve(t_seq *t, int tetricount)
{
	int		size;
	char	*grid;
	int		print;

	size = ft_sqrt(tetricount * 4);
	if (!(grid = ft_alloc_grid(size)))
		return (0);
	while (!(ft_recurse(t, grid, 0, size)))
	{
		size++;
		free(grid);
		if (!(grid = ft_alloc_grid(size)))
			return (0);
	}
	print = 0;
	while (print <= size * size)
	{
		if (print != 0 && print % size == 0)
			ft_putchar('\n');
		if (print != size * size)
			ft_putchar(grid[print]);
		print++;
	}
	return (1);
}
