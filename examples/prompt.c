#include <stdio.h>

int main()
{
	//In C, strings are just arrays of characters,
	//which always end with the character '\0'
	char name[80];
	
	//File Print Formatted- Like in Java, C does
	//output and input from the terminal using something
	//called "filestreams". stdout is like Java's
	//System.out
	fprintf(stdout, "What's you're name?\n> ");
	
	//File Scan- Also as in Java, in C, to get input
	//from the terminal, you scan a filestream. stdin
	//is like Java's System.in
	fscanf(stdin, "%s", name);
	
	//This is formatted output. The '%s' in the second
	//argument means "string", as in "print the supplied
	//string here".
	fprintf(stdout, "Hello, %s!\n", name);
	
	return 0;
}
