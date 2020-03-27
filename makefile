CC=gcc
#CC=ccomp
CFLAGS=-O3 -I/usr/include  -I/usr/include/x86_64-linux-gnu

CFILES = $(wildcard *.c)
LDIR =../lib

LIBS=-lm

DEPS = $(wildcard *.h)

OBJ = $(CFILES:%.c=%.o)


main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~

t:
	echo $(CFILES)
	echo $(OBJ)
