/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:28:50 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/19 18:16:11 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*str;

	if (s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1);
	x = ft_strlen((char *)s2);
	str = ft_calloc((i + x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	x = 0;
	while (s1 && s1[x])
		str[i++] = s1[x++];
	x = 0;
	while (s2[x])
		str[i++] = s2[x++];
	free((char *)s1);
	return (str);
}

void	*ft_calloc(unsigned int	size)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}