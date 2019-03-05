/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seqnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:49:06 by rkamegne          #+#    #+#             */
/*   Updated: 2018/12/10 14:29:11 by krutten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_seq	*ft_seqnew(char letter)
{
	t_seq	*list;

	if (!(list = (t_seq*)malloc(sizeof(*list))))
		return (NULL);
	list->letter = letter;
	list->next = NULL;
	return (list);
}
