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
	int options = fNUM_LINES;
	
	size_t numFiles = argc - 1;
	char** fileNames = calloc(numFiles, sizeof(char*));
	int currFile = 0;

	for (int i = 1; i < argc; i++){
		if (getOptionValue(argv[i], &options, &nLines, &nBytes)) { numFiles--; continue; }

		if (getOption(argv[i], &options)) { numFiles--; continue; }
		
		addStringToArray(fileNames, currFile, argv[i]);
		currFile++;
	}

	fileNames = realloc(fileNames, numFiles * sizeof(char*));

	printFiles(fileNames, numFiles, options, nLines, nBytes);

	free2D(fileNames, numFiles);
}

void setBits(int *dest, Options mask){ *dest = *dest | mask; }
void clearBits(int *dest, Options mask){ *dest = *dest & ~mask; }
BOOL maskBits(int options, Options mask){ return options & mask; }

BOOL getOptionValue(char argv[], int *options, int *nLines, int *nBytes){
	int errVal;

	if (maskBits(*options, fSET_NUM_LINES)) {
		errVal = errVal = sscanf(argv, "%d", nLines);
		clearBits(options, fSET_NUM_LINES);
		return errVal;
	}
	else if (maskBits(*options, fSET_NUM_BYTES)) {
		errVal = errVal = sscanf(argv, "%d", nBytes);
		clearBits(options, fSET_NUM_BYTES);
		return errVal;
	}
	else { return FALSE; }
}
BOOL getOption(char argv[], int *options){
	if (!strcmp(argv, NUM_LINES)) {
		setBits(options, fSET_NUM_LINES);
		setBits(options, fNUM_LINES);
		clearBits(options, fNUM_BYTES);
		return TRUE;
	}
	else if (!strcmp(argv, NUM_BYTES)) {
		setBits(options, fSET_NUM_BYTES);
		setBits(options, fNUM_BYTES);
		clearBits(options, fNUM_LINES);
		return TRUE;
	}
	else { return FALSE; }
}
void addStringToArray(char **array, int pos, char src[]){
	array[pos] = calloc(strlen(src) + 1, sizeof(char));
	strcpy(array[pos], src);
}

void printFiles(char **fileNames, size_t numFiles, int options, size_t numLines, size_t numBytes){
	FILE *fPtr;

	for (int i = 0; i < numFiles; i++){
		if ((fPtr = fopen(fileNames[i], "r")) == NULL) { printf("Error opening file %s\n", fileNames[i]); continue; }

		if (numFiles > 1){
			printf("===>\t%s\t<===:\n",fileNames[i]);
		}
		
		if (maskBits(options, fNUM_LINES)){ printLines(fPtr, numLines); }
		else if (maskBits(options, fNUM_BYTES)){ printBytes(fPtr, numBytes); }

		printf("\n\n\n");

		fclose(fPtr);
	}
}
void printLines(FILE *fPtr, size_t numLines){
	if (fPtr == NULL) { return; }

	char currLine[buffSize];

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