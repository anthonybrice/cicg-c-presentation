#include <stdio.h>
#include <string.h>

int main()
{
	char name[80];
	int age;
	
	fprintf(stdout, "Enter your name and age.\n> ");
	fscanf(stdin, "%s", name);
	
	//&age means "pointer to age"
	//A pointer is essentially a memory address,
	//which usually (but not always) 'points' to
	//a variable
	//You give a pointer to fscanf so it can put
	//a value at that memory address
	fscanf(stdin, "%d", &age);
	
	fprintf(stdout, "So you're %s, and you're %d years old.\n", name, age);

	return 0;
}
