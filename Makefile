CC=g++
CFLAGS=-I.
DEPS=solar.h

all: solar

solar: solar.o
	g++ solar.cpp -o solar.o 

