/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefabreg <lefabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:12:25 by jyjy              #+#    #+#             */
/*   Updated: 2024/02/28 15:28:02 by lefabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concate;
	char	*result;
	size_t	space_needed;

	if (!s1 || !s2)
		return (NULL);
	space_needed = ft_strlen(s1) + ft_strlen(s2) + 1;
	concate = (char *)malloc(sizeof(char) * space_needed);
	if (concate == NULL)
		return (NULL);
	result = concate;
	while (*s1 != '\0')
	{
		*concate = *s1;
		s1++;
		concate++;
	}
	while (*s2 != '\0')
	{
		*concate = *s2;
		s2++;
		concate++;
	}
	*concate = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
	{
		return (0);
	}
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	remaining_length;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	remaining_length = ft_strlen(s + start);
	if (len > remaining_length)
		len = remaining_length;
	s1 = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!s1)
		return (NULL);
	while (i < len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

size_t	index_for_n(char *buffer)
{
	size_t	i;
	size_t	is_n;

	i = 0;
	is_n = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			is_n = 1;
			i++;
			break ;
		}
		i++;
	}
	if (!is_n)
		return (0);
	return (i);
}
