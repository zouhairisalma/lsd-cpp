#include "read_lines.h"

void	read_line(int fd)
{
	char		*line;
	int			i;
	// char		*buf;
	// ssize_t		bytes_read;

	i = 1;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char		*line;
	int			fd;
	int			w_fd;
	const char	*tests[] = {
		"tests/test.txt",
		"tests/test2.txt",
		"tests/test3.txt"
	};
	const int	files = sizeof(tests) / sizeof(tests[0]);

	if (argc > 1)
	{
		if (argc > 2)
		{
			printf("Sorry, only accept one file to open");
			return (-1);
		}
		fd = open(argv[1], O_RDWR);
		if (fd < 0) 
		{ 
			perror("r1"); 
			exit(1); 
		} 
		read_line(fd);
		w_fd = write(fd, "\nhello\n", ft_strlen("\nhello\n"));
		// printf("wd = %d\n", w_fd);
		close(fd);
	}
	else
	{
		for (int i = 0; i < files; i++)
		{
			printf("Now testing file %s:\n", tests[i]);
			fd = open(tests[i], O_RDONLY);
			if (fd < 0) 
			{ 
				perror("r1"); 
				exit(1); 
			} 
			line = get_next_line(fd);
			while (line != NULL)
			{
				printf("%s", line);
				free(line);
				line = get_next_line(fd);
			}
			printf("\n\n");
			system("leaks a.out");
			close(fd);
		}
	}
	return (0);
}
