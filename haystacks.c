#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "dict.h"

#define NEEDLES_FILE_PARAM_INDEX 1
#define MAX_LINE_LENGTH 48

inline void loadNeedles(FILE *needlesFile, Dict *dict) {
  char *buf = calloc(sizeof(char), MAX_LINE_LENGTH);
	while (fgets(buf, MAX_LINE_LENGTH, needlesFile)) {
    DictInsert(*dict, buf, "");
	}

  free(buf);
}

inline void processStdin(Dict *dict) {
	char *buf = calloc(sizeof(char), MAX_LINE_LENGTH);

	while (fgets(buf, MAX_LINE_LENGTH, stdin) != NULL) {
      if (DictSearch(*dict, buf) != 0) {
        fwrite(buf, MAX_LINE_LENGTH, 1, stdout);
        DictDelete(*dict, buf);
      }
	}

	free(buf);
}

int main(int argc, char** argv)
{
    setvbuf(stdin,(char*)NULL,_IOFBF,0);
 
    Dict dictionary;
    dictionary = DictCreate();

    FILE *needlesFile;
    needlesFile = fopen(argv[NEEDLES_FILE_PARAM_INDEX], "r");
    loadNeedles(needlesFile, &dictionary);   
    // fclose(needlesFile);

    processStdin(&dictionary);

    return 0;
}
