all: vectorSplit converter 

vectorSplit: vectorSplit.cpp
	g++ vectorSplit.cpp -o vectorSplit -std=c++11 -Wall

converter: converter.cpp
	g++ converter.cpp -o converter

clean:
	rm -f *.o vectorSplit converter
