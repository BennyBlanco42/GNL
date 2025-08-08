/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanteu <bchanteu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:00:19 by bchanteu          #+#    #+#             */
/*   Updated: 2025/08/08 16:17:23 by bchanteu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s1)
{	
	int	i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len_src;

	dest = NULL;
	len_src = ft_strlen(src);
	dest = malloc(sizeof (char) * (len_src + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_strjoin(char *s1, char *s2, char **dest)
{
	int		i;
	int		j;

	*dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (*dest == (NULL))
		return ;
	i = 0;
	while (i < ft_strlen(s1))
	{
		dest[0][i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		dest[0][j + ft_strlen(s1)] = s2[j];
		j++;
	}
	dest[0][i + j] = '\0';
}

char	*buildstash(char *stash, char *buffer)
{
	char	*temp;

	temp = NULL;
	if (buffer == NULL)
		return (NULL);
	if (stash == NULL)
		return (ft_strdup(buffer));
	temp = ft_strdup(stash);
	free(stash);
	ft_strjoin(temp, buffer, &stash);
	free(temp);
	return (stash);
}
