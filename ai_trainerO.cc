#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <cstdio>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>  
#include<sstream>  

using namespace std;  

#define MAX_BUF 1024
int main()
{
    int fd;
    char * myfifo = "/tmp/myfifoO";
    char buf[MAX_BUF];
    /* create the FIFO (named pipe) */
    mkfifo(myfifo, 0666);

    while(1){
    fd = open(myfifo, O_WRONLY);
    write(fd, "Yes", sizeof("Yes"));
    close(fd);
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Received: %s\n", buf);
    fd = open(myfifo, O_WRONLY);
    int Move = rand() % 10  ;
    string str= to_string(Move);
    const void * a = str.c_str(); 
    write(fd,a, sizeof(a));
    close(fd);
    }
    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}