test :
	g++ ai_trainerO.cc
	gnome-terminal -e ./a.out
	g++ ai_trainerX.cc
	gnome-terminal -e ./a.out
open:
	g++ test_main.cc
	./a.out

	