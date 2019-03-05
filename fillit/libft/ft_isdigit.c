/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 10:58:28 by rkamegne          #+#    #+#             */
/*   Updated: 2018/10/09 11:00:10 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
