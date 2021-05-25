# Joseph Larson - gha3bn - 3/29/2021 - Makefile

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-O2
DEBUG=-g

make: HashTable.o wordPuzzle.o timer.o
	$(CXX) HashTable.o wordPuzzle.o timer.o

HashTable.o: HashTable.cpp timer.h

timer.o: timer.cpp

wordPuzzle.o: wordPuzzle.cpp HashTable.h timer.h
