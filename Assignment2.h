// Logan Thomas
// Assignment 2
// 4/13/2018


/*	Assignment2.h
*	This is a header file for the Assignment2.c file.
*	This file contains function declarations and
*	a type definition of a struct called "Player".
*/
#ifndef _ASSIGNMENT2_
#define _ASSIGNMENT2_

typedef struct {
   char name[50];
   int age;
   float points;
} Player;

void updateName(Player* player);
void updateAge(Player* player);
void updatePoints(Player* player);
void displayPlayer(Player* player);
void clearPlayer(Player* player);
void displayMenu(void);

#endif