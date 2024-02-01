/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:53 by enschnei          #+#    #+#             */
/*   Updated: 2024/01/22 13:32:49 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char *stack)
{
	int		i;
	char	*s;

	i = 0;
	if (!stack[i])
		return (NULL);
	while (stack[i] && stack[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (stack[i] && stack[i] != '\n')
	{
		s[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		s[i] = stack[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*save(char *stack)
{
	int		i;
	int		y;
	char	*s;

	i = 0;
	while (stack[i] && stack[i] != '\n')
		i++;
	if (!stack[i])
	{
		free(stack);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(stack) - i + 1));
	if (!s)
		return (NULL);
	i++;
	y = 0;
	while (stack[i])
		s[y++] = stack[i++];
	s[y] = '\0';
	free(stack);
	return (s);
}

static char	*ft_read_and_save(int fd, char *stack)
{
	char	*buff;
	int		i;
	char	*tmp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!stack)
		stack = ft_strdup("\0");
	i = 1;
	while (!ft_strchr(stack, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(stack);
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		tmp = stack;
		stack = ft_strjoin(stack, buff);
		free(tmp);
	}
	return (free(buff), stack);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stack[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stack[fd] = ft_read_and_save(fd, stack[fd]);
	if (!stack[fd])
		return (NULL);
	line = get_line(stack[fd]);
	stack[fd] = save(stack[fd]);
	if (!line && stack[fd])
		free(stack[fd]);
	return (line);
}
