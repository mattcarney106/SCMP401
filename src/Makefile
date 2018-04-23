USER= carneym

#Defining include directory, compiler, and flags for compiler
IDIR=../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11  -Wno-deprecated-declarations

#Defining libary directories
LIBDIR=/usr/local/lib

LIBS= -lmysqlcppconn

#Defining object directory
ODIR=obj

#Compiling Kara's code
#Determines all header files
_DEPS=site.h sites.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

#Determines list of obj files that will be created
_OBJ=TestDBquery.o site.o sites.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

all: TestDBquery solar

#Compiles all intermediate object files
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

#Makes final executible from all intermediate object files
TestDBquery: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

#Compiling my code
_DEPS=solar.h site.h sites.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=solar.o site.o sites.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

solar: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
