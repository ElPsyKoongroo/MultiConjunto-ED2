FLAGS   = -Wall -Wextra -std=c++17 -ggdb
SOURCES = ./sources
INCLUDES = ./includes

app: cartelera UsuarioP3.cpp
	g++ $(FLAGS) ./UsuarioP3.cpp cartelera.o -I $(INCLUDES) -o app.o

cartelera: $(SOURCES)/cartelera.cpp
	g++ $(FLAGS) -c $(SOURCES)/cartelera.cpp -I $(INCLUDES) -o cartelera.o
