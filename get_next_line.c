/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:52:35 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/19 18:07:16 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	isnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	else if (i == 0)
		return (i);
	else
		return (-1);
}

char	*fillbuffer(int fd)
{
	char	*buffer;
	int		result;

	buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	result = read(fd, buffer, BUFFER_SIZE);
	if (result == -1 || result == 0)
		return (ft_calloc(1, 1));
	return (buffer);
}

char	*endsave(char *str, int fd)
{
	char	*buff;

	if (!str)
	{
		str = fillbuffer(fd);
		if (!str)
			return (NULL);
	}
	while (isnl(str) != -1)
	{
		buff = fillbuffer(fd);
		if (!buff)
			break ;
		ft_strjoin(str, buff);
	}
	
	return (ft_strjoin(str, buff));
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = endsave(save, fd);
	line = ft_substr(save, 0, ft_strchr(save, '\n');
	save = ft_substr(save, ft_strchr(save, '\n'), ft_strlen(save) - ft_strchr(save, '\n'));
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test", O_RDONLY);
	printf("fichier: %d", fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
*/
