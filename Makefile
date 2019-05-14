CC     = g++
CFLAGS = -Wall -Wextra -O2 -Wno-unused-result -g
LDFLAGS	= -lSDL -lSDL_image -lGLU -lGL -lm
LIB    = -lm
OBJ    = bin/main.o bin/Map.o bin/Path.o bin/Position.o bin/Entity.o bin/Tower.o bin/Building.o bin/Alien.o
RM     = rm -f
BIN    = bin/itd
DIRNAME = $(shell basename $$PWD)
BACKUP  = $(shell date +`basename $$PWD`-%m.%d.%H.%M.zip)
STDNAME = $(DIRNAME).zip

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(BIN) $(LDFLAGS)
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: $(BIN) "
	@echo "--------------------------------------------------------------"

bin/Map.o : include/Map.hpp src/Map.cpp
	@echo "compile monstre"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/Path.o : include/Path.hpp src/Path.cpp
	@echo "compile tableauMonstre"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/Position.o : include/Position.hpp src/Position.cpp
	@echo "compile tour"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/Entity.o : include/Entity.hpp src/Entity.cpp include/Position.hpp
	@echo "compile tableauTour"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/Tower.o : include/Tower.hpp src/Tower.cpp include/Entity.hpp
	@echo "compile carte"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/Building.o : include/Building.hpp src/Building.cpp include/Tower.hpp include/Entity.hpp
	@echo "compile image"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/Alien.o : include/Alien.hpp src/Alien.cpp include/Tower.hpp include/Entity.hpp include/Path.hpp
	@echo "compile sprites"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

bin/main.o : src/main.cpp bin/Map.o bin/Path.o bin/Position.o bin/Entity.o bin/Tower.o bin/Building.o bin/Alien.o
	@echo "compile main"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

clean :	
	@echo "**************************"
	@echo "CLEAN"
	@echo "**************************"
	$(RM) *~ $(OBJ) $(BIN)    

bigclean :
	@echo "**************************"
	@echo "BIG CLEAN"
	@echo "**************************"
	find . -name '*~' -exec rm -fv {} \;
	$(RM) *~ $(OBJ) $(BIN)

zip : clean 
	@echo "**************************"
	@echo "ZIP"
	@echo "**************************"
	cd .. && zip -r $(BACKUP) $(DIRNAME)