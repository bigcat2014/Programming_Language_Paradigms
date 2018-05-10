/*
*	Logan Thomas
*	Programming Language Paradigms
*	Assignment 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Assignment4.h"

BOOL DEBUG = FALSE;

int main(int argc, char *argv[]){
	int options = fERROR;

	size_t numFiles = argc - 1;
	char** files;
	int currentFile = 0;

	char *input;

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

	// Read the standard input into the buffer
	if (readInput(&input) == FALSE) { return EXIT_FAILURE; }

	// Print the input to stdout
	printf("%s\n", input);
	
	// Print debug information
	if (DEBUG) { printFileNames(files, numFiles); }

	free(input);
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

// Read stdin into the buffer provided
BOOL readInput(char **buffer){
	size_t buffSize = BUFSIZ;
	size_t length = 0;
	char character;

	// Allocate memory for the buffer
	if ((*buffer = calloc(buffSize, sizeof(char))) == NULL) { perror("malloc"); return FALSE; }

	while(TRUE){
		// Print debug information
		if (DEBUG && length % 1000 == 0) { 
			printf("\nReading...\n");
			printf("Buffer size: %ld\n", buffSize);
			printf("Length %ld\n", length);
		}

		// Get the next character from stdin
		character = fgetc(stdin);
		// If it is the end of the file or fgetc returns NULL, break
		if (feof(stdin) || character == NULL) { break; }

		// Add the character to the buffer
		(*buffer)[length++] = character;

		// If the next index is outside of the allocated memory, reallocate more memory
		if (length >= buffSize) {
			// Print debug information
			if (DEBUG) { printf("\nToo many bytes. Reallocating...\n"); }

			// Double the size of the buffer
			buffSize *= 2;
			// Reallocate the new amount of memory
			if ((*buffer = realloc(*buffer, buffSize * sizeof(char))) == NULL) { perror("realloc"); return FALSE; }

			// Print debug information
			if (DEBUG) {
				printf("New size: %ld\n", buffSize);
			}
		}
	}

	// If there was an error, return false
	if (ferror(stdin)) { perror("fread"); return FALSE; }
	// Print debug information
	if (DEBUG) { printf("Done.\n\n"); }

	// Reallocate the buffer to the exact size of the buffer
	realloc(*buffer, sizeof(char) * length);
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