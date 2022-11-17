/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:49:32 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/17 12:41:07 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		isline(char *buffer, int result);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int res1, int res2);
void	*ft_calloc(size_t count, size_t size);
char	*endsave(char *str);
int		isnl(char *str);
int		endlen(char *str);
int		ft_strlen(char *str);
char	*strcln(char *str);

#endif
