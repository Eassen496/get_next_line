/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:13:41 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/17 14:23:55 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = isnl(str);
	while (str[++j])
		i++;
	if (i != 0)
		i--;
	return (i);
}

int	isnl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}

char	*endsave(char *str)
{
	static char	*save = NULL;
	char		*tmp;
	int			i;
	int			j;

	j = 0;
	if (!save && !str)
	{
		tmp = ft_calloc(1, 1);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	else if (!save)
	{
		i = isnl(str);
		if (str[i + 1] == '\0' || i == 0)
			return (str);
		save = malloc((endlen(str) + 1) * sizeof(char));
		save[0] = str[++i];
		while (str[i])
			save[++j] = str[++i];
		save[j] = '\0';
		str = strcln(str);
		return (str);
	}
	else
	{
		tmp = save;
		save = NULL;
		return (tmp);
	}
}

int	isline(char *buffer, int result)
{
	int	i;

	i = 0;
	while (result-- > 0 && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char	*buffer1;
	int		result1;
	char	*buffer2;
	int		result2;
	char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = endsave(NULL);
	buffer1 = ft_calloc(BUFFER_SIZE, 1);
	if (!buffer1)
		return (NULL);
	result1 = read(fd, buffer1, BUFFER_SIZE);
	buffer1 = ft_strjoin(save, buffer1, 0, result1);
	if (result1 == 0 || result1 == -1)
	{
		free(buffer1);
		return (NULL);
	}
	while (isline(buffer1, result1) == 0)
	{
		buffer2 = ft_calloc(BUFFER_SIZE, 1);
		if (!buffer2)
			return (NULL);
		result2 = read(fd, buffer2, BUFFER_SIZE);
		buffer1 = ft_strjoin(buffer1, buffer2, result1, result2);
		result1 += result2;
		if (result2 == 0)
			break ;
	}
	buffer1 = endsave(buffer1);
	return (buffer1);
}

/*
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	int		fd = open("test", O_RDONLY);
	char	*buffer;

	printf("File: [%s] - Fd: %d\n", "test", fd);
	buffer = get_next_line(fd);
	while (buffer)
	{
		printf("$>%s\n", buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}
*/
