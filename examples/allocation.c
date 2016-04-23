#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count = 10;
	fprintf(stdout, "How many numbers to average?\n> ");
	fscanf(stdin, "%d", &count);
	
	//You can read this as
	//"Float pointer 'nums' equals memory allocate 
	//count times the size of a float, in bytes"
	//Essentially, you're asking for some pointer 
	//to memory that the OS will give you to use 
	//in your program. You'd probably do this when
	//you don't know how much memory you need when
	//writing the program.
	
	float* nums = malloc(sizeof(float) * count);
	
	int i;
	for(i = 0; i < count; i++) {
		fscanf(stdin, "%f", &nums[i]);
	}
	
	float sum = 0.0f;
	
	for(i = 0; i < count; i++) {
		sum += nums[i];
	}
	
	fprintf(stdout, "Average: %f\n", sum / count);
	
	//Once you're done using the memory you asked the
	//OS for, you should always free it up so it can
	//be used by some other part of your program, or
	//even another program entirely.
	
	free(nums);
	
	return 0;
}
