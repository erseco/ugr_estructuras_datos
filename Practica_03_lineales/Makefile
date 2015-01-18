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
CPPFLAGS = -dynamiclib
else  #flags para linux
LDFLAGS =
CPPFLAGS = -Wall -g -c
endif

# TODO (sin empaquetado)
all: clean $(BIN)/usocolas $(BIN)/usopilas_max $(BIN)/usocolas_max

# COMPILACION
$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o
$(OBJ)/usocolas.o: $(INCLUDE)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INCLUDE)

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o
$(OBJ)/usopilas_max.o: $(INCLUDE)/pila_max.h $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp  -o $(OBJ)/usopilas_max.o -I$(INCLUDE) -I$(SRC)

$(BIN)/usocolas_max: $(OBJ)/usocolas_max.o
	$(CXX) -o $(BIN)/usocolas_max $(OBJ)/usocolas_max.o
$(OBJ)/usocolas_max.o: $(INCLUDE)/cola_max.h $(SRC)/usocolas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usocolas_max.cpp  -o $(OBJ)/usocolas_max.o -I$(INCLUDE) -I$(SRC)


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
	tar --exclude "*.tgz" --exclude "*.DS_Store" --exclude "*.pdf" --exclude "__MACOSX" --exclude datos -czvf ../$(shell basename "$(CURDIR)").tgz .

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
