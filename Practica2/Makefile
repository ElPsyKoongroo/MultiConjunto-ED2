FLAGS = -Wall -Wextra -ggdb --std=c++17

cosito: practica2.cpp
ifeq ($(OS),Windows_NT)
	g++ $(FLAGS) ./practica2.cpp ./Wsrc/*.o -I ./includes/ -o main.exe
else
	g++ $(FLAGS) ./practica2.cpp ./Lsrc/*.o -I ./includes/ -o main.exe
endif

