#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, char const *set);
int	ft_search_n(const char *s1);
char	*ft_strchr(const char *s, int c);

char *get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*holder;
	size_t		a;
	int		n;

	n = 0;
	line = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(fd == -1 || BUFFER_SIZE <= 0)
		return(NULL);				
	if(!holder)
		holder = ft_strdup("");
	while(!ft_strchr(holder, '\n'))	//bucle principal Read
	{
		a = read(fd, buf, BUFFER_SIZE);
		if(a == 0)
		{
			printf("q hay holder= %s\n", holder);
			line = (char *)malloc(sizeof(char) * (ft_strlen(holder) + 1));
			line = ft_strjoin(line, holder);
			free(buf);
			return(line);
		}
		holder = ft_strjoin(holder, buf);
	}
	//ok ahora ya si que hay \n
	n = ft_search_n(holder);
	line = (char *)malloc((n) * sizeof(char));
	ft_strlcpy(line, holder, n + 1);
	holder = ft_strtrim(holder, line); 				//EL TRIM ME HACE MAL!!! en la ultima linea
	//printf("quiero ver lo que hay en holder = %s\n", holder);
	free(buf);
	return(line);	
}

int main()
{
	int fd;
	char *result;
	int i;

	i = 0;
	fd = open("/Users/jonelorriaga/programacion/42/gnl2/text.txt", O_RDONLY);
	while(i < 5)
	{
		result = get_next_line(fd);
		printf("RESULTADO =%s", result);
		sleep(2);
		i++;
	}
	return(0);
}
