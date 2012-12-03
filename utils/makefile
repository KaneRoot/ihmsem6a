CC = g++
OPTIONS = -Wall
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
	$(CC) $(OPTIONS) -c fileutils.cpp -o fileutils.o

archive : 
	-@tar cvfz $(ARCHIVE).tar.gz *

debug : all
	valgrind $(VALGRIND_OPTIONS) ./$(PROG) 
	
clean : 
	rm -f *.o $(PROG) $(ARCHIVE).tar.gz
	
