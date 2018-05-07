/*
*	Logan Thomas
*	Programming Language Paradigms
*	Assignment 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assignment4.h"

int main(int argc, char *argv[]){
	BOOL DEBUG = FALSE;
	int options = fERROR;

	size_t numFiles = argc - 1;
	char** files;
	int currentFile = 0;

	// Preliminary loop through args to get options and determine debug mode
	for (int i = 1; i < argc; i++){
		// Get options
		if (getOption(argv[i], &options)) {numFiles--; continue;}
	}
	// Set debug mode
	DEBUG = maskBits(options, fDEBUG) ? TRUE : FALSE;
	
	// Print debug info
	if (DEBUG) { 
		printf("Number of args: %d\n", argc - 1);
		printf("Number of files: %ld\n", numFiles);
		printOptions(options);
	}

	// Allocate memory for files array
	if((files = calloc(numFiles, sizeof(char*))) == NULL) { perror("calloc"); return EXIT_FAILURE; }
	
	// Secondary loop through args to get file names
	for (int i = 1; i < argc; i++){
		if (!getOption(argv[i], &options)) {
			// Print debug info
			if (DEBUG) { printf("File name found: %s;\tcurrentFile: %d\n", argv[i], currentFile); }
			// Add file name to files array
			if (addStringToArray(files, &currentFile, argv[i]) == FALSE) {perror("calloc"); return EXIT_FAILURE; }
		}
	}
	
	// Print debug information
	if (DEBUG) { printFileNames(files, numFiles); }

	free2D(files, numFiles);
	return EXIT_SUCCESS;
}

// Bit manipulation
void setBits(int *dest, Options mask){ *dest = *dest | mask; }
void clearBits(int *dest, Options mask){ *dest = *dest & ~mask; }
BOOL maskBits(int options, Options mask){ return options & mask; }

// Arg parsing
BOOL getOption(char arg[], int *options){
	if (!strcmp(arg, DEBUG_OPTION)) {
		setBits(options, fDEBUG);
		return TRUE;
	}
	else if (!strcmp(arg, APPEND_OPTION)) {
		setBits(options, fAPPEND);
		return TRUE;
	}
	else { return FALSE; }
}
BOOL addStringToArray(char **array, int *pos, char src[]){
	if ((array[*pos] = calloc(strlen(src) + 1, sizeof(char))) == NULL) { return FALSE; }
	strcpy(array[*pos], src);
	*pos += 1;
	return TRUE;
}

// Printing
void printFileNames(char **files, size_t numFiles){
	if (numFiles > 0) {
		printf("\nFiles provided:\n");
		for (int i = 0; i < numFiles; i++) {
			printf("%s\n", files[i]);
		}
	} else {
		printf("No filenames provided.\n");
	}
}
void printOptions(int options){
	printf("Options: Debug");
	if (maskBits(options, fAPPEND)) { printf(", Append\n\n"); }
	else { printf("\n\n"); }
}

// Freeing memory
void free2D(char **array, size_t numRows){
	for (int i = 0; i < numRows; i++){
		free(array[i]);
	}
	free(array);
}