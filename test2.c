#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_strlen(const char *s1)
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

	len_src = ft_strlen(src);
	dest = (char *) malloc (sizeof (char) * len_src + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	dest = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == (NULL))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= len2)
	{
		dest[i + len] = s2[i];
		i++;
	}
	dest[len + len2 + 1] = '\0';
	free(s1);
	free(s2);
	return (dest);
}


char	*buildstash(char *stash, char *buffer)
{
	char *temp;

	temp = ft_strdup(stash);
	//free(stash);
	stash = ft_strjoin(temp, buffer);
	return (stash);

	
}


// int	main(void)
// {
// 	static char *stash;
// 	char *buffer;

// 	stash = ft_strdup("salut");
// 	buffer = ft_strdup("toute le monde");

	
// 	printf("stash => %s", buildstash(stash, buffer));
// }
int	main(void)
{
    int        fd;
    char    *next_line;

    next_line = "test";
    fd = open("files/test.txt", O_RDONLY);
    while (next_line != NULL)
    {
        next_line = get_next_line(fd);
        if (next_line == NULL)
            printf("EOF\n");
        else {
            printf("|S|%s|E|", next_line);
            free(next_line);
        }
    }
    next_line = NULL;
    close(fd);
    return(0);
}