#ifndef _ASSIGNMENT4_
#define _ASSIGNMENT4_

#define BOOL int
#define TRUE 1
#define FALSE 0

#define DEBUG_OPTION "-d"
#define APPEND_OPTION "-a"

typedef enum {
	fERROR		= 0,
	fDEBUG		= 1 << 0,
	fAPPEND		= 1 << 1
} Options;

void setBits(int *dest, Options mask);
void clearBits(int *dest, Options mask);
int maskBits(int options, Options mask);

BOOL getOption(char arg[], int *options);
BOOL addStringToArray(char **array, int *pos, char src[]);

int readInput(char **buffer);

void printFileNames(char **files, size_t numFiles);
void printOptions(int options);
void printInput(char *input, size_t inputLength, char **files, size_t numFiles, BOOL append);

void free2D(char **array, size_t numRows);
#endif