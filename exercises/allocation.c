#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char buffer[80];
	
	char** positions;
	char** names;
	int crew_size = 1;
	
	printf("You've been promoted to Captain and get to pick your own crew to take on your adventures!\n");
	printf("How big is your crew?\n> ");
	scanf("%d", &crew_size);
	crew_size = crew_size + 1; //to include you, Captain!
	
	//Have them allocate the positions and names after the input
	positions = malloc(sizeof(char*) * crew_size);
	names = malloc(sizeof(char*) * crew_size);
	
	positions[0] = malloc(strlen("Captain") + 1);
	strcpy(positions[0], "Captain");
	
	printf("\nWhat is your name, Captain?\n> ");
	scanf("%80s", buffer);
	names[0] = malloc(strlen(buffer) + 1);
	strcpy(names[0], buffer);
	
	printf("And what are the positions and names of your crew? (Enter '<position> <name>')\n> ");
	
	int i;
	for(i = 1; i < crew_size; i++) {
		
		//Have them allocate the space for both the positions and the names
		scanf(" %80s", buffer);
		positions[i] = malloc(strlen(buffer) + 1);
		strcpy(positions[i], buffer);
		
		scanf("%80s", buffer);
		names[i] = malloc(strlen(buffer) + 1);
		strcpy(names[i], buffer);
		
		printf("\n> ");
	}
	
	printf("So the crew of your ship is:\n\n");
	
	//Make sure they free the arrays they allocated- not necessarily in this loop
	for(i = 0; i < crew_size; i++) {
		printf("%s %s\n", positions[i], names[i]);
		free(positions[i]);
		free(names[i]);
	}
	
	free(positions);
	free(names);
	
	printf("Aim for the stars, new Captain!\n");
		
}
