/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:54:49 by aeloyan           #+#    #+#             */
/*   Updated: 2022/04/21 20:10:22 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	val;
	int		i;
	int		k;

	val = 0;
	i = 0;
	k = 0;
	while (s[i] == '\t' || s[i] == '\r' || s[i] == ' ' || s[i] == '\v'
		|| s[i] == '-' || s[i] == '+' || s[i] == '\f' || s[i] == '\n')
	{
		if (s[i] == ' ')
			k++;
		if ((s[i] == '+' && !ft_isdigit(s[i + 1])) || k > 1)
			return (0);
		i++;
	}
	if (s[i - 1] == '-')
		k = -1;
	while (ft_isdigit(s[i]))
	{	
		val = (val * 10) + s[i] - '0';
		if (val > INT_MAX && k != -1)
			return (-1);
		if (k == -1 && - val < INT_MIN)
			return (0);
		i++;
	}
	if (k == -1)
		return (-val);
	return (val);
}
