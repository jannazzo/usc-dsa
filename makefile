
flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

sort.o : sort.cpp sort.h
	$(compile) $<

driver : driver.cpp sort.o
	$(link) $^

clean:
	rm *.o a.out