/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:13:12 by lefabreg          #+#    #+#             */
/*   Updated: 2024/02/27 19:05:27 by lefabreg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*manage_line_with_n_for_buffer(char *buffer, size_t index);
char	*manage_line_with_n_for_line(char *buffer, size_t index);
char	*read_line(int fd, char *buffer, char *previous_line, int *bytes_read);
char	*helper(int fd, char *buffer, int bytes_read);
size_t	index_for_n(char *buffer);

#endif