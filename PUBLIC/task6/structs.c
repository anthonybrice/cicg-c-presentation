#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char* name;

  int health;

  int* weapon_statuses; // An array of each weapon's status. A value 100 or
                        // greater indicates the weapon is ready to fire
  int num_weapons;

} Spaceship;

// YOUR TASK: Implement charge_weapons and attack_ship
void attack_ship(Spaceship* from, Spaceship* to);
void charge_weapons(Spaceship* ship);

Spaceship make_ship(const char* name, int weapons);
void destroy_ship(Spaceship* ship);

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

/**
 * attack_ship loops through the weapons of its first argument, and for each
 * weapon status >= 100 removes some health from its second argument (Say, 2
 * health). Each fired weapon should have its status set back to 0.
 */
void attack_ship(Spaceship* firing, Spaceship* target)
{

}

/**
 * charge_weapon loops through each weapon's status, incrementing it by some
 * value (say 5), and breaks after any weapon's status is greater than 100.
 */
void charge_weapons(Spaceship* ship)
{

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
