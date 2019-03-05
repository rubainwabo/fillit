/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seqdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 22:56:22 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 13:59:24 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_seqdel(t_seq **lst)
{
	t_seq	*tmp;

	tmp = *lst;
	if (lst && *lst)
	{
		while (tmp)
		{
			free(tmp);
			tmp = tmp->next;
		}
		*lst = NULL;
	}
}
