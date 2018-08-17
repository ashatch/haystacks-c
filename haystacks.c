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

struct map_list_entry {
	char *uuidChars;
	struct map_list_entry *next;
};

struct map_entry {
	long key;
	struct map_list_entry *list;
};

long uuidPartLong(char *uuidChars, char *uuidPartBuffer) {
	memcpy(uuidPartBuffer, &uuidChars[0], UUID_BUCKET_LENGTH);
	uuidPartBuffer[UUID_BUCKET_LENGTH] = '\0';

	return strtol(uuidPartBuffer, NULL, BASE_16);
}

void processStdin(struct map_entry *needles, char *uuidPartBuffer) {
	size_t buflen = LINE_LENGTH;
	int stdinFilePointer = fileno(stdin);
	char *buf = calloc(sizeof(char), LINE_LENGTH);

	while ((read(stdinFilePointer, buf, LINE_LENGTH))) {
		long num = uuidPartLong(buf, uuidPartBuffer);
		if (needles[num].key == num) {
			fwrite(buf, LINE_LENGTH, 1, stdout);
		}		
	}	

	free(buf);
}

void addToList(char *uuid, struct map_list_entry *list) {
	//if (!list->next) {
		// list->uuidChars = calloc(sizeof(char), UUID_LENGTH + 1);
		// strncpy(list->uuidChars, uuid, 37);
		// list->uuidChars[36] = '\0';
		// list->next = NULL;
	//} else {
	//	printf("Adding to chain");
	//	struct map_list_entry *t = list->next;
		// long j = 0;
		// while (t->next != NULL) {
		// 	t = t->next;
		// 	// j++;
		// }
		// // printf("%lu", j);
		// addToList(uuid, t);
	//}
}

void loadNeedles(char *lineBuffer, struct map_entry *needles, FILE *needlesFile, char *uuidPartBuffer) {
	while (fread(lineBuffer, LINE_LENGTH, 1, needlesFile)) {			
		long num = uuidPartLong(lineBuffer, uuidPartBuffer);
		
		// copy key and uuid value to the struct
		//needles[num].key = num;

		// if (!needles[num].list) {			
		// 	needles[num].list = malloc(sizeof(struct map_list_entry));
		// 	needles[num].list->next = NULL;
		// }
		// addToList(lineBuffer, needles[num].list);
	}


	free(lineBuffer);
}

int main(int argc, char** argv) {	
	struct uuid* u = uuid_from_string("10ac8810-663c-4340-be23-7eecdcffc8ae");
	printf("%lld,%lld\n", u->msb, u->lsb);
	free(u);

	// map_t mymap;    
	// mymap = tracker_new();

	// FILE *needlesFile;

	// char *lineBuffer = malloc(sizeof(char) * LINE_LENGTH);
	// char *uuidPartBuffer = calloc(sizeof(char), UUID_BUCKET_CHAR_LENGTH);
	// struct map_entry *needles = NULL;//calloc(sizeof(struct map_entry), UUID_BUCKET_MAX_VALUE);

	// needlesFile = fopen(argv[NEEDLES_FILE_PARAM_INDEX], "r");
	// loadNeedles(lineBuffer, needles, needlesFile, uuidPartBuffer);
	// fclose(needlesFile);

	// //processStdin(needles, uuidPartBuffer);
	// free(needles);	
	// free(uuidPartBuffer);

}
