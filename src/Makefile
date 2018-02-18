IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

#Defining object directory
ODIR=obj

#Determines all header files (?)
_DEPS=solar.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#Determines list of obj files that will be created (?)
_OBJ=solar.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< -I. 

solar: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

