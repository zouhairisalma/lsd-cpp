#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>


# define BUFFER_SIZE 1024

int		get_next_line(int , char **);
size_t	ft_strlcpy(char *, const char *, size_t );
size_t	ft_strlen(const char *);
char	*ft_strdup(const char *);
char	*ft_strjoinn(char const *, char const *);
char	*ft_substr(char const *, unsigned int , size_t );

#endif

