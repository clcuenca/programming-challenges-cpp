COMPILER=g++
CPPFLAGS=-Wall -g -pedantic -pedantic-errors -std=c++11

the_trip:
	$(COMPILER) $(CPPFLAGS) -o TheTrip TheTrip.cpp

clean:
	rm TheTrip