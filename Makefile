CC      = gcc
CFLAGS  = -g
RM      = rm -rf

default: all

all: dict_test

dict_test: dict_test.c dict.c
	$(CC) $(CFLAGS) -o dict_test dict_test.c dict.c

# all: haystacks

# haystacks: haystacks.c uuidtracker.c uuid.c murmur3.c
# 		$(CC) $(CFLAGS) -o haystacks haystacks.c uuidtracker.c uuid.c murmur3.c

# clean veryclean:
# 		$(RM) haystacks haystacks.dSYM
