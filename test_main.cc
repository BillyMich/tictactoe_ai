#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <sstream>
using namespace std;

#define MAX_BUF 1024
char square[9] = {'0','1','2','3','4','5','6','7','8'};
int Movements[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};

static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
  
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
  
    printf("\n");
    return 0;
}

int postgame(int Database){


    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("AIdb.db", &DB);

    if (exit) {
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        return (-1);
    }
    else
        std::cout << "Opened Database Successfully!1" << std::endl;

    string my_str;

    
  //  sqlite3* DB;
    char* messaggeError;  
      exit = sqlite3_open("AIdb.db", &DB);
    string query = "SELECT * FROM MovesForX;";
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl;
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
  
//   os << "INSERT INTO MovesForX VALUES( SELECT MAX( id ) + 1,"
//    <<Movements[0]<<"," <<Movements[1]<<"," <<Movements[2] <<"," << Movements[3] <<"," <<Movements[4] <<"," <<Movements[5] <<","
//    <<Movements[6] <<"," << Movements[7] <<"," << Movements[8] << ");";
//                my_str = os.str(); 
    string sql("INSERT INTO MovesForX VALUES(1,2,3,4,5,6,7,8,9,10);");
    cout<<sql<<endl;
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert"  <<std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

    


/*
    if ( Database==2){
    sqlite3* DB;
    char* messaggeError;  
    int  exit = sqlite3_open("AIdb.db", &DB);
    string query = "SELECT * FROM MovesForY;";
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl;
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

   os << "INSERT INTO PERSON VALUES( SELECT MAX( id ) + 1,"
               <<Movements[0]<<"," <<Movements[1]<<"," <<Movements[2] <<"," << Movements[3] <<"," <<Movements[4] <<"," <<Movements[5] <<","
                <<Movements[6] <<"," << Movements[7] <<"," << Movements[8] << ");" ;
                my_str = os.str(); 
  
    string sql(my_str);
  
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
    if (exit != SQLITE_OK) {
        std::cerr << "Error Insert" << std::endl;
        sqlite3_free(messaggeError);
    }
    else
        std::cout << "Records created Successfully!" << std::endl;

    }

    */


}









void PrintData(){

for(int i=0;i<9;i++){
    cout<<Movements[i];
        }

    cout<< "\n";

}



void KeepData(int num){

    for(int i=0;i<9;i++){
        if(Movements[i]== -1){
            Movements[i]=num;
            return;
        }

    }

}


// 0 Null 1 X 2 O 
int checkwin()
	{
		if (square[0] == square [1]  && square[1] == square[2] )
		{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}		
		else
		if (square[3] == square [4]  && square[4] == square[5] )
			{	if ( square [3] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[6] == square [7]  && square[7] == square[8] )
			{	if ( square [6] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
		else
		if (square[1] == square [4]  && square[4] == square[7] )
			{	if ( square [1] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (square[2] == square [5]  && square[5] == square[8] )
			{	if ( square [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
    else
		if (square[0] == square [4]  && square[4] == square[8] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (square[2] == square [4]  && square[4] == square[6] )
			{	if ( square [2] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else
		if (square[0] == square [3]  && square[3] == square[6] )
			{	if ( square [0] == 'X' )			
			return 1;
			else
			return 2; 
		}
	else 
		return 0;
	}


int mark(int player, int box)
{
    if ( square[box]=='X' || square[box]=='Y')
    return 0;
	if (player == 1 )
	{

		square[box] = 'X';
        return 1;
	}
	else
		square[box] = 'Y';
        return 1;
}

void display()
{
		for(int i=0;i<9;i++)
		{
			cout<< square[i] << "\t" ;
				if (i == 2 || i== 5 || i==8)
					cout<<"\n"; 
}
}






int main()
{
    
    // seting up the game // 






    //This is the sql conection for O
    

     // This is all data we wat //
    // For fifo conection & while loop //

    int fd;
    char*  myfifoO = "/tmp/myfifoO";
    char*  myfifoX = "/tmp/myfifoX";
    char buf[MAX_BUF];
    bool acceptable_actions = false;
    
    
    
    int i=0;
    int flag = 1;
    /* open, read, and display the message from the FIFO */
   // 
    while (i++<5){
    if(checkwin()==2){
        cout<<"Y WON !!!!\n";
        flag = 0 ;
        postgame(2);
        break;
    }
        
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

        // tsekarei ama nikaei kanenas kai ama nikaei 
        // to pernaei sto sql h draw 
    
        acceptable_actions = false;
    while(!acceptable_actions){
            
        // Opes the pipe to read the message

    fd = open(myfifoX, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Player 1 move: %s\n", buf);
    close(fd);
     if(mark(1,stoi(buf))){
         fd = open(myfifoX, O_WRONLY);
        write(fd, "Yes", sizeof("Yes"));
        close(fd);
        KeepData(stoi(buf));
         acceptable_actions = true;
         }else{
        fd = open(myfifoX, O_WRONLY);
        write(fd, "No", sizeof("No"));
        close(fd);
         }
    }

   
    if(checkwin()==1){
        cout<<"X WON !!!!\n";
        flag = 0;
       postgame(1);
        break;
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
     if(mark(2,stoi(buf))){
         fd = open(myfifoO, O_WRONLY);
        write(fd, "Yes", sizeof("Yes"));
        close(fd);
        KeepData(stoi(buf));
        acceptable_actions = true;
         }else{
        fd = open(myfifoO, O_WRONLY);
        write(fd, "No", sizeof("No"));
        close(fd); }
    }
    printf("\nEND OF ROUND\n");
    }

    if (flag){
    cout<<"NONE WONE \n";
     postgame(0);
    }
    display();
    PrintData();
std::string line; 
while (std::getline(std::cin, line))
{
    std::cout << line << std::endl;
}
    return 0;
}