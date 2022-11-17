/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:13:52 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/17 13:49:07 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int res1, int res2)
{
	int		i;
	int		x;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (res1 == 0)
		res1 = ft_strlen(s1);
	str = (char *) malloc((res1 + res2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[x])
		str[i++] = s1[x++];
	x = 0;
	while (res2-- > 0)
		str[i++] = s2[x++];
	str[i] = '\0';
	free(s1);
	free(s2);
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
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*strcln(char *str)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc((isnl(str) + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	while (str[i] != '\n')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i++] = '\n';
	str2[i++] = '\0';
	return (str2);
}
