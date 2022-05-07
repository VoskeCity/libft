/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:06:10 by aeloyan           #+#    #+#             */
/*   Updated: 2022/05/07 13:58:18 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*getnext(char *ptrge, char chge);
static int	wordlen(char *ptrw, char chw);
static int	getrows(char *ptrg, char chg);

char	**ft_split(const char *str, char ch)
{
	char	**mat;
	char	*ptr;
	int		j;

	j = 0;
	if (!str)
		return (0);
	ptr = ft_strtrim(str, &ch);
	if (!ptr)
		return (0);
	mat = (char **)malloc(sizeof(char *) * (getrows(ptr, ch) + 1));
	if (!mat)
		return (0);
	while (*ptr)
	{
		mat[j] = ft_substr(ptr, 0, wordlen(ptr, ch));
		if (!mat[j])
		{
			while (j)
				free(mat[--j]);
			free(mat);
			return (0);
		}
		j++;
		ptr = getnext(ptr, ch);
	}
	mat[j] = NULL;
	return (mat);
}

static char	*getnext(char *ptrge, char chge)
{
	while (*ptrge && *ptrge != chge)
		ptrge++;
	while (*ptrge && *ptrge == chge)
		ptrge++;
	return (ptrge);
}

static int	wordlen(char *ptrw, char chw)
{
	int	i;

	i = 0;
	while (ptrw[i] && ptrw[i] != chw)
		i++;
	return (i);
}

static int	getrows(char *ptrg, char chg)
{
	int	i;

	i = 0;
	while (*ptrg)
	{
		ptrg = getnext(ptrg, chg);
		i++;
	}
	return (i);
}
