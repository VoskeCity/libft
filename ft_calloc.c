/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:58:24 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/24 15:08:23 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		*ptr;
	size_t	i;

	i = 0;
	ptr = (int *)malloc(count * size);
	if (!ptr || (count == SIZE_MAX && size == SIZE_MAX))
		return (0);
	while (i < count)
		ptr[i++] = 0;
	return ((void *)ptr);
}
