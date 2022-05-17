FLAGS = -Wall -Wextra -ggdb --std=c++17



cosito: practica4.cpp
ifeq ($(OS),Windows_NT)
	g++ $(FLAGS) ./practica4.cpp ./Wsrc/*.o -I ./inc/ -o main.exe
else
	g++ $(FLAGS) ./practica4.cpp ./Lsrc/*.o -I ./inc/ -o main.exe
endif

