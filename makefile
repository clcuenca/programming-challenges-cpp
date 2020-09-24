COMPILER=g++
CPPFLAGS=-Wall -g -pedantic -pedantic-errors -std=c++11

the_trip:
	$(COMPILER) $(CPPFLAGS) -o TheTrip TheTrip.cpp

4367:
	$(COMPILER) $(CPPFLAGS) -o 4367 4367.cpp

clean:
	rm TheTrip