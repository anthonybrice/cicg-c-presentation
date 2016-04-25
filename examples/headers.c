#include <stdio.h>
#include <stdlib.h>

//we use quotes around headers that we write
#include "headers.h"

IList* IList_new()
{
	IList* list;
	list = malloc(sizeof(IList));
	
	//a new list starts off empty
	list->head = NULL;
	list->tail = NULL;
	
	return list;
}

void IList_delete(IList* list)
{
	INode* node = list->head;
	INode* next = node->next;
	
	//to delete a list, we delete every node of the
	//list, and then finally the list itself
	
	while(node != NULL) {
		free(node);
		node = next;
		
		if(node) {
			next = node->next;
		}
	}
	
	list->head = NULL;
	list->tail = NULL;
	
	free(list);
}

void IList_add(IList* list, int val)
{
	INode* new = malloc(sizeof(INode));
	new->value = val;
	new->next = NULL;
	
	//This is the advantage of a list-
	//adding a new element is just
	//putting it at the end of the list
	
	if(list->head == NULL) {
		list->head = new;
		list->tail = list->head;
	} else {
		list->tail->next = new;
		list->tail = new;
	}
	
}

void IList_remove(IList* list, int val)
{
	INode* current = list->head;
	INode* prev = list->head;
	
	//Unfortunately removing an element takes
	//more work. We have to go over the whole list up
	//until the element, then 'skip' that node before
	//deleting it.
	
	while(current != NULL && current->value != val) {
		prev = current;
		current = current->next;
	}
	
	if(current != NULL) {
		if(current == list->head) {
			list->head = current->next;
		} else {
			if(current == list->tail) {
				list->tail = prev;
			}
		}
		
		prev->next = current->next;
		free(current);
	}
}

INode* IList_find(IList* list, int val)
{
	INode* current = list->head;
	
	while(current != NULL && current->value != val) {
		current = current->next;
	}
	
	//Returning NULL means the element wasn't found.
	
	return current;
}

void IList_print(IList* list)
{
	INode* current = list->head;
	
	while(current != NULL && current->next != NULL) {
		printf("%d, ", current->value);
		current = current->next;
	}
	
	if(current != NULL) {
		printf("%d", current->value);
	}
}
