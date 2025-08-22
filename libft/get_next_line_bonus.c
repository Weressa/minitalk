/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:20:27 by assabich          #+#    #+#             */
/*   Updated: 2024/12/31 13:20:32 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char	*create_line(int fd, char *buf, char *left)
{
	int		lu;
	char	*temp;

	lu = read(fd, buf, BUFFER_SIZE);
	while (lu > 0)
	{
		buf[lu] = '\0';
		if (left)
			temp = ft_strjoin(left, buf);
		else
			temp = ft_strdup(buf);
		free(left);
		left = temp;
		if (ft_strchr(left, '\n'))
			break ;
		lu = read(fd, buf, BUFFER_SIZE);
	}
	if ((lu == 0 && left && *left == '\0') || lu < 0)
	{
		free(left);
		left = NULL;
	}
	free(buf);
	return (left);
}

char	*extract_line(char *left)
{
	char	*newl;
	char	*line;

	newl = ft_strchr(left, '\n');
	if (newl)
		line = ft_substr(left, 0, (newl - left + 1));
	else
		line = ft_strdup(left);
	return (line);
}

char	*leftover(char *left)
{
	char	*newl;
	char	*remain;

	newl = ft_strchr(left, '\n');
	if (newl)
		remain = ft_strdup(newl + 1);
	else
		remain = NULL;
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*left[FOPEN_MAX];
	char		*buf;
	char		*line;
	char		*temp;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	left[fd] = create_line(fd, buf, left[fd]);
	if (!left[fd])
		return (NULL);
	line = extract_line(left[fd]);
	temp = leftover(left[fd]);
	free(left[fd]);
	left[fd] = temp;
	return (line);
}
