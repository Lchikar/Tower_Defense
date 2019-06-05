CC     = g++
CFLAGS = -Wall -Wextra -O2 -Wno-unused-result -g
LDFLAGS	= -lSDL -lSDL_image -lGLU -lGL -lglut -lm
LIB    = -lm
OBJ    = obj/main.o obj/texture.o obj/Button.o obj/IHM.o obj/Map.o obj/Position.o obj/Entity.o obj/Tower.o obj/Building.o obj/Alien.o obj/Graph.o obj/InGame.o
RM     = rm -f
BIN    = bin/itd
DIRNAME = $(shell basename $$PWD)
BACKUP  = $(shell date +`basename $$PWD`-%m.%d.%H.%M.zip)
STDNAME = $(DIRNAME).zip

all : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(BIN) $(LDFLAGS)
	@echo "--------------------------------------------------------------"
	@echo "            to execute type: $(BIN) data/testmap.itd"
	@echo "--------------------------------------------------------------"

obj/texture.o : src/texture.cpp
	@echo "compile texture"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Button.o : src/Button.cpp
	@echo "compile Button"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/IHM.o : src/IHM.cpp
	@echo "compile IHM"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Map.o : src/Map.cpp
	@echo "compile Map"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."


obj/Position.o : src/Position.cpp
	@echo "compile Position"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Entity.o : src/Entity.cpp
	@echo "compile Entity"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Tower.o : src/Tower.cpp
	@echo "compile Tower"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Building.o : src/Building.cpp
	@echo "compile Building"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Alien.o : src/Alien.cpp
	@echo "compile Alien"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/main.o : src/main.cpp
	@echo "compile main"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/Graph.o : src/Graph.cpp
	@echo "compile Graph"
	$(CC) $(CFLAGS) -c -o $@  $<
	@echo "done..."

obj/InGame.o : src/InGame.cpp
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