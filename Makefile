CC      = gcc
CFLAGS  = -g
RM      = rm -rf

default: all

all: haystacks

haystacks: haystacks.c uuidtracker.c uuid.c
		$(CC) $(CFLAGS) -o haystacks haystacks.c uuidtracker.c uuid.c

clean veryclean:
		$(RM) haystacks haystacks.dSYM
