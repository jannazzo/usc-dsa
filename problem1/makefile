flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

classify.o : classify.cpp classify.h
	$(compile) $<

driver : driver.cpp classify.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver