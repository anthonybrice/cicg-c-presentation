#include <stdio.h>

//Main has two forms- no arguments, and taking
//	'argc', the number of arguments and
//	'argv', the argument values
//
//These are the command line arguments you give
//to the program when you run it. Together, these 
//are the 'args' in Java's 
//'public static main(String[] args)'

int main(int argc, char** argv)
{
	//argc is always at least 1, because...
	if(argc < 2) {
		
		//... the first argument value is the program name
		fprintf(stderr, "Usage: %s <name>\n", argv[0]);
		return -1;
	}
	
	fprintf(stdout, "Hello, %s!\n", argv[1]);
	return 0;
}
