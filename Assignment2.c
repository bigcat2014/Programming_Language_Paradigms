// Logan Thomas
// Assignment 2
// 4/13/2018

/*	Assignment2.c
*	This is the Assignment2.c file.
*	This file contains function definitions and
*	a command line program to create and edit
*	player data; i.e. name, age, points.
*/
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <string.h>
#include "Assignment2.h"

int main(void){
	// Variable to exit the while loop when the user exits
	int quit = FALSE;
	// Holds the user input character from the menu selection
	char inputText[1];
	// The Player struct to hold the player values, name, age, and points
	Player pl;
	// Initializes the player
	clearPlayer(&pl);

	// Loops until the user chooses exit
	while (!quit) {
		// Displays the menu
		displayMenu();
		// Gets the user input and stores it in input text
		scanf("%1s", inputText);
		// Clear input buffer in case of incorrect user data
		while((getchar()) != '\n');
		// Decicides which function to run based on user input
		switch (*inputText){
			case 'n':
				// Changes the player name based on user input
				updateName(&pl);
				break;
			case 'a':
				// Changes the player age based on user input
				updateAge(&pl);
				break;
			case 'p':
				// Changes the player points based on user input
				updatePoints(&pl);
				break;
			case 'd':
				// Displays the player's info
				displayPlayer(&pl);
				break;
			case 'c':
				// Resets the player info
				clearPlayer(&pl);
				break;
			case 'q':
				// Exits the program
				quit = TRUE;
				printf("Quitting...\n");
				break;
			default:
				// Notifies the user that their selection is invalid
				printf("Invalid selection: %s\n", inputText);
		}
	}
	printf("Goodbye\n");
	return 0;
}


/*	updateName
*	Returns: nothing
*	Parameters: Player struct pointer
*	
*	This method accepts a player struct and prompts the user
*		for a name to update the player name in the struct.
*/
void updateName(Player* player){
	char name[50];

	printf("Please enter the player's name\n");
	printf(">> ");
	scanf("%50s", name);
	// Clear input buffer in case of incorrect user data
	while((getchar()) != '\n');
	strncpy(player->name, name, strlen(name));
}


/*	updateAge
*	Returns: nothing
*	Parameters: Player struct pointer
*	
*	This method accepts a player struct and prompts the user
*		for an age to update the player name in the struct.
*/
void updateAge(Player* player){
	int age[1];

	printf("Please enter the player's age\n");
	printf(">> ");
	scanf("%d", age);
	// Clear input buffer in case of incorrect user data
	while((getchar()) != '\n');
	player->age = *age;
}


/*	updatePoints
*	Returns: nothing
*	Parameters: Player struct pointer
*	
*	This method accepts a player struct and prompts the user
*		for the number of points to update the player name
*		in the struct.
*/
void updatePoints(Player* player){
	float points[1];

	printf("Please enter the player's points per game\n");
	printf(">> ");
	scanf("%f", points);
	// Clear input buffer in case of incorrect user data
	while((getchar()) != '\n');
	player->points = *points;
}


/*	displayPlayer
*	Returns: nothing
*	Parameters: Player struct pointer
*	
*	This method accepts a player struct and displays the
*		player info in a redable format
*/
void displayPlayer(Player* player){
	printf("%s\n\n", "Player info:");
	printf("\t%s%s\n", "Name: ", player->name);
	printf("\t%s%d\n", "Age: ", player->age);
	printf("\t%s%.2f\n\n", "Points: ", player->points);
}


/*	clearPlayer
*	Returns: nothing
*	Parameters: Player struct pointer
*	
*	This method accepts a player struct and resets it
*/
void clearPlayer(Player* player){
	*player = (const Player) {};
}


/*	displayMenu
*	Returns: nothing
*	Parameters: nothing
*	
*	This method prints the menu for user interaction
*/
void displayMenu(void){
	printf("%s\n\n", "Please select an option:");
	printf("\t\"%c\" - %s\n", 'n', "Enter the name of a player");
	printf("\t\"%c\" - %s\n", 'a', "Enter the age of a player");
	printf("\t\"%c\" - %s\n", 'p', "Enter the points per game of a player");
	printf("\t\"%c\" - %s\n", 'd', "Display the player data");
	printf("\t\"%c\" - %s\n", 'c', "Clear the player data");
	printf("\t\"%c\" - %s\n\n", 'q', "Quit");
	printf(">> ");
}