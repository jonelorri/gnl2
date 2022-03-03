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
char	*get_next_line(int fd);

int main()
{
	int fd;
	char *result;
	int i;

	i = 0;
	fd = open("/Users/jelorria/cursus/gnl2/gnlTester/files/multiple_line_no_nl", O_RDONLY);
	while(i < 3)
	{
		result = get_next_line(fd);
		printf("RESULTADO =%s", result);
		free(result);
		i++;
	}
	return(0);
}
