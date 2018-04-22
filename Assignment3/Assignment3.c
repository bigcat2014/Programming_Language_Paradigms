/*
*	Logan Thomas
*	Programming Language Paradigms
*	Assignment 3
*/

#define N 10

#define NUM_LINES "-n"
#define NUM_BYTES "-c"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Assignment3.h"

int main(int argc, char *argv[]) {
	int nLines = N;
	int nBytes = 0;
	int options = 0;
	int errVal;
	
	size_t numFiles = argc - 1;
	char** fileNames = calloc(numFiles, sizeof(char*));
	int currFile = 0;

	for (int i = 1; i < argc; i++){
		switch (options){
			case fNUM_LINES:
				errVal = sscanf(argv[i], "%d", &nLines);
				clearBits(&options, fNUM_LINES);
				if (errVal) {numFiles--; continue;}
				break;
			case fNUM_BYTES:
				errVal = sscanf(argv[i], "%d", &nBytes);
				clearBits(&options, fNUM_BYTES);
				if (errVal) {numFiles--; continue;}
				break;
		}

		if (!strcmp(argv[i], NUM_LINES)) {
			setBits(&options, fNUM_LINES);
			numFiles--;
			continue;
		}
		if (!strcmp(argv[i], NUM_BYTES)) {
			setBits(&options, fNUM_BYTES);
			numFiles--;
			continue;
		}

		fileNames[currFile] = calloc(strlen(argv[i]) + 1, sizeof(char));
		strcpy(fileNames[currFile], argv[i]);
		currFile++;
	}

	fileNames = realloc(fileNames, numFiles * sizeof(char*));

	printf("File names:\n");
	for (int i = 0; i < numFiles; i++){
		printf("%s\n",fileNames[i]);
	}

	printf("\nNumber of lines: %d\n", nLines);
	printf("Number of bytes: %d\n", nBytes);

	free2D(fileNames, numFiles);
}

void setBits(int *dest, Options mask){ *dest = *dest | mask; }
void clearBits(int *dest, Options mask){ *dest = *dest & ~mask; }
void free2D(char **array, size_t numRows){
	for (int i = 0; i < numRows; i++){
		free(array[i]);
	}
	free(array);
}