/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:48:25 by mbouaza           #+#    #+#             */
/*   Updated: 2023/11/07 15:11:00 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Creation of my buffer_size, used for read() */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* include */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/* Lib for get_next_line */

// char //

char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

// int //

int		check_newline(char c, char *s);

// size_t //

size_t	ft_strlen(char *s);

#endif
