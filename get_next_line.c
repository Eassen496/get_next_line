/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:52:35 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/17 23:23:56 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	char	*str;
	char	*save;
	int		result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = endsave(NULL);
