/*
*	Logan Thomas
*	Programming Language Paradigms
*	Assignment 3
*/


/*	Assignment3.h
*	This is a header file for the Assignment3.c file.
*	This file contains function declarations.
*/
#ifndef _ASSIGNMENT3_
#define _ASSIGNMENT3_

#define TRUE 1
#define FALSE 0

#define N 10
#define BUFFER_SIZE 1024

#define NUM_LINES "-n"
#define NUM_BYTES "-c"

#define BOOL int

// Options flags
typedef enum {
	fERROR			= 0,
	fNUM_LINES		= 1 << 0,
	fNUM_BYTES		= 1 << 1,
	fSET_NUM_LINES	= 1 << 2,
	fSET_NUM_BYTES	= 1 << 3
} Options;


// Function Declarations
void setBits(int *dest, Options mask);
void clearBits(int *dest, Options mask);

BOOL getOptionValue(char argv[], int *options, int *nLines, int *nBytes);
BOOL getOption(char argv[], int *options);
void addStringToArray(char **array, int pos, char src[]);

void printFiles(char **fileNames, size_t numFiles, int options, size_t numLines, size_t numBytes);
void printLines(FILE *fPtr, size_t numLines);
void printBytes(FILE *fPtr, size_t numBytes);

void free2D(char **array, size_t numRows);

#endif