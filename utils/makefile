CC = g++
OPTIONS = -Wall -I /users/info/il3/pittoli/repos/boost/boost_1_52_0 -L /users/info/il3/pittoli/repos/boost/boost_1_52_0/stage/lib/
ARCHIVE = pittoli_hett
PROG = main
VALGRIND_OPTIONS = --leak-check=full -v

all : $(PROG)

$(PROG) : planning.o user.o salle.o type.o horaire.o film.o fileutils.o test.o 
	$(CC) -o $(PROG) planning.o user.o salle.o type.o horaire.o film.o fileutils.o test.o $(OPTIONS)

%.o : %.cpp %.h
	$(CC) -o $@ -c $< $(OPTIONS)


main.o : main.cpp
	$(CC) $(OPTIONS) -c main.cpp -o main.o

test.o : test.cpp
	$(CC) $(OPTIONS) -c test.cpp -o test.o

fileutils.o : fileutils.h fileutils.cpp
	$(CC) -c fileutils.cpp -o fileutils.o $(OPTIONS) 

archive : 
	-@tar cvfz $(ARCHIVE).tar.gz *

debug : all
	valgrind $(VALGRIND_OPTIONS) ./$(PROG) 
	
clean : 
	rm -f *.o $(PROG) $(ARCHIVE).tar.gz
	
