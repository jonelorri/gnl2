#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = ft_strlen(src);
	if (dstsize)
	{
		while (src[++i] && --dstsize)
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n-- > 0)
		*(ptr++) = *(ptr2++);
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	*(dest + ft_strlen(s1)) = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	i = dstl;
	if (dstl >= dstsize)
		return (dstsize + srcl);
	while (dstl < dstsize - 1 && *src)
		*(dst + dstl++) = *src++;
	*(dst + dstl) = '\0';
	return (i + srcl);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	//printf("s1 = %s\n s2 = %s\n", s1, s2);
	s1_len = ft_strlen(s1);
	//printf("uno %d\n", s1_len);
	s2_len = ft_strlen(s2);
	//printf("dos %d\n",s2_len);
	
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcat(&dest[s1_len], s2, s2_len + 1);
	free((char *)s1);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*srt;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s || len < 0)
		return (NULL);
	srt = (char *)malloc(len + 1 * (sizeof(char)));
	if (!srt)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
		j++;
	while (start < j && i < len)
	{
		srt[i] = s[start];
		i++;
		start++;
	}
	srt[i] = '\0';
	return (srt);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	end;

	end = 1;
	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		if(*s1 != '\n')
			s1++;
		else
			break;
	if(*s1 == '\n')
		s1++;
	return (ft_substr(s1, 0, ft_strlen(s1)));
}

int	ft_search_n(const char *s1)
{
	int i;
	int nLocation;

	nLocation = 0;
	i = 0;
	while(i < (int)ft_strlen(s1))
	{
		if(s1[i] == '\n')
		{
			nLocation = i + 1;
			break;
		}
		i++;
	}
	return(nLocation);
}
