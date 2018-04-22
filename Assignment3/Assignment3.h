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

typedef enum {
	fNUM_LINES = 1 << 0,
	fNUM_BYTES = 1 << 1
} Options;

void setBits(int *dest, Options mask);
void clearBits(int *dest, Options mask);
void free2D(char **array, size_t numRows);

#endif