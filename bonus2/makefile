flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

heapsort.o : heapsort.cpp heapsort.h
	$(compile) $<

driver : driver.cpp heapsort.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver