/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:22:54 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 17:21:14 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_valid_tet(char *buffer, int bound)
{
	int		i;
	int		xcount;
	int		ocount;

	i = -1;
	xcount = 0;
	ocount = 0;
	if (!(buffer[4] == '\n' && buffer[9] == '\n' && buffer[14] == '\n' &&
				buffer[19] == '\n'))
		return (0);
	while (++i < bound)
	{
		if (buffer[i] == '#')
			xcount++;
		else if (buffer[i] == '.')
			ocount++;
	}
	if (xcount != 4 || ocount != 12)
		return (0);
	return (check_tetrim(buffer, bound));
}

int			ft_process_input(int fd, t_seq **tlist)
{
	t_read	tread;
	char	current_letter;

	tread.tetricount = 0;
	current_letter = 'A';
	tread.head = ft_seqnew(current_letter);
	tread.reader = tread.head;
	*tlist = tread.head;
	while ((tread.bound = read(fd, tread.buffer, 21)) > 0)
	{
		tread.tetricount++;
		tread.buffer[tread.bound] = '\0';
		ft_strcpy(tread.lastbuffer, tread.buffer);
		if (ft_valid_tet(tread.buffer, tread.bound) && tread.tetricount <= 26)
		{
			ft_what_tet(tread.reader, tread.buffer);
			current_letter++;
			tread.reader->next = ft_seqnew(current_letter);
			tread.reader = tread.reader->next;
		}
		else
			return (0);
	}
	return ((tread.lastbuffer[20] != '\n') ? tread.tetricount : 0);
}
