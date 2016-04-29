// arguments.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <name> <integer>\n", argv[0]);
    return -1;
  }

  // YOUR TASK: Read the user's name from command line arguments and print it.
  // Then read a number from the command line.

  char* name = argv[1];
  int num = atoi(argv[2]);

  printf("Hello, %s\n", name);
  printf("Your magic number is %d\n", num);
}
