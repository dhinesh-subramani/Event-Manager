# eventmanager: visitor.c employee.c receptionist.c
# 	gcc -o eventmanager visitor.c employee.c receptionist.c -I../include

IDR = ../include

BINS = ../bin

CC = gcc

CFGS = -I$(IDR)

_LIBS = receptionist.h employee.h visitor.h
LIBS = $(patsubst %,$(IDR)/%,$(_LIBS))

_OBJ = receptionist.o employee.o visitor.o 
OBJ = $(patsubst %,$(BINS)/%,$(_OBJ))

$(BINS)/%.o: %.c $(LIBS)
	$(CC) -c -o $@ $< $(CFGS)

$(BINS)/main: $(OBJ)
	$(CC) -o $@ $^ $(CFGS) 

