###############################################################################
#
# ED - Estructura de Datos
# Grado en Ingeniería Informática
#
# 2014 - Ernesto Serrano <erseco@correo.ugr.es>
# ---------------------------------------------
#
# Fichero Makefile para generacion de ejecutables, paquetes y documentacion
#
###############################################################################

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

# banderas para el enlazador
# Se indica directorios donde encontrar las funciontecas con -L. Usando -l seguido del
# nombre se indica la funcionteca que se desea enlazar.
OS := $(shell uname)
ifeq ($(OS),Darwin) #flags para MAC OS X
LDFLAGS =
CPPFLAGS =
else  #flags para linux
LDFLAGS =
CPPFLAGS = -Wall -g -c
endif

# TODO (sin empaquetado)
all: clean $(BIN)/pruebatraductor

# COMPILACION
$(BIN)/pruebatraductor : $(OBJ)/pruebatraductor.o $(LIB)/libtraductor.a
	$(CXX) -o $(BIN)/pruebatraductor $(OBJ)/pruebatraductor.o -I$(INCLUDE) -L$(LIB) -ltraductor

$(LIB)/libtraductor.a : $(OBJ)/traductor.o $(OBJ)/palabra.o
	ar rvs $(LIB)/libtraductor.a $(OBJ)/traductor.o $(OBJ)/palabra.o

$(OBJ)/palabra.o : $(SRC)/palabra.cpp
	$(CXX) $(CPPFLAGS) -c -o $(OBJ)/palabra.o $(SRC)/palabra.cpp -I$(INCLUDE)

$(OBJ)/traductor.o : $(SRC)/traductor.cpp $(OBJ)/palabra.o
	$(CXX) $(CPPFLAGS) -c -o $(OBJ)/traductor.o $(SRC)/traductor.cpp $(OBJ)/palabra.o -I$(INCLUDE)


$(OBJ)/pruebatraductor.o : $(SRC)/pruebatraductor.cpp $(OBJ)/traductor.o
	$(CXX) $(CPPFLAGS) -c -o $(OBJ)/pruebatraductor.o $(SRC)/pruebatraductor.cpp $(OBJ)/traductor.o $(OBJ)/palabra.o -I$(INCLUDE)



# DOCUMENTACION
# Genera la documentacion mediante doxygen en la carpeta doc
.PHONY: doc
doc:
	doxygen doc/doxys/Doxyfile

# EMPAQUETADO
# Genera el archivo .tgz de la práctica mediante la linea de comandos
# Omite los archivos propios de MacOSX y coge el nombre del directorio como nombre
.PHONY: package
package: clean
	@echo "Empaquetando..."
	tar --exclude "*.tgz" --exclude "*.DS_Store" --exclude "__MACOSX" --exclude datos -czvf ../$(shell basename "$(CURDIR)").tgz .

# LIMPEZA
# Limpia los archivos compilados, así como los archivos objeto y los paquetes zip
.PHONY: clean
clean:
	@echo "Limpiando..."
	@rm -f $(OBJ)/*\
        $(BIN)/*\
        $(DOC)/html/*\
        $(LIB)/*\
        ./*.tgz
