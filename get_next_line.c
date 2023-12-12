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

static char *set_line(char *buffer)
{
	size_t i; 
	char *str;

	i = 0;
	while(buffer[i] != '\n' || buffer[i] != '\0')
		i++;
	str = ft_substr(buffer, i + 1, ft_strlen(buffer) - i) + 1;
	if(!str)
	{	
		free(str);
		return(NULL);
	}
	str = '\0';
	return(str);
}

char *on_verra(char *buffer)
{
	size_t i;
	char *str;

	i = 0;
	while(buffer[i] != '\n' && buffer[i])
	{
		str = ft_strdup(buffer);
		
	}
	str = '\0';
	return(str);
}

char *get_next_line(int fd)
{
	size_t 		i;
	char 		*str;
	char		*buffer;
	char		*tmp;
	static char *stash;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	stash = '\0';
	while(i != 0 && !ft_strchr(stash, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE); // sois renvoie 1 ou fin = 0 ou error = -1
		if(i == -1)
		{
			free(buffer);
			return(NULL);
		}
		tmp = stash;
		stash = ft_strjoin(stash, buffer); // stash = bonjour\nzizi'\n'
		free(tmp);
	}
	str = set_line(stash);
	str = '\0';
	return(str);
}

//bonjour\n
//zizi\n