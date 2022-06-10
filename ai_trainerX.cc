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


using namespace std;  

#define MAX_BUF 1024
int main()
{
    // This is all data we wat //
    // For fifo conection & while loop //

    int fd;
    char * myfifo = "/tmp/myfifoX";
    char buf[MAX_BUF];
    string OK = "Yes";
    // create the FIFO (named pipe) //

    mkfifo(myfifo, 0666);
    // This is one until i conect in with //
    //The sql server //
    while(1){

        // Here we write to confirm the AI 
        // Is ready to make a move 
    fd = open(myfifo, O_WRONLY);
    write(fd, "Yes", sizeof("Yes"));
    close(fd);

        //Then we expect from the main fuction
        // to sent us the msg "Play" so it can start
        //Canculationg its next move 
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Received: %s\n", buf);
        
        //In this part we making random moves
        //So the programm generates random numbers
        //But not all are right so we must filter them
        //All that  by the main 
    bool acceptable_actions = false;
    
        //The loop will continue until the
        //answer is accepted from the main
    while(!acceptable_actions){

        // Here we open the pipe to 
        // sent the move we got to the main

    fd = open(myfifo, O_WRONLY);
        int Move = rand() % 9  ;

        //Here we make some configuration //
        // From int -> string -> const void * 
        // it might be changed!
    string str= to_string(Move);
    const void * a = str.c_str(); 
    write(fd,a, sizeof(a));
    close(fd);

    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    if((strcmp(buf,"Yes"))==0){
    printf("Received: %s\n", buf);
    break; 
    }
       
    }

    }
    /* remove the FIFO */
    unlink(myfifo);

    return 0;
}