test :
	g++ ai_trainerO.cc
	gnome-terminal -e ./a.out
	g++ ai_trainerX.cc
	gnome-terminal -e ./a.out
	g++ test_main.cc -l sqlite3
	gnome-terminal -e ./a.out

	