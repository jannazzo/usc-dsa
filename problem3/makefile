flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

heap.o : heap.cpp heap.h
	$(compile) $<

driver : driver.cpp heap.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver