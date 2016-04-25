#include <stdio.h>
#include <stdlib.h>

/* structs in C are ways to organize your data
 * into a single element- 'struct'ured data
 *
 * They are somewhat like classes in Java and
 * Python, but are much more limited in scope.
 * While in Java and Python, your objects can
 * hold data and include function definitions,
 * in C, your structures can only hold data,
 * including nested structs (like nested classes
 * in Java and Python).
*/

struct int_array {
	
	//'data' here will point to an array of ints-
	//we'll look at arrays in this exercise, too
	int* data;
	
	int length;
};


/* This is a 'typedef', a way to define a new name
 * for an already-existing type. It has the form
 *
 * typedef <original typename> <new typename>
 *
 * Normally you would typedef a struct, because if you
 * didn't, you would have to add 'struct' before
 * each variable of that type, because 'struct' is a
 * part of the type declaration. If you don't, that's
 * fine! You just have to declare them like
 *
 * struct <struct name> <variable name>
*/

typedef struct int_array IArray;

IArray IArray_new(int length);
void IArray_delete(IArray* arr);

void IArray_print(IArray* arr);

int main()
{
	IArray array = IArray_new(10);
	
	printf("Enter 10 integers\n> ");
	
	//We can access the members of an array instance
	//with the dot notation, like in Java and Python
	int i;
	for(i = 0; i < array.length; i++) {
		scanf("%d", &array.data[i]);
	}
	
	printf("\nSo, you entered\n\t");
	IArray_print(&array);
	printf("\n");
	
	//Unlike Java and Python, objects don't get deleted
	//automatically- don't forget to put back the memory
	//you asked for, even if you didn't call malloc
	//yourself!
	
	IArray_delete(&array);
	
	return 0;
}

IArray IArray_new(int length)
{
	IArray array;
	
	//Allocate <length> ints as an array, and
	//point data at it
	
	array.data = malloc(sizeof(int) * length);
	array.length = length;
	
	return array;
}

void IArray_delete(IArray* array)
{
	//When we have a pointer to a structure, we use
	//the arrow notation- an arrow replaces the dot.
	//Now the pointer really seems like a 'point'-er!
	
	free(array->data);
}

void IArray_print(IArray* array)
{
	printf("{ ");
	
	//If IArray wasn't a structure, we'd have to pass 
	//the length separately!
	
	int i;
	for(i = 0; i < array->length; i++) {
		printf("%d ", array->data[i]);
	}
	
	printf("}");
}
