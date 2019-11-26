/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:14:18 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/25 17:45:59 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(long int nbr)
{
	int				len;
	unsigned int	unbr;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		unbr = -nbr;
		len++;
	}
	else
		unbr = nbr;
	while (unbr != 0)
	{
		unbr = unbr / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[len-- - 1] = '8';
			n = n / 10;
		}
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
