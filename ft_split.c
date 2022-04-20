/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:23:04 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/20 15:33:56 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_getnext(char *s, char c);
static	size_t	ft_getrows(const char *s, char c);
//static	size_t	ft_rowlen(char *s, char c);

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
	mat = (char **)malloc(sizeof(char *) * i);
	if (!mat || !s)
		return (0);
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == c)
			ptr = ft_getnext(ptr, c);
		mat[j] = (char *)malloc(sizeof(char *));
		while (*ptr && *ptr != c)
			mat[j][k++] = *(ptr++);
		mat[j][k] = '\0';
		printf("%s\n", mat[j]);
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
		if (*ptr == c && ptr != ft_getnext(ptr, c))
		{
			ptr = ft_getnext(ptr, c);
			k++;
		}
		ptr++;
	}
	if (*s == c)
		k = k - 1;
	return (k);
}

//static	size_t	ft_rowlen(char *s, char c)
//{
//	size_t	k;
//
//	k = 0;
//	while (s[k] && s[k++] != c)
//		;
//	if (k)
//		return (k - 1);
//	return(k);
//}

static	char	*ft_getnext(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (s + i);
}
