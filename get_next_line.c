/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:32:09 by enschnei          #+#    #+#             */
/*   Updated: 2023/11/18 16:32:09 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *set_line(char *buffer)
{
	size_t i;
	char *str;

	i = 0;
	while(buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	str = ft_substr(buffer, i + 1, ft_strlen(buffer) - i) + 1;
	if(str[i] == 0)
	{	
		free(str);
		return(NULL);
	}
	str = '\0';
	return(str);
}

char *line_buffer(int fd, char *buffer, char *c)
{
	size_t read_line;
	char *tmp;

	read_line = 1;
	while(read_line > 0)
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if(read_line == -1)
		{
			free(buffer);
			return(NULL);
		}
	}
	return(buffer);
}