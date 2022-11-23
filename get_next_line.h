/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 00:31:41 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/23 21:32:10 by ale-roux         ###   ########.fr       */
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

char            *get_next_line(int fd);
char			*ft_strchr(const char *s, int c);
char	        *ft_strjoin(char *s1, char *s2);
void        	*ft_calloc(unsigned int size);
size_t	        ft_strlen(char *str);
char	        *loadbuffer(char *str, int fd);
char	        *saveclnr(char *str);
int	            isnl(char *str);
char	        *lineclnr(char *str);

#endif
