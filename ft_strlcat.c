/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:24:22 by aeloyan           #+#    #+#             */
/*   Updated: 2022/03/30 17:20:07 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	lendst;

	lendst = ft_strlen(dst);
	if (lendst > dstsize || dstsize == 0)
		return (dstsize + ft_strlen(src));
	return (lendst + ft_strlcpy(dst + lendst, src, dstsize - lendst));
}
