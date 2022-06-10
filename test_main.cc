#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define MAX_BUF 1024

int main()
{
     // This is all data we wat //
    // For fifo conection & while loop //

    int fd;
    char*  myfifoO = "/tmp/myfifoO";
    char*  myfifoX = "/tmp/myfifoX";
    char buf[MAX_BUF];
    bool acceptable_actions = false;
    int i=0;
    /* open, read, and display the message from the FIFO */
    
    while (i++<5){
    
        //Opes the conection with the fist Player
        //Now reads the message from the Player1
    fd = open(myfifoX, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Player 1 conection: %s\n", buf);
        
        //Now writes the message to the AI/PLAYER1
        //to start the canculation 

    fd = open(myfifoX, O_WRONLY);
    write(fd, "Play", sizeof("Play"));
    close(fd);

        //This bool will start with false
        //Until its its switched to end the
        // loop 

        acceptable_actions = false;
    while(!acceptable_actions){

        // Opes the pipe to read the message

    fd = open(myfifoX, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Player 1 move: %s\n", buf);
    close(fd);
     if(stoi(buf)==4){
         fd = open(myfifoX, O_WRONLY);
        write(fd, "Yes", sizeof("Yes"));
        close(fd);
         acceptable_actions = true;
         }else{
        fd = open(myfifoX, O_WRONLY);
        write(fd, "No", sizeof("No"));
        close(fd);
         }
    }

   

    fd = open(myfifoO, O_RDONLY);
    read(fd, buf, MAX_BUF);
    close(fd);
    printf("Player 2 conection: %s\n", buf);

        fd = open(myfifoO, O_WRONLY);
    write(fd, "Play", sizeof("Play"));
    close(fd);
        
        acceptable_actions = false;
    while(!acceptable_actions){
           // Opes the pipe to read the message

    fd = open(myfifoO, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Player 2 move: %s\n", buf);
    close(fd);
     if(stoi(buf)==3){
         fd = open(myfifoO, O_WRONLY);
        write(fd, "Yes", sizeof("Yes"));
        close(fd);
        acceptable_actions = true;
         }else{
        fd = open(myfifoO, O_WRONLY);
        write(fd, "No", sizeof("No"));
        close(fd); }
    }
    printf("\nEND OF ROUND\n");
    }

std::string line; 
while (std::getline(std::cin, line))
{
    std::cout << line << std::endl;
}
    return 0;
}