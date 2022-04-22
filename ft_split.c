/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:23:04 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 15:21:15 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_getnext(char *s, char c);
static size_t	ft_getrows(char *s, char c);
static size_t	ft_rowlen(char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**mat;
	char	*ptr;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	ptr = (char *)s;
	mat = (char **)malloc((sizeof(char *) * ft_getrows(ptr, c)) + 1);
	if (!s || !mat)
		return (0);
	while (*ptr)
	{
		ptr = ft_getnext(ptr, c);
		mat[j] = (char *)malloc(ft_rowlen(ptr, c) + 1);
		if (*ptr)
		{
			while (*ptr && *ptr != c)
				mat[j][k++] = *(ptr++);
			mat[j++][k] = '\0';
			k = 0;
		}
	}
	mat[j] = 0;
	return (mat);
}

static	char	*ft_getnext(char *s, char c)
{
	size_t	i;

	i = 0;
	if (*s != c)
		return (s);
	while (s[i] == c)
		i++;
	return (s + i);
}

static	size_t	ft_getrows(char *ptr, char c)
{
	size_t	k;

	k = 1;
	if (*ptr == c)
		k = k - 1;
	while (*ptr)
	{
		if (*ptr == c)
		{
			ptr = ft_getnext(ptr, c);
			if (*ptr)
				k++;
		}
		ptr++;
	}
	return (k);
}

static	size_t	ft_rowlen(char *s, char c)
{
	size_t	k;

	k = 0;
	while (s[k] && s[k++] != c)
		;
	if (k)
		return (k - 1);
	return (k);
}
