#include <stdio.h>

int get_population(int generation);

int main()
{
	int capacity;
	int population = 0;
	
	printf("Oh no! A tribble has snuck on board!\n");
	printf("How many tribbles can your ship fit?\n> ");
	scanf("%d", &capacity);
	
	int generation = 1;
	
	while(population < capacity) {
		
		population = get_population(generation);
		generation = generation + 1;
		
	}
	
	printf("Your ship is overrun after %d generations! Abandon ship!\n", generation);
	
	return 0;
}


//have them fill this out
//This function should return a constantly-increasing number,
//based on the Fibonacci sequence. Tell them that each tribble
//can breed one more tribble each, and the older ones are still
//on the ship

int get_population(int generation)
{
	if(generation <= 0) {
		return 1;
	} else {
		return get_population(generation - 2) + get_population(generation - 1);
	}
}
