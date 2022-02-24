#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (*str++)
		str_len++;
	return (str_len);
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
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcat(&dest[s1_len], s2, s2_len + 1);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, &s[start], len + 1);
	return (dest);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end]))
		end--;
	return (ft_substr(s1, 0, end + 1));
}

int	ft_search_n(const char *s1)
{
	int i;
	int nLocation;

	nLocation = 0;
	i = 0;
	while(i < ft_strlen(s1))
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
