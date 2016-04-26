// pointers.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char** first, char** second) {
  char* temp;

  temp = *first;
  *first = *second;
  *second = temp;
}

int main(void) {
  char* string1 = "This is the first string.";
  char* string2 = "This is the second string.";

  // YOUR TASK: write a function `swap` that swaps the pointers string1 and
  // string2.

  swap(&string1, &string2);

  printf("string1 = %s and string2 = %s\n", string1, string2);
}
