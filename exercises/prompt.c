// prompt.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char name[40];
  printf("Enter your name:\n");

  // YOUR TASK: Prompt the user for their name say hello.

  scanf("%s", name);
  printf("Hello, %s\n", name);

  return 0;
}
