// arguments.c

#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <name>\n", argv[0]);
    return -1;
  }

  // YOUR TASK: Read the user's name from command line arguments and print it.

  printf("Hello, %s\n", argv[1]);
  return 0;
}
