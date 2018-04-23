/*
*	Logan Thomas
*	Programming Language Paradigms
*	Assignment 3
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Assignment3.h"

int main(int argc, char *argv[]) {
	int nLines = N;
	int nBytes = 0;
	int options = 0;
	
	size_t numFiles = argc - 1;
	char** fileNames = calloc(numFiles, sizeof(char*));
	int currFile = 0;

	for (int i = 1; i < argc; i++){
		if (getNumber(argv[i], &options, &nLines, &nBytes)) {numFiles--; continue;}

		if (compareOption(argv[i], NUM_LINES, &options)) { numFiles--; continue; }
		if (compareOption(argv[i], NUM_BYTES, &options)) { numFiles--; continue; }
		

		addStringToArray(fileNames, currFile, argv[i]);
		currFile++;
	}

	fileNames = realloc(fileNames, numFiles * sizeof(char*));

	printFiles(fileNames, numFiles, nLines, nBytes);

	free2D(fileNames, numFiles);
}

void setBits(int *dest, Options mask){ *dest = *dest | mask; }
void clearBits(int *dest, Options mask){ *dest = *dest & ~mask; }

BOOL getNumber(char argv[], int *options, int *nLines, int *nBytes){
	Options op;
	int errVal;
	
		switch (*options){
			case fNUM_LINES:
				errVal = sscanf(argv, "%d", nLines);
				op = fNUM_LINES;
				break;
			case fNUM_BYTES:
				errVal = sscanf(argv, "%d", nBytes);
				op = fNUM_BYTES;
				break;
			default:
				return FALSE;
		}

	clearBits(options, op);
	return errVal;
}
BOOL compareOption(char argv[], char option[], int *options){
	Options op;
	if (!strcmp(option, NUM_LINES)) { op = fNUM_LINES; }
	else if (!strcmp(option, NUM_BYTES)) { op = fNUM_BYTES; }
	else { return FALSE; }

	if (!strcmp(argv, option)) {
		setBits(options, op);
		return TRUE;
	}
	return FALSE;if (!strcmp(argv, option)) {
		setBits(options, op);
		return TRUE;
	}
	return FALSE;
}
void addStringToArray(char **array, int pos, char src[]){
	array[pos] = calloc(strlen(src) + 1, sizeof(char));
	strcpy(array[pos], src);
}

void printFiles(char **fileNames, size_t numFiles, size_t numLines, size_t numBytes){
	FILE *fPtr;

	for (int i = 0; i < numFiles; i++){
		if ((fPtr = fopen(fileNames[i], "r")) == NULL) { printf("Error opening file %s\n", fileNames[i]); continue; }

		printf("%s:\n",fileNames[i]);
		
		printLines(fPtr, numLines);
		printBytes(fPtr, numBytes);

		printf("\n\n\n");

		fclose(fPtr);
	}
}
void printLines(FILE *fPtr, size_t numLines){
	if (fPtr == NULL) { return; }

	char currLine[buffSize];

	printf("Printing %ld Lines...\n", numLines);

	fseek(fPtr, 0, SEEK_SET);
	for (int j = 0; j < numLines; j++){
		fgets(currLine, buffSize, fPtr);
		printf("%s", currLine);
		if (feof(fPtr)) { break; }
	}
}
void printBytes(FILE *fPtr, size_t numBytes){
	if (fPtr == NULL) { return; }

	char currByte;

	printf("\n\nPrinting %ld Characters...\n", numBytes);
	
	fseek(fPtr, 0, SEEK_SET);
	for (int j = 0; j < numBytes; j++){
		currByte = (char)fgetc(fPtr);
		printf("%c", currByte);
		if (feof(fPtr)) { break; }
	}
}

void free2D(char **array, size_t numRows){
	for (int i = 0; i < numRows; i++){
		free(array[i]);
	}
	free(array);
}