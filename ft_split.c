/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:23:04 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/09 20:30:47 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_getnext(char *s, char c);
static	size_t	ft_getrows(const char *s, char c);
static	size_t	ft_rowlen(char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**mat;
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	i = ft_getrows(s, c);
	mat = (char **)malloc(ft_strlen(s) + 1);
	if (!mat)
		return (0);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			ptr = ft_getnext(ptr, c);
		mat[j] = (char *)malloc(ft_rowlen(ptr, c) + 1);
		while (*ptr && *ptr != c)
			mat[j][k++] = *ptr++;
		mat[j][k] = '\0';
		k = 0;
		j++;
	}
	mat[j] = (void *)0;
	return (mat);
}

static	size_t	ft_getrows(const char *s, char c)
{
	char	*ptr;
	size_t	k;

	ptr = (char *)s;
	k = 1;
	while (*ptr)
	{
		if (*ptr == c)
			if (ptr != ft_getnext(ptr, c))
			{
			ptr = ft_getnext(ptr, c);
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
	return (k);
}

static	char	*ft_getnext(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	if (s + i != '\0')
		return (s + i);
	return (s);
}
