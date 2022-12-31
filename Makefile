CXX=g++
CFLAGS=-Wall -g -std=c++20
DEFS=-DDEBUG
FILE=lc33

all: $(FILE).o

%: %.cpp
	$(CXX) $(CFLAGS) -o $*.o $*.cpp

$(FILE).o: $(FILE).cpp
	$(CXX) $(CFLAGS) $(DEFS) -o $(FILE).o $(FILE).cpp

clean:
	rm -f *.o
