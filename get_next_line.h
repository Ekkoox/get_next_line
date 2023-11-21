/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:22:38 by enschnei          #+#    #+#             */
/*   Updated: 2023/11/18 16:22:38 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET NEXT_LINE
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line (int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);

#endif