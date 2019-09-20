OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11
#
# si se compila desde el linux de la FIB conviene usar g++-5 en lugar de g++
#
program.exe: program.o
				 g++ -o program.exe *.o $(OPCIONS)
#
program.o:
				 g++ -c *.cc $(OPCIONS)

#
practica:
				 tar -cvf practica.tar *.cc *.hh Makefile html.zip
				 
#
doxygen:
				doxygen Doxyfile && zip -r html.zip html

#
clean:
	rm -f *.o
	rm -f *.exe
	rm -f practica.tar
