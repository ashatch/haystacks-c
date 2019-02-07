#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "dict.h"


#define NEEDLES_FILE_PARAM_INDEX 1
#define UUID_LENGTH 36
#define NEWLINE_LENGTH 1
#define LINE_LENGTH (UUID_LENGTH + NEWLINE_LENGTH)


void loadNeedles(FILE *needlesFile, Dict *dict) {
  char *buf = calloc(sizeof(char), LINE_LENGTH);
	while (fread(buf, LINE_LENGTH, 1, needlesFile)) {			
    DictInsert(*dict, buf, "");
	}
}

void processStdin(Dict *dict) {
	size_t buflen = LINE_LENGTH;
	int stdinFilePointer = fileno(stdin);
	char *buf = calloc(sizeof(char), LINE_LENGTH);

	while ((read(stdinFilePointer, buf, LINE_LENGTH))) {
      if (DictSearch(*dict, buf) != 0) {
        fwrite(buf, LINE_LENGTH, 1, stdout);
      }
	}

	free(buf);
}

int main(int argc, char** argv)
{
    Dict dictionary;
    dictionary = DictCreate();

    FILE *needlesFile;
    needlesFile = fopen(argv[NEEDLES_FILE_PARAM_INDEX], "r");
    loadNeedles(needlesFile, &dictionary);   
    fclose(needlesFile);

    processStdin(&dictionary);

    return 0;
}
