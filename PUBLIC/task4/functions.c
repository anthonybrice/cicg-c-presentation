// functions.c

#include <math.h>
#include <stdio.h>

// YOUR TASK: Implement the function get_population.

int get_population(int generation);
int power(int base, int exp);

main() {
  int capacity;
  int population = 0;

  printf("Oh no! A tribble has snuck on board!\n");
  printf("How many tribbles can your ship fit?\n> ");
  scanf("%d", &capacity);

  int generation = 1;

  while (population < capacity) {
    population = get_population(generation);
    generation = generation + 1;
  }

  printf("Your ship is overrun after %d generations! Abandon ship!\n", generation);
}

int power(int base, int exp) {
  int result = 1;

  int i;
  for (i = 0; i < exp; i++)
    result *= base;

  return result;
}
