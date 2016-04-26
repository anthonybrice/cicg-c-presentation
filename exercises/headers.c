// headers.c

// YOUR TASK: Write a header file for the linked-list implementation below,
// exposing list_append(), list_prepend(), and the struct itself.

#include "headers.h"

struct List {
  void* data;
  struct List* next;
};

struct List* list_last(struct List* list) {
  if (list) {
    while (list->next) {
      list = list->next;
    }
  }

  return list;
}

struct List* list_init(void) {
  struct List* list = malloc(sizeof (struct List));
  return list;
}

struct List* list_prepend(struct List* list, void* data) {
  struct List* new_list = list_init();
  new_list->data = data;
  new_list->next = list;

  return new_list;
}

struct List* list_append(struct List* list, void* data) {
  struct List* last;
  struct List* new_list = list_init();

  new_list->data = data;
  new_list->next = NULL;

  if (list) {
    last = list_last(list);
    last->next = new_list;

    return list;
  } else {
    return new_list;
  }
}

int main(void) {
  struct List* list = NULL;

  list = list_prepend(list, "This is my data.\0");

  printf("%s", list->data);
}
