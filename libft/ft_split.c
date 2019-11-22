/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipizarro <ipizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:10:34 by pmontese          #+#    #+#             */
/*   Updated: 2019/11/21 18:50:14 by ipizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *ptr;

	ptr = dest;
	while (n > 0 && *src != '\0')
	{
		if (*src)
			*dest = *src;
		else
			*dest = '\0';
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (ptr);
}

static size_t	ft_wordcount(char const *str, char delimiter)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] != delimiter)
			w += 1;
		while (str[i] != delimiter && str[i + 1])
			i += 1;
		i += 1;
	}
	return (w);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**list;

	if (s == NULL)
		return (NULL);
	list = (char**)malloc(sizeof(char*) * (ft_wordcount(s, c) + 1));
	if (!list)
		return (NULL);
	j = 0;
	while (*s != 0)
	{
		i = 0;
		while (s[i] != c && s[i] != 0)
			i++;
		if (i)
		{
			list[j++] = ft_strncpy((char*)malloc(i + 1), s, i);
			s = &s[i];
		}
		else
			s++;
	}
	list[j] = NULL;
	return (list);
}
