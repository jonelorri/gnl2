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
int		ft_search_n(const char *s1);
char	*ft_strchr(const char *s, int c);

char *get_next_line(int fd)
{
	char		*buf;
	char		*line;
	char		*temp;
	static char	*holder;
	size_t		a;
	int			n;

	n = 0;
	line = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(fd == -1 || BUFFER_SIZE <= 0)
		return(NULL);				
	if(holder == NULL)
		holder = ft_strdup("");
	a = BUFFER_SIZE;
	while(ft_strchr(holder, '\n') == NULL && a == BUFFER_SIZE)	//bucle principal Read
	{
		a = read(fd, buf, BUFFER_SIZE);
		holder = ft_strjoin(holder, buf);
	}
	if(ft_search_n(holder) != 0)		//si hay \n...
	{
		n = ft_search_n(holder);
		ft_strlcpy(line, holder, n + 1);
		holder = ft_strtrim(holder, line);
		free(buf);
		return(line);
	}
	else if(a < BUFFER_SIZE && a != -1)		//okei no hay \n pero si hay '\0'...
	{
		printf("a = %zu\n", a);
		printf("lo que hay en holder = %s\n", holder);
		printf("lo que hay en buf = %s\n", buf);			//(veo que hay que recortar el buf (pasandolo  a un temp) con la medida de a) 
	}
	free(buf);
	return("fin");	
}

int main()
{
	int fd;
	char *result;
	int i;

	i = 0;
	fd = open("/Users/jelorria/cursus/gnl/2text.txt", O_RDONLY);
	while(i < 1)
	{
		result = get_next_line(fd);
		printf("%s", result);
		i++;
	}
	return(0);
}
