#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
void close_fd(int fd);
void print_error(char *msg, char *opt, int status);
/**
 * main - check code
 * @argc: Numbers of arguments
 * @argv: Arguments
 *
 * Return: Always 0
 **/
int main(int argc, char **argv)
{
	int fd_to, fd_from, r_bytes, w_bytes;
	char buffer[1024];

	if (argc != 3)
		print_error("Usage: cp file_from file_to", "", 97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file ", argv[1], 98);


	fd_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (fd_to == -1)
	{
		close_fd(fd_from);
		print_error("Error: Can't write to ", argv[2], 99);
	}

	r_bytes = read(fd_from, buffer, 1024);
	while (r_bytes > 0)
	{
		w_bytes = write(fd_to, buffer, r_bytes);
		if (w_bytes != r_bytes)
		{
			close_fd(fd_from);
			print_error("Error: Can't write to ", argv[2], 99);
		}
		r_bytes = read(fd_from, buffer, 1024);
	}
	if (r_bytes == -1)
		print_error("Error: Can't read from file ", argv[1], 98);
	close_fd(fd_from);
	close_fd(fd_to);
}
/**
 * close_fd - close file descriptor
 * @fd: file descriptor
 * Return: void
 */
void close_fd(int fd)
{
	int err;

	if (fd > 0)
	{
		err = close(fd);
		if (err == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
			exit(100);
		}
	}
}

/**
 * print_error - Print the error and close the file descriptor
 * @msg: Error message to show
 * @opt: Optional arguments
 * @status: Exit status code
 **/
void print_error(char *msg, char *opt, int status)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, opt);
	exit(status);
}
