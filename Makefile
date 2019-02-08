CC      = clang
CFLAGS  = -g -Ofast
RM      = rm -rf

default: all

all: haystacks

haystacks: haystacks.c dict.c
	$(CC) $(CFLAGS) -o haystacks haystacks.c dict.c

clean veryclean:
		$(RM) haystacks haystacks.dSYM
