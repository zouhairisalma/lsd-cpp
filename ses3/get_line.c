#include "read_line.h"
#include <stdio.h>

static char	*ft_strchr(const char *s, int c)
{
	while (*(char *)s != '\0' && *s != (char)c)
		s++;
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (0);
}

static int	ternary(int indicator, char **line, char **s)
{
	if ((indicator == 0) || *line)
	{
		s = 0;
		if (indicator == 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

int	output(char **line, char **s, int k)
{
	char		*str;
	int			indicator;

	indicator = 1;
	if (k < 0)
		return (-1);
	str = ft_strchr(*s, '\n');
	if (!(str))
	{
		str = ft_strchr(*s, '\0');
		indicator = 0;
	}
	str++;
	*line = malloc(sizeof(char) * (str - *s) + 1);
	ft_strlcpy(*line, *s, (str - *s));
	str = *s;
	*s = ft_substr(*s, ft_strlen(*line) + 1,
			ft_strlen(*s) - ft_strlen(*line) + 1);
	free(str);
	return (ternary(indicator, line, s));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *d, const char *s, size_t n)
{
	size_t		k;
	void		*dest;

	dest = d;
	k = ft_strlen(s);
	if (n == 0)
		return (k);
	if (dest == NULL)
		return (0);
	if (n)
	{
		while (n - 1 > 0 && *s)
		{
			*(unsigned char *)dest++ = *(unsigned char *)s++;
			n--;
		}
	}
	*(unsigned char *)dest = '\0';
	return (k);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!(ptr))
		return (0);
	while (i < len)
	{
		ptr[i] = (char)s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoinn(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((s1 == 0 && s2 == 0) || !s1)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(str))
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i++] = s2[j];
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (0);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (0);
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

















int	get_next_line(int fd, char **line)
{
	static char		*s;
	char			*buffer;
	char			*temp;
	int				k;

	if (BUFFER_SIZE < 0 || fd < 0 || line == NULL)
		return (-1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (s == NULL)
		s = ft_strdup("");
	k = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(s, '\n') && k > 0)
	{
		buffer[k] = '\0';
		temp = s;
		s = ft_strjoinn(s, buffer);
		free(temp);
		k = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(line, &s, k));
}








