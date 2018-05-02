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
	// Holds the number of lines to print.
	int nLines = N;
	// Holds the number of characters to print.
	int nBytes = 0;
	// Holds the flags.
	int options = fNUM_LINES;
	
	// Holds the number of files.
	size_t numFiles = argc - 1;
	// Jagged array of strings to hold the filenames
	char** fileNames = calloc(numFiles, sizeof(char*));
	// Holds the index where the filename should be stored.
	int currFile = 0;

	for (int i = 1; i < argc; i++){
		// If an option flag was received in the previous iteration, store this argument as an
		//	integer for that specific flag and decrement the number of files and continue on
		//	to the next iteration of the loop.
		// 	If an option flag was not received, do nothing.
		if (getOptionValue(argv[i], &options, &nLines, &nBytes)) { numFiles--; continue; }

		// If argv[i] is an option flag (-n or -c), set the flag in options, decrement the
		//	number of files, and continue to the next iteration of the loop.
		//	If argv[i] is not an option flag, do nothing.
		if (getOption(argv[i], &options)) { numFiles--; continue; }
		
		// Store argv[i] as a file name and increment currFile.
		addStringToArray(fileNames, currFile, argv[i]);
		currFile++;
	}

	// Reallocate memory for fileNames in case -n or -c flag was received, fileNames will have
	//	extra memory allocated because every argument was assumed to be a file name when
	//	fileNames was allocated.
	fileNames = realloc(fileNames, numFiles * sizeof(char*));
	
	// Print the head of the files.
	printFiles(fileNames, numFiles, options, nLines, nBytes);

	// Free the memory allocated for the fileNames array
	free2D(fileNames, numFiles);
}

// Sets bits in the destination using the mask provided
void setBits(int *dest, Options mask){ *dest = *dest | mask; }
// Clears bits in the destination using the mask provided
void clearBits(int *dest, Options mask){ *dest = *dest & ~mask; }
// Checks if bits are set using the mask provided
BOOL maskBits(int options, Options mask){ return options & mask; }

// Stores the decimal value in the nLines or nBytes variables according to the option flag set and returns
//	a boolean value on whether or not it succeeded
BOOL getOptionValue(char argv[], int *options, int *nLines, int *nBytes){
	int errVal;
	
	// Checks if the SET_NUM_LINES flag is set
	if (maskBits(*options, fSET_NUM_LINES)) {
		// Gets the value and stores it in nLines
		errVal = sscanf(argv, "%d", nLines);
		// Clears the SET_NUM_LINES flag
		clearBits(options, fSET_NUM_LINES);
		// Returns the error value (0 if argv was not an integer)
		return errVal;
	}
	// Checks if the SET_NUM_BYTES flag is set
	else if (maskBits(*options, fSET_NUM_BYTES)) {
		// Gets the value and stores it in nBytes
		errVal = sscanf(argv, "%d", nBytes);
		// Clears the SET_NUM_BYTES flag
		clearBits(options, fSET_NUM_BYTES);
		// Returns the error value (0 if argv was not an integer)
		return errVal;
	}
	// If no flags are set, return false
	else { return FALSE; }
}
// Checks if argv is an option, sets the corresponding flags, and returns a boolean value on whether or not it succeeded
BOOL getOption(char argv[], int *options){
	// Checks if argv is the NUM_LINES option
	if (!strcmp(argv, NUM_LINES)) {
		// Sets the SET_NUM_LINES flag
		setBits(options, fSET_NUM_LINES);
		// Sets the NUM_LINES flag
		setBits(options, fNUM_LINES);
		// Clears the NUM_BYTES flag
		clearBits(options, fNUM_BYTES);
		return TRUE;
	}
	// Checks if argv is the NUM_BYTES option
	else if (!strcmp(argv, NUM_BYTES)) {
		// Sets the SET_NUM_BYTES flag
		setBits(options, fSET_NUM_BYTES);
		// Sets the NUM_BYTES flag
		setBits(options, fNUM_BYTES);
		// Clears the NUM_LINES flag
		clearBits(options, fNUM_LINES);
		return TRUE;
	}
	// If argv is not a flag, return false
	else { return FALSE; }
}
// Adds the filename to the fileNames array
void addStringToArray(char **array, int pos, char src[]){
	// Allocates enough memory in fileNames to store the string
	array[pos] = calloc(strlen(src) + 1, sizeof(char));
	// Copies the string to fileNames
	strcpy(array[pos], src);
}

// Prints the head of each file in fileNames according to the options received
void printFiles(char **fileNames, size_t numFiles, int options, size_t numLines, size_t numBytes){
	// Points to the current file
	FILE *fPtr;

	// For each file in fileNames, print
	for (int i = 0; i < numFiles; i++){
		// Sets the file pointer to the current file, skip if the pointer is NULL
		if ((fPtr = fopen(fileNames[i], "r")) == NULL) { printf("Error opening file %s\n", fileNames[i]); continue; }

		// If there is more than one file, print a header
		if (numFiles > 1){
			printf("===>\t%s\t<===:\n",fileNames[i]);
		}
		
		// Print lines
		if (maskBits(options, fNUM_LINES)){ printLines(fPtr, numLines); }
		// Print characters
		else if (maskBits(options, fNUM_BYTES)){ printBytes(fPtr, numBytes); }

		printf("\n\n\n");

		// Close the file
		fclose(fPtr);
	}
}

// Prints the first [numLines] lines of the file
void printLines(FILE *fPtr, size_t numLines){
	if (fPtr == NULL) { return; }

	// Create a buffer to store the line
	char currLine[BUFFER_SIZE];

	// Set the cursor to the beginning of the file
	fseek(fPtr, 0, SEEK_SET);
	// Print the lines
	for (int j = 0; j < numLines; j++){
		fgets(currLine, BUFFER_SIZE, fPtr);
		printf("%s", currLine);
		// If the end of the file was reached, break
		if (feof(fPtr)) { break; }
	}
}

// Prints the first [numBytes] bytes of the file
void printBytes(FILE *fPtr, size_t numBytes){
	if (fPtr == NULL) { return; }

	// Create a buffer to store the character
	char currByte;
	
	// Set the cursor to the beginning of the file
	fseek(fPtr, 0, SEEK_SET);
	// Print the characters
	for (int j = 0; j < numBytes; j++){
		currByte = (char)fgetc(fPtr);
		printf("%c", currByte);
		// If the end of the file was reached, break
		if (feof(fPtr)) { break; }
	}
}

// Frees the memory of a 2D jagged array
void free2D(char **array, size_t numRows){
	// For each row, free the memory
	for (int i = 0; i < numRows; i++){
		free(array[i]);
	}
	// Free the now empty array
	free(array);
}