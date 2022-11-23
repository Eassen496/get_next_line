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

char	*lineclnr(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if (save[0] == '\0')
		return (NULL);
	ret = ft_calloc((isnl(str) + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	while (save[i] && save[i] != '\n')
	{
		ret[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		ret[i] = save[i];
		i++;
	}
	return (ret);
}

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

char	*saveclnr(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = isnl(str);
	if (i == -1)
	{
		free(str);
		return (NULL);
	}
	ret = ft_calloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		ret[j++] = save[i++];
	free(str);
	return (ret);
}

char	*loadbuffer(char *str, int fd)
{
	char	*buffer;
	int		readed;

	if (!save)
		str = "\0\0";
	buffer = ft_calloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (ft_strchr(str, '\n') != -1 && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = loadbuffer(save, fd);
	if (!save)
		return (NULL);
	line = lineclnr(save);
	save = saveclnr(save);
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