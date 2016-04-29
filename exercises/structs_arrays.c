#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* name;
	
	int health;
	
	int* weapon_statuses;
	int num_weapons;
	
} Spaceship;

Spaceship make_ship(const char* name, int weapons);
void destroy_ship(Spaceship* ship);

void attack_ship(Spaceship* from, Spaceship* to);
void charge_weapons(Spaceship* ship);

void fight_ships(Spaceship* first, Spaceship* second);

int main()
{
	char name[80];
	int weapons = 7;
	
	printf("You've just bought your own spaceship! What is it called?\n> ");
	scanf("%79s", name); //only fills in 79 characters- one more is needed at the end for '\0'
	
	printf("\nAnd how many weapons does it have?\n> ");
	scanf("%d", &weapons);
	
	Spaceship our_ship = make_ship(name, weapons);
	
	printf("\nYou take off in your new spaceship!\n...\n...\n\nA hostile ship sets its eyes on you! Quick, what is its description?\n");
	printf("(What is its broadcasted name?)\n> ");
	scanf("%79s", name);
	printf("(How many weapons does it have?)\n> ");
	scanf("%d", &weapons);
	
	Spaceship enemy = make_ship(name, weapons);
	
	fight_ships(&our_ship, &enemy);
	
	if(our_ship.name == NULL) {
		printf("\n\nShould have invested in some better shields!\n");
		
		if(enemy.name == NULL) {
			printf("At least you took them down with you.\n\n");
		}
	} else {
		printf("\n\nGood job! Now try for the Death Star.\n\n");
	}
	
	return 0;
}

Spaceship make_ship(const char* name, int weapons)
{
	Spaceship ship;
	
	//strlen is short for STRing LENgth- it just
	//finds out how long your string is
	ship.name = malloc(strlen(name) + 1);
	strcpy(ship.name, name);
	
	ship.health = 100;
	
	ship.num_weapons = weapons;
	ship.weapon_statuses = malloc(sizeof(int) * weapons);
	
	int i;
	for(i = 0; i < weapons; i++) {
		ship.weapon_statuses[i] = 0;
	}
	
	return ship;
}

void destroy_ship(Spaceship* ship)
{
	printf("\n%s was destroyed!\n", ship->name);
	free(ship->name);
	free(ship->weapon_statuses);
	ship->name = NULL;
	ship->weapon_statuses = NULL;
}

//Have them fill this out-
//Requirements:
//
//	1) Should loop through firing's weapon statuses and find
//	   weapons at 100% charge.
//
//	2) Should take away some health from target
//
//	3) Should reset the firing's weapon's status to 0
//
//	(Tell them about rand() if they ask- it's used in
//	 testing code in Comp 362)
//

void attack_ship(Spaceship* firing, Spaceship* target)
{
	int i;
	for(i = 0; i < firing->num_weapons; i++) {
		
		//pew pew pew
		if(firing->weapon_statuses[i] == 100) {
			target->health = target->health - 2;
			firing->weapon_statuses[i] = 0;
		}
	}
}

//Have them fill this out-
//Requirements:
//
//	1) Loop through the ship's weapon statuses and increase
//	   the status at each step
//
//	2) Stop at the first weapon status >= 100 (it's at max
//	   capacity and has to be fired)
//
//	(Tell them about rand() if they ask- it's used in
//	 testing code for Comp 362)
//

void charge_weapons(Spaceship* ship)
{
	int i;
	for(i = 0; i < ship->num_weapons; i++) {
		ship->weapon_statuses[i] = ship->weapon_statuses[i] + 5;
		
		if(ship->weapon_statuses[i] >= 100) {
			break;
		}
	}
}

//They can modify this if they want, but they don't have to add or
//remove anything here.
void fight_ships(Spaceship* first, Spaceship* second)
{
	while(first->name != NULL && second->name != NULL) {
		charge_weapons(first);
		charge_weapons(second);
		
		attack_ship(second, first); //they saw us first
		attack_ship(first, second); //returning fire
		
		printf("\n\n%s's health: %d\n", first->name, first->health);
		printf("%s's health: %d", second->name, second->health);
		
		if(first->health <= 0) {
			destroy_ship(first);
		}
		
		if(second->health <= 0) {
			destroy_ship(second);
		}
	}
}
