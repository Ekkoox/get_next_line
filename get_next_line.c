/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/11/18 16:32:09 by enschnei          #+#    #+#             */
/*   Updated: 2023/12/14 15:34:34 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_clean_stash(char *stash)
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

char	*get_next_line(int fd)
{
	int			i;
	char		*str;
	char		*buffer;
	static char	*stash;

	str = NULL;
	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (i != 0 && ft_strchr(buffer, '\n') != 1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
		{
			str = NULL;
			free(buffer);
			free(stash);
			stash = NULL;
			buffer = NULL;
			return (str);
		}
		buffer[i] = 0;
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
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
// 	//    int fd = open("test.txt", O_RDONLY);
// 	int fd = open("bible.txt", O_RDONLY);
// 	int i = 1;
// 	//    FILE *file = fopen("a.out", "r");
// 	char *next_line = NULL;
// 	while (i)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			return (printf("next_line[%d] = %s\n", i, next_line));
// 		printf("next_line[%d] = %s", i, next_line);
// 		free(next_line);
// 		i++;
// 	}
// 	return (0);
// }
