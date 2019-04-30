CFLAGS = -g -Wall -Werror -ansi

all: tower_defense


tower_defense: test.o #tower_defense.o main.o
	g++ -o tower_defense test.o #tower_defense.o main.o -lMLV -lm

#tower_defense.o: tower_defense.h tower_defense.cpp
#	g++ -o tower_defense.o -c tower_defense.cpp $(CFLAGS)

test.o:  test.cpp #tower_defense.h test.h
	g++ -o test.o -c test.cpp $(CFLAGS)

#main.o: main.cpp tower_defense.h test.h
#	g++ -o main.o -c main.cpp $(CFLAGS)



doc: Doxyfile *.cpp *.h
	doxygen Doxyfile

clean_all: clean clean_doc

clean:
	rm *.o tower_defense

clean_doc:
	rm -R html/

