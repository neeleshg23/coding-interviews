CXX=g++
CFLAGS = -Wall -g -std=c++17

FILE=lc150

all: $(FILE).o

$(FILE).o: $(FILE).cpp
	$(CXX) $(CFLAGS) -o $(FILE).o $(FILE).cpp

clean:
	rm -f *.o
