/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:52:05 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/25 17:45:55 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\v' || c == '\n' || c == '\r' || c == '\f' \
		|| c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while (ft_isspace(str[i]))
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
	}
	return (nbr * sign);
}
