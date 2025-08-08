/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:28:04 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/08 13:14:16 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*sepstash(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (NULL);
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

int	ft_scansatash(char *stash)
{
	int	lenstash;
	int	i;

	if (stash == NULL)
		return (0);
	lenstash = ft_strlen(stash);
	i = 0;
	while (i < lenstash)
	{
		if (stash[i++] == 10)
		{
			return (1);
		}
	}
	return (0);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
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
	static char	*stash = NULL;
	char		*buffer;
	char		*line;
	int			bytes;

	if (fd == -1)
		return (NULL);
	bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_scansatash(stash) && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), NULL);
		buffer[bytes] = '\0';
		stash = buildstash(stash, buffer);
	}
	free(buffer);
	if (!stash || stash[0] == '\0')
		return (NULL);
	line = extract_line(stash);
	stash = sepstash(stash);
	return (line);
}

// int main(void)
// {
//     int     fd;
//     char    *next_line;

//     fd = open("files/test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("open");
//         return (1);
//     }

//     while ((next_line = get_next_line(fd)) != NULL)
//     {
//         printf("|S|%s|E|\n", next_line);
//         free(next_line);
//     }

//     printf("EOF\n");
//     close(fd);
//     return (0);
// }
