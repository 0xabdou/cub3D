/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouahib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:30:18 by aouahib           #+#    #+#             */
/*   Updated: 2019/12/06 18:49:19 by aouahib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MAX_FD 10240
# define BUFFER_SIZE 100
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(char *s, char c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);

#endif
