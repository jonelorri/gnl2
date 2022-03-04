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
char	*ft_fromn(char *holder);

char *get_next_line(int fd)
{
	char		*buf;
	char		*line;
	char		*temp;
	static char	*holder;
	size_t		a;
	int		n;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	line = ft_strdup("");
	temp = ft_strdup("");
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if(!buf)
		return (NULL); 
	if(!holder)
		holder = ft_strdup("");
	while(ft_search_n(holder) == 0)
	{
		a = read(fd, buf, BUFFER_SIZE);
		buf[a] = 00;
		if(a == 0)
		{
			if(ft_strlen(holder) > 0)
			{
				line = (char *)malloc(sizeof(char) * ft_strlen(holder) + 1);
				line = holder;
				holder = NULL;	
				return(line);
			}
			else
				return(NULL);
		}
		if(a < BUFFER_SIZE && a > 0)
		{	
			if(ft_strlen(holder) > 0)
			{
				temp = (char *)malloc(sizeof(char) * (a + 1));
				ft_strlcpy(temp, buf, a + 1);
				holder = ft_strjoin(holder, temp);
				free(temp);
				temp = NULL;
			}
			else
				ft_strlcpy(holder, buf, a + 1);
		}
		if(a == BUFFER_SIZE)
			holder = ft_strjoin(holder, buf);
	}
	n = ft_search_n(holder);
	line = (char *)malloc((n + 1) * sizeof(char));
	ft_strlcpy(line, holder, n + 1);
	holder = ft_strtrim(holder, line);
	free(buf);
	return(line);
}
