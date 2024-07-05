/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:57:47 by mboyansa          #+#    #+#             */
/*   Updated: 2023/04/13 22:22:05 by mboyansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

char	*trim_str(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = str_check(str);
	if (!str[i])
		return (get_free(str));
	line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	len_s1 = (ft_strlen((char *)s1));
	len_s2 = (ft_strlen((char *)s2));
	res = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s1, len_s1);
	ft_strcpy(&res[len_s1], s2, len_s2);
	free(s1);
	return (res);
}

unsigned int	ft_strlen(const char *str)
{
	unsigned int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*make_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	i = str_check(str);
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
