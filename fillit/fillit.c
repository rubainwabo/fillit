/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:59:44 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 17:06:09 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	t_seq	*tetrilist;
	int		tetricount;

	tetrilist = NULL;
	tetricount = 0;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (!(tetricount = ft_process_input(fd, &tetrilist)))
	{
		ft_seqdel(&tetrilist);
		ft_putendl("error");
		return (0);
	}
	ft_solve(tetrilist, tetricount);
	close(fd);
	return (0);
}
