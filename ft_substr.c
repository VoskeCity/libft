/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:44:33 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/15 19:52:33 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s || start < 0)
		return (0);
	if (start > (unsigned int)ft_strlen(s) - (unsigned int)len)
		return (0);
	if (!(ptr = (char *)malloc(len * sizeof(char) + 1)))
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		ft_strlcpy(ptr, "", 1);
		return (ptr);
	}
	ptr = ft_strncpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}
