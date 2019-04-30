CFLAGS = -g -Wall -Werror -ansi

all: bin/itd


bin/itd: bin/itd.o bin/main.o bin/Map.o bin/Path.o bin/Position.o bin/Entity.o bin/Tower.o bin/Building.o bin/Alien.o
	g++ -o bin/itd bin/itd.o #tower_defense.o main.o -lMLV -lm

#tower_defense.o: tower_defense.h tower_defense.cpp
#	g++ -o tower_defense.o -c tower_defense.cpp $(CFLAGS)

#test.o:  test.cpp #tower_defense.h test.h
#	g++ -o test.o -c test.cpp $(CFLAGS)


bin/Map.o: include/Map.hpp src/Map.cpp
	g++ -o bin/Map.o -c src/Map.cpp $(CFLAGS)

bin/Path.o: include/Path.hpp src/Path.cpp
	g++ -o bin/Path.o -c src/Path.cpp $(CFLAGS)	

bin/Position.o: include/Position.hpp src/Position.cpp
	g++ -o bin/Position.o -c src/Position.cpp $(CFLAGS)

bin/Entity.o: include/Entity.hpp src/Entity.cpp include/Position.hpp
	g++ -o bin/Entity.o -c src/Entity.cpp $(CFLAGS)	

bin/Tower.o: include/Tower.hpp src/Tower.cpp include/Entity.hpp
	g++ -o bin/Tower.o -c src/Tower.cpp $(CFLAGS)

bin/Building.o: include/Building.hpp src/Building.cpp include/Tower.hpp include/Entity.hpp
	g++ -o bin/Building.o -c src/Building.cpp $(CFLAGS)	

bin/Alien.o: include/Alien.hpp src/Alien.cpp include/Tower.hpp include/Entity.hpp include/Path.hpp
	g++ -o bin/Alien.o -c src/Alien.cpp $(CFLAGS)	

bin/main.o: src/main.cpp include/Entity.hpp include/Map.hpp include/Building.hpp include/Path.hpp include/Alien.hpp include/Position.hpp 
	g++ -o bin/main.o -c src/main.cpp $(CFLAGS)



doc: Doxyfile *.cpp *.hpp
	doxygen Doxyfile

clean_all: clean clean_doc

clean:
	rm *.o bin/itd

clean_doc:
	rm -R html/

