gcc_options = -std=c++17 -Wall --pedantic-errors
GCC = g++

program : main.cpp all.h all.h.gch
	$(GCC) $(gcc_options) -include all.h -o $@ $<

all.h.gch : all.h
	$(GCC) $(gcc_options) -x c++-header -o $@ $<

run : program
	./program

clean :
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : rn clean
