/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:48:51 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 16:58:25 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_seq
{
	int				points[3][2];
	int				min;
	int				max;
	char			letter;
	struct s_seq	*next;
}					t_seq;
typedef struct		s_read
{
	char			buffer[22];
	char			lastbuffer[22];
	int				bound;
	t_seq			*head;
	t_seq			*reader;
	int				tetricount;
}					t_read;
t_seq				*ft_seqnew(char letter);
void				ft_what_tet(t_seq *reader, char *buffer);
int					ft_process_input(int fd, t_seq **tlist);
int					check_tetrim(char *buffer, int bound);
int					ft_solve(t_seq *t, int tetricount);
int					ft_min_max(int which_one, int x, int y, int z);
void				ft_seqdel(t_seq **lst);
#endif
