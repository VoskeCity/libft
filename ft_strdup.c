/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:34:36 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/05 20:49:00 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1);
	if (!(ptr = (char *)malloc(i * sizeof(char) + 1)))
		return (0);
	i = ft_strlcpy(ptr, s1, i + 1);
	return (ptr);
}
