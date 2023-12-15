/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: enschnei <marvin@42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/12/15 15:54:26 by enschnei          #+#    #+#             */
/*   Updated: 2023/12/15 15:54:30 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *stash)
{
	size_t	i;
	char	*str;

	i = 0;
	if (stash && !ft_strchr(stash, '\n'))
		return (NULL);
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_clean_stash(char *stash)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	new = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (stash[i])
	{
		new[j] = stash[i + j];
		j++;
	}
	new[j] = '\0';
	return (free(stash), new);
}

static char	*ft_stash(int fd, char *stash)
{
	int		i;
	char	*buffer;

	i = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if(!stash)
		stash = ft_strdup("");
	while (i != 0 && ft_strchr(stash, '\n') != 1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			if (!ft_strchr(stash, '\n'))
			 	return (stash);
			stash = NULL;
			buffer = NULL;
			return (buffer);
		}
		buffer[i] = 0;
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stash;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_stash(fd, stash);
	str = set_line(stash);
	stash = ft_clean_stash(stash);
	return (str);
}

/*int main()
{
	char *str;
	int fd;

	str = NULL;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (0);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	// for (int i = 0; i < 10; i++)
	// {
	// 	str = get_next_line(fd);
	// }
	return (0);
}*/

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//    int fd = open("41_with_nl", O_RDONLY);
// 	//    int fd = open("alternate_line_nl_no_nl", O_RDONLY);
// 	//    int fd = open("king_james.txt", O_RDONLY);
// 	   int fd = open("test.txt", O_RDONLY);
// 	// int fd = open("bible.txt", O_RDONLY);
// 	//    FILE *file = fopen("a.out", "r");
// 	char *next_line = NULL;
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		next_line = get_next_line(fd);
// 		printf("%s", next_line);
// 		free(next_line);
// 		i++;
// 	}
// 	return (0);
// }