/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:28:04 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/06 17:43:30 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#define BUFFER_SIZE	10
//REVOIR POUR LE BUFFER_SIZE = 10 /!\ doble free ?? pb sur buildstash ??
int	ft_scansatash(char *stash)
{
	int	lenstash;
	int	i;
	
	lenstash = ft_strlen(stash);
	i = 0;
	while (i < lenstash)
	{
		if (stash[i++] == 10)
		{
			printf("il y'a un /n dans le stash\n");
			return (1);
		}
	}
	return(0);
}

char *extract_line(char *stash)
{
	int	i;
	char	*line;
		
	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
char	*get_next_line(int fd)
{
	static char *stash = NULL;
	char	*buffer;
	int	bytes;

	if (fd == -1)
		return("Error: Invalid file descriptor");
	
	bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (bytes != 0)
	{	
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			printf("erreur ou fin du fichier");
			break;
		}
		buffer[bytes] = '\0';
		stash = buildstash(stash, buffer);
		if (ft_scansatash(stash) == 1)
			return (extract_line(stash));
			
	}
	return("stash");
}

int main(void)
{
	int	fd;
	char	*next_line;

	next_line = "test";
	fd = open("files/test.txt", O_RDONLY);
	printf("new_line => %s\n", get_next_line(fd));
	close(fd);
	return(0);
}

// int	main(void)
// {
//     int        fd;
//     char    *next_line;

//     next_line = "test";
//     fd = open("files/test.txt", O_RDONLY);
//     while (next_line != NULL)
//     {
//         next_line = get_next_line(fd);
//         if (next_line == NULL)
//             printf("EOF\n");
//         else {
//             printf("|S|%s|E|", next_line);
//             free(next_line);
//         }
//     }
//     next_line = NULL;
//     close(fd);
//     return(0);
// }
// gerer le cas ou read return -1 => erreur de lecture => stop 
