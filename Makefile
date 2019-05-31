CC     = g++
CFLAGS = -Wall -Wextra -O2 -Wno-unused-result -g
LDFLAGS	= -lSDL -lSDL_image -lGLU -lGL -lm
LIB    = -lm
OBJ    = bin/main.o bin/texture.o bin/Button.o bin/IHM.o bin/Map.o bin/Path.o bin/Position.o bin/Entity.o bin/Tower.o bin/Building.o bin/Alien.o bin/Graph.o bin/InGame.o
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

bin/texture.o : src/texture.cpp
	@echo "compile texture"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Button.o : src/Button.cpp
	@echo "compile Button"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/IHM.o : src/IHM.cpp
	@echo "compile IHM"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Map.o : src/Map.cpp
	@echo "compile Map"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Path.o : src/Path.cpp
	@echo "compile Path"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Position.o : src/Position.cpp
	@echo "compile Position"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Entity.o : src/Entity.cpp
	@echo "compile Entity"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Tower.o : src/Tower.cpp
	@echo "compile Tower"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Building.o : src/Building.cpp
	@echo "compile Building"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Alien.o : src/Alien.cpp
	@echo "compile Alien"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/main.o : src/main.cpp
	@echo "compile main"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/Graph.o : src/Graph.cpp
	@echo "compile Graph"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

bin/InGame.o : src/InGame.cpp
	@echo "compile InGame"
	$(CC) $(CFLAGS) -c -o $@  $<
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