flags = -std=c++17 -Wall
compile = g++ $(flags) -c
link = g++ $(flags)

tests.o : tests.cpp tests.h
	$(compile) $<

classify.o : classify.cpp classify.h
	$(compile) $<

sort.o : sort.cpp sort.h
	$(compile) $<

heap.o : heap.cpp heap.h
	$(compile) $<

driver : driver.cpp tests.o classify.o sort.o heap.o
	$(link) $^ -o driver

clean:
	rm *.o input.txt output.txt driver