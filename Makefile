CC=g++
CFLAGS=-I.
DEPS=solar.h

# Says that all .o files depend on header and cpp files.
# This means that if a cpp or h file changes, the object file must be recompiled.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< -I. 

all: solar

solar: solar.o
	$(CC) solar.cpp -o solar.o 

