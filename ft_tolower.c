/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:30:53 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/22 12:40:21 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int x)
{
	if (x >= 'A' && x <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c = c - 'A' + 'a';
	return (c);
}
