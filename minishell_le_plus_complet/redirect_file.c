#include "minishell.h"

int	redirect_file(const char *target, int std_fd, int flags, int mode)
{
	int	fd;

	fd = open(target, flags, mode);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	if (dup2(fd, std_fd) == -1)
	{
		perror("dup2");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
