/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:28:56 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 17:57:38 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rm(char *ptr, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*prt;
	size_t	k;
	size_t	j;

	if (!s1)
		return (0);
	j = 0;
	k = ft_strlen(s1);
	ptr = (char *)malloc(k + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, k + 1);
	while (ft_rm(ptr, set))
		;
	while (ft_rm(ptr + ft_strlen(ptr) - 1, set))
		;
	prt = (char *)malloc(ft_strlen(ptr) + 1);
	if (prt == 0)
		return (0);
	ft_strlcpy(prt, ptr, ft_strlen(ptr) + 1);
	return (prt);
}

int	ft_rm(char *ptr, const char *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (ptr[0] == set[j])
		{
			ft_memmove((void *)(ptr), (void *)(ptr + 1), ft_strlen(ptr));
			return (1);
		}
		j++;
	}
	return (0);
}
