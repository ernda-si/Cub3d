/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eve <eve@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:20:44 by ernda-si          #+#    #+#             */
/*   Updated: 2025/10/24 13:33:54 by eve              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*ft_strjoin_GNL(char *line, char *buff, size_t	line_len, size_t buff_len);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		cut_buff(char *buffer);
// int		hasnl(char *buffer);

#endif