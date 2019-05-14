CC     = g++
CFLAGS = -Wall -Wextra -O2 -Wno-unused-result -g
LDFLAGS	= -lSDL -lSDL_image -lGLU -lGL -lm
LIB    = -lm
OBJ    = obj/main.o obj/texture.o obj/Map.o obj/Path.o obj/Position.o obj/Entity.o obj/Tower.o obj/Building.o obj/Alien.o
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

obj/texture.o : include/texture.hpp src/texture.cpp
	@echo "compile texture"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Map.o : include/Map.hpp src/Map.cpp include/texture.hpp
	@echo "compile Map"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Path.o : include/Path.hpp src/Path.cpp
	@echo "compile Path"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Position.o : include/Position.hpp src/Position.cpp
	@echo "compile Position"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Entity.o : include/Entity.hpp src/Entity.cpp include/Position.hpp
	@echo "compile Entity"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Tower.o : include/Tower.hpp src/Tower.cpp include/Entity.hpp
	@echo "compile Tower"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Building.o : include/Building.hpp src/Building.cpp include/Tower.hpp include/Entity.hpp
	@echo "compile Building"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/Alien.o : include/Alien.hpp src/Alien.cpp include/Tower.hpp include/Entity.hpp include/Path.hpp
	@echo "compile Alien"
	$(CC) $(CFLAGS) -c $<  
	@echo "done..."

obj/main.o : src/main.cpp obj/texture.o obj/Map.o obj/Path.o obj/Position.o obj/Entity.o obj/Tower.o obj/Building.o obj/Alien.o
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