flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

floyd.o : floyd.cpp floyd.h
	$(compile) $<

driver : driver.cpp floyd.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver