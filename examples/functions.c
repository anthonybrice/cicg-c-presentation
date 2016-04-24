#include <stdio.h>

//Functions in C work a bit like static methods in Java, or regular 
//functions in Python, with some key differences.

//This is called a "function prototype", or "function declaration".
//It gives all the info about a function, besides the actual code 
//contained in it. This includes the return type, name, and
//parameter list.

void print_n(char c, int n);

int main(int argc, char** argv)
{
	char c;
	int n;
	
	printf("What character do you want to print?\n> ");
	scanf("%c", &c); //scanf is short for fscanf(stdin, ...);
	
	printf("\nAnd how many times do you want to print it?\n> ");
	scanf("%d", &n);
	
	printf("\n");
	
	//Normally in C, you wouldn't be able to call a function before
	//you've defined it, since the compiler reads from top to bottom
	//in a single pass (this is similar to Python, where you cannot
	//use a function that is defined later in the program, and different
	//from Java, where you can). 
	//But because we've _declared_ it above, we can _reference_ it here, 
	//and so long as we _define_ the function later on, everything will 
	//work as expected. 
	//Keep this in mind if you ever see a compiler error like 
	//"undefined reference to ...". This means there was a function
	//_declaration_, but there was no _definition_ for that function.
	//(That the compiler could find, anyway).
	
	print_n(c, n);
	print_n("\n", 1); //parameters can be literal values
	
	return 0;
}

//This is a "function definition". It copies the data in the declaration
//(so the compiler can be sure everything is correct), and includes the
//code that is actually run when the function is called.

void print_n(char c, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		//'putchar' prints a single character to the terminal
		putchar(n);
	}
}
