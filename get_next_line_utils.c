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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	int				x;

	i = start;
	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) && ft_strlen(s) != 0)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) > start && len < start)
		len = len + 1 - 1;
	else if (len < start)
		len = start - len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < (len + start) && s[i])
		str[x++] = s[i++];
	str[x] = 0;
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
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
	str = (char *) malloc((i + x + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	x = 0;
	while (s1 && s1[x])
		str[i++] = s1[x++];
	x = 0;
	while (s2[x])
		str[i++] = s2[x++];
	str[i] = '\0';
	free((char *)s1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
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
