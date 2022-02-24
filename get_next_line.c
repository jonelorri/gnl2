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
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, char const *set);
int		ft_search_n(const char *s1);

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
	n = ft_search_n(holder);
	while(n == 0) //o hay '\0'
	{
		a = read(fd, buf, BUFFER_SIZE);
		holder = ft_strjoin(holder, buf);
		n = ft_search_n(holder);
	}
	line = (char *)malloc(sizeof(char) * (n + 1));
	ft_strlcpy(line, holder, n + 1);
	holder = ft_strtrim(holder, line);
	free(buf);
	return(line);
}

int main()
{
	int fd;
	char *result;
	int i;

	i = 0;
	fd = open("/Users/jelorria/cursus/gnl/text.txt", O_RDONLY);
	while(i < 5)
	{
		result = get_next_line(fd);
		printf("%s", result);
		i++;
	}
	return(0);
}
