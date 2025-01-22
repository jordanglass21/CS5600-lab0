
# variable to store the compiler name
CC := gcc

# variable to store the final executable file name
TARGETS := caesar queue ciphered_queue

# variable to store compilation flags 
# (-Wall: prints all compiler warnings)
CFLAGS := -Wall

# default executable
all: $(TARGETS)

# caesar executable
caesar: caesar.o caesar_main.o
	$(CC) $(CFLAGS) caesar.o caesar_main.o -o caesar

# compile caesar.o
caesar.o: caesar.c caesar.h
	$(CC) -c $(CFLAGS) caesar.c

# compile caesar_main.o
caesar_main.o: caesar_main.c caesar.h
	$(CC) -c $(CFLAGS) caesar_main.c

# queue executable
queue: queue.o queue_main.o
	$(CC) $(CFLAGS) queue.o queue_main.o -o queue

# compile queue.o
queue.o: queue.c queue.h
	$(CC) -c $(CFLAGS) queue.c

# compile queue_main.o
queue_main.o: queue_main.c queue.h
	$(CC) -c $(CFLAGS) queue_main.c

# compile ciphered_queue executable
ciphered_queue:  ciphered_queue_main.o queue.o caesar.o
	$(CC) $(CFLAGS) ciphered_queue_main.o queue.o caesar.o -o ciphered_queue

# compile ciphred_queue.o
# ciphered_queue.o: ciphered_queue.c queue.h caesar.h
#	$(CC) -c $(CFLAGS) ciphered_queue.c -o ciphered_queue.o

# compile queue_main.o
ciphered_queue_main.o: ciphered_queue_main.c queue.h caesar.h
	$(CC) -c $(CFLAGS) ciphered_queue_main.c -o ciphered_queue_main.o

# .PHONY: clean indicates that "clean" is just  not a target file to build. 
# We can use "make clean" command to delete object files and executable files to start
# the compilation fresh.
.PHONY: clean 
clean:
	rm -rf *.o $(TARGETS)
