/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:24:09 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/03 15:39:42 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*dsts;
	char	*srcs;
	size_t	i;

	srcs = (char *)src;
	dsts = (char *)dst;
	i = 0;
	if (ft_abs((int)dst, (int)src) >= (int)n)
	{
		while (i < n)
		{
			dsts[i] = srcs[i];
			i++;
		}
	}
	return (dst);
}
