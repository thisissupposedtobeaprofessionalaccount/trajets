NOM_APP = trajets
EDL = g++
COMP = g++
EDL_OPTS = -ansi -pedantic -Wall -std=c++11 -g
COMP_OPTS = -ansi -pedantic -Wall -std=c++11 -c -g 
SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
INT = $(SRC_DIR)Trajet.h $(SRC_DIR)TrajetSimple.h $(SRC_DIR)TrajetCompose.h $(SRC_DIR)Catalogue.h $(SRC_DIR)Cell.h $(SRC_DIR)ListeChainee.h $(SRC_DIR)MoyenTransport.h


REAL = $(INT:.h=.cpp) $(SRC_DIR)main.cpp
OBJ = $(REAL:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

$(BIN_DIR)$(NOM_APP) : $(OBJ) 
	$(EDL) $(EDL_OPTS) -o $(BIN_DIR)$(NOM_APP) $(OBJ) 

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp $(SRC_DIR)%.h
	$(COMP) $(COMP_OPTS) $< -o $@

# main n'a pas de .h, règle spécifique
$(OBJ_DIR)main.o : $(SRC_DIR)main.cpp
	$(COMP) $(COMP_OPTS) $< -o $@

clean : 
	rm -rf $(BIN_DIR)* $(OBJ_DIR)*

