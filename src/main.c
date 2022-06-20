#define _GNU_SOURCE
#include <fcntl.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define delete_module(name, flags) syscall(__NR_delete_module, name, flags)

int main(int argc, char **argv)
{
    char fname[14] = "/proc/syslogk";
    if (access(fname, F_OK) != 0) {
        printf("%s does not exist\n", fname);
        return EXIT_SUCCESS;
    }

	int fd = open(fname, O_WRONLY);
	lseek(fd, 0 , SEEK_SET);
	write(fd, "1", 1);
	close(fd);

    if (delete_module(fname, O_NONBLOCK) != 0) {
        printf("failed deleting %s\n", fname);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}