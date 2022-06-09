#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <cstdio>

#define MAX_BUF 1024

int main()
{
    int fd;
    char*  myfifoO = "/tmp/myfifoO";
    char*  myfifoX = "/tmp/myfifoX";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */int i=0;
    while (i++<5){
    fd = open(myfifoX, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Player 1 conection: %s\n", buf);

        fd = open(myfifoX, O_WRONLY);
    write(fd, "Play", sizeof("Play"));
    close(fd);
    fd = open(myfifoX, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Player 1 move: %s\n", buf);

    fd = open(myfifoO, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Player 2 conection: %s\n", buf);

        fd = open(myfifoO, O_WRONLY);
    write(fd, "Play", sizeof("Play"));
    close(fd);
    fd = open(myfifoO, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Player 2 move: %s\n", buf);
    printf("\nEND OF ROUND\n");
    }
    return 0;
}