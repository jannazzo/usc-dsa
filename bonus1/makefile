flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

boyermoore.o : boyermoore.cpp boyermoore.h
	$(compile) $<

driver : driver.cpp boyermoore.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver