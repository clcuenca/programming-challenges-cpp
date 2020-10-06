COMPILER=g++
CPPFLAGS=-Wall -g -pedantic -pedantic-errors -std=c++11

thetrip:
	$(COMPILER) $(CPPFLAGS) -o thetrip thetrip.cpp

4367:
	$(COMPILER) $(CPPFLAGS) -o 4367 4367.cpp

7794:
	$(COMPILER) $(CPPFLAGS) -o 7794 7794.cpp

7795:
	$(COMPILER) $(CPPFLAGS) -o 7795 7795.cpp

clean:
	rm thetrip
	rm 7794
	rm 4367