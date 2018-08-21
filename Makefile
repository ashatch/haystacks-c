CC      = gcc
CFLAGS  = -g
RM      = rm -rf

default: all

all: haystacks

haystacks: haystacks.c uuidtracker.c uuid.c murmur3.c
		$(CC) $(CFLAGS) -o haystacks haystacks.c uuidtracker.c uuid.c murmur3.c

clean veryclean:
		$(RM) haystacks haystacks.dSYM
