// arguments.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Usage: %s <name> <integer>\n", argv[0]);
    exit(-1);
  }

  // YOUR TASK: Read the user's name and integer from command line arguments,
  // then say hello to the user as many times as given by the integer.

}
