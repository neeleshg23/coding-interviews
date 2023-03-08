CXX=g++
CFLAGS=-Wall -g -std=c++14
DEFS=-DDEBUG
FILE=lc2517

all: $(FILE).o

%: %.cpp
	$(CXX) $(CFLAGS) -o $*.o $*.cpp

$(FILE).o: $(FILE).cpp
	$(CXX) $(CFLAGS) $(DEFS) -o $(FILE).o $(FILE).cpp

clean:
	rm -f *.o
