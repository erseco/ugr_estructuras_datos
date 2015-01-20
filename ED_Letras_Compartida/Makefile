
# VARIABLES
BIN 	= bin
SRC 	= src
OBJ 	= obj
LIB 	= lib
DOC 	= doc
INCLUDE = include

# Definición de compiladores
CXX = g++ -Ofast
CC = gcc -Ofast


LDFLAGS =
CPPFLAGS = -Wall -g -c

# Colección de objetos a compilar
OBJECTS = testdiccionario testarbol

# TODO (sin empaquetado)
all: $(OBJECTS)


# COMPILACION (asi de chulo)
$(OBJECTS):
	$(CXX) -o $(BIN)/$@ $(SRC)/$@.cpp -I$(INCLUDE) $(LDFLAGS)

