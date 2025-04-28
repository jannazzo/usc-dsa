flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

horspool.o : horspool.cpp horspool.h
	$(compile) $<

driver : driver.cpp horspool.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver