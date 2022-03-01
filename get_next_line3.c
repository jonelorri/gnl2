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
	static char	*holder;
	char		*temp;
	size_t		a;
	int			n;
	int			contador;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	contador = 0;
	n = 0;
	line = ft_strdup("");
	temp = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	//printf("holder2 -> %s\n", holder); 
	if(!holder)
		holder = ft_strdup("");
	//printf("holder3 -> %s\n", holder);
	while(!ft_strchr(holder, '\n'))	//bucle principal Read
	{
		a = read(fd, buf, BUFFER_SIZE);
		if(a == 0 && contador != 0)
		{
			line = (char *)malloc(sizeof(char) * (ft_strlen(holder) + 1));
			line = ft_strjoin(line, holder);
			free(holder);
			free(buf);
			return(line);
		}
		else if(a == 0 && contador == 0)
			return(NULL);
		else if(a < BUFFER_SIZE && a > 0 && contador == 0 && !ft_strchr(buf, '\n'))
		{
			line = (char *)malloc(sizeof(char) * (a + ft_strlen(holder)) + 1);
			line = ft_strjoin(holder, buf);
			free(buf);
			return(line);
		}
		else if(a < BUFFER_SIZE && a > 0 && contador != 0 && !ft_strchr(buf, '\n'))
		{
			temp = (char *)malloc(sizeof(char) * a + 1);
			ft_strlcpy(temp, buf, a + 1);
			line = (char *)malloc(sizeof(char) * (ft_strlen(holder) + a + 1));
			line = ft_strjoin(holder, temp);
			free(temp);
			free(buf);
			return(line);
		}
		holder = ft_strjoin(holder, buf);
		contador = 1;
	}	
	//ok ahora ya si que hay \n
	//printf("holder4 -> %s\n", holder);
	n = ft_search_n(holder);
	line = (char *)malloc((n + 1) * sizeof(char));
	ft_strlcpy(line, holder, n + 1);
	//printf("holder5 -> %s\n", holder);
	//printf("linea -> %s\n", line);
	holder = ft_strtrim(holder, line);		//tenog q hacer trim de otra forma
	printf("quiero ver lo que hay en holder = %s\n", holder);
	free(buf);
	return(line);	
}
