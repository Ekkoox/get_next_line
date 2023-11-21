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

char *get_next_line (int fd)
{
	char	*stash;
	char	*line;
	char	*buffer;

	buffer = malloc();
	return(line);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main() {
    // Ouvrir un fichier en lecture seule (O_RDONLY)
    int fileDescriptor = open("enzo.txt", O_RDONLY);

    if (fileDescriptor == -1)
	{
        perror("Erreur lors de l'ouverture du fichier");
        return (1);
    }

    char buffer[BUFFER_SIZE];
    
    // Utilisation de la fonction read pour lire depuis le fichier
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer) - 1);

    if (bytesRead == -1) 
	{
        perror("Erreur lors de la lecture du fichier");
        close(fileDescriptor); // Fermer le descripteur de fichier en cas d'erreur
        return 1;
    }

    // Ajout d'un caractère nul à la fin du tampon pour former une chaîne de caractères valide
    buffer[bytesRead] = '\0';

    printf("Contenu du fichier :\n%s", buffer);

    // Fermer le descripteur de fichier après utilisation
    close(fileDescriptor);

    return 0;
}*/