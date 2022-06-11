test :
	g++ ai_trainerO.cc
	gnome-terminal -e ./a.out
	g++ ai_trainerX.cc
	gnome-terminal -e ./a.out
	g++ Main.cc -l sqlite3
	gnome-terminal -e ./a.out

db : 
	g++ MakeDB.cc -l sqlite3
	gnome-terminal -e ./a.out

data : 
	g++ MakeDB.cc -l sqlite3
	./a.out


	