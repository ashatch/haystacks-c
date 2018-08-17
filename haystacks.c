#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "uuid.h"
#include "uuidtracker.h"

#define NEEDLES_FILE_PARAM_INDEX 2

#define NEWLINE_LENGTH 1
#define NULL_TERMINATOR_CHAR_LENGTH 1
#define BASE_16 16

#define UUID_LENGTH 36
#define UUID_BUCKET_LENGTH 8
#define UUID_BUCKET_CHAR_LENGTH (UUID_BUCKET_LENGTH + NULL_TERMINATOR_CHAR_LENGTH)
#define UUID_BUCKET_MAX_VALUE 4294967295

#define LINE_LENGTH (UUID_LENGTH + NEWLINE_LENGTH)

// void processStdin(struct map_entry *needles, char *uuidPartBuffer) {
// 	size_t buflen = LINE_LENGTH;
// 	int stdinFilePointer = fileno(stdin);
// 	char *buf = calloc(sizeof(char), LINE_LENGTH);

// 	while ((read(stdinFilePointer, buf, LINE_LENGTH))) {
// 		long num = uuidPartLong(buf, uuidPartBuffer);
// 		if (needles[num].key == num) {
// 			fwrite(buf, LINE_LENGTH, 1, stdout);
// 		}		
// 	}	

// 	free(buf);
// }

struct _blackboard {
	struct node *tree;
	char *lineBuffer;
} blackboard;

struct node {
	struct node *leaves;
};

void loadNeedles(FILE *needlesFile) {
	while (fread(blackboard.lineBuffer, LINE_LENGTH, 1, needlesFile)) {			
		struct uuid* u = uuid_from_string(blackboard.lineBuffer);
		free(u);
	}	
}

int main(int argc, char** argv) {	
	int sizeOfChunks = 1 << 16;
	
	blackboard.lineBuffer = malloc(sizeof(char) * LINE_LENGTH);
	blackboard.tree = malloc(sizeof(struct node) * sizeOfChunks);

	FILE *needlesFile;
	needlesFile = fopen(argv[NEEDLES_FILE_PARAM_INDEX], "r");
	loadNeedles(needlesFile);
	
	fclose(needlesFile);
	free(blackboard.lineBuffer);
	free(blackboard.tree);

	// //processStdin(needles, uuidPartBuffer);
}

/*

find a large collection of sparsely populated collection of 128-bit data items

expected needles size: 24-bit -> 16M

idea: array size 65k on first 16-bits


split 128-bit into 16-bit segments; arrange into tree.


*/

