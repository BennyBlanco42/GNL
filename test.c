#define BUFFER_SIZE	10
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>


size_t	ft_strlen(const char *s1)
{	
	int	i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size -1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	// VERIFIER SI BESOIN DE CETTE LIGNE dest[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c2;

	str = (unsigned char *)s;
	c2 = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == c2)
			return ((void *) &str[i]); // &str[i +1] => pour gader le \n
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			c2;

	c2 = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c2)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c2)
		return ((char *) &s[i]);
	return (NULL);
}

int main()
{
	char	buffer[10000];
	static char stash[1000];
	char ligne[1000];
	int fd;
	ssize_t bytes;
	int	i = 0;
	
	fd = open("files.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erreur d'ouverture");
		close(fd);
		exit(EXIT_FAILURE);
	}

	while (ft_strchr(stash, 10) == NULL)
	{
		//pqs sur de cette boucle 
		break;
	}


	while (read(fd, buffer, BUFFER_SIZE) != 0)
	{
		if ((ft_strchr(stash, 10) != NULL))
		{
			
		}
		printf("lecture [%d] => '%s'\n", i++, buffer);
	}
	/*
	bytes =	read(fd, buffer, BUFFER_SIZE);
	if (bytes == -1)
	{
		perror("Erreur lecture");
		close(fd);
		exit(EXIT_FAILURE);
	}
	ft_strlcpy(stash, buffer, BUFFER_SIZE +1);
	printf("Contenu lu \n%s\n", buffer);
	printf("Contenu deplace dans stash; \n%s\n", stash);
	*/

/*if (ft_memchr(stash, 10, 100) != NULL)
	{	
		printf("NEw buffer \n%s\n", buffer);
		buffer[0] = '\0';
		printf("NEw buffer \n%s\n", buffer);
		printf("trouve /n");
		//mettre ce que return ft_memchr dans buffer et le reste 
		ft_strlcpy(buffer, ft_memchr(stash, 10, 100), 10);
		printf("NEw buffer \n%s\n", buffer);
		//printf("Contenu deplace dans stash; \n%s\n", stash);

	}
*/
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		len_src;

	len_src = ft_strlen (src);
	dest = (char *) malloc (sizeof (char) * len_src + 1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	int		len2;
	char	*dest;

	dest = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(2) + 1));
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
	int i;
	int	j;
	char *temp;

	temp = ft_strdup(stash);
	free(stash);
	stash = ft_strjoin(temp, buffer);
	return (stash);

	
}


/* char * OU void function buildstash(char *stash, char *buffer):
	create var char *temp
	stash = "hello\0"
	buffer = "everyone\n\0"
	-> in the function
	create char * temp (mallo sizeofchar * stashlen + 1) (strdup)
	free(stash)
	malloc stash = sizeofchar * (templen or same var stashlen) + (bufferlen) + 1
	then iterate i and j to build stash = "temp+buffer" ("hello"+"everyone\n\0")
	*/
