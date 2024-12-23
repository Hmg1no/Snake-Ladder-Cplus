CXX = g++
CXXFLAGS = -Wall -g

test: mytest.o snakes.o
	$(CXX) $(CXXFLAGS) mytest.o snakes.o -o test

mytest.o: mytest.cpp snakes.h
	$(CXX) $(CXXFLAGS) -c mytest.cpp

snakes.o: snakes.cpp snakes.h
	$(CXX) $(CXXFLAGS) -c snakes.cpp

clean:
	rm -f *.o
	rm -f test
	rm -f *~

run: test
	./test

val: test
	valgrind ./test

val1:
	valgrind --track-origins=yes ./test

leak:
	valgrind --leak-check=full ./test



