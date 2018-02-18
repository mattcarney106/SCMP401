#Defining include directory, compiler, and flags for compiler
IDIR=../include
CC=g++
CFLAGS=-I$(IDIR)

#Defining object directory
ODIR=obj

#Determines all header files
_DEPS=solar.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#Determines list of obj files that will be created
_OBJ=solar.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

#Compiles all intermediate object files
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

#Makes final executible from all intermediate object files
solar: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

