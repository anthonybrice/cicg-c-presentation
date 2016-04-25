//This is a header file. Header files are used to hold
//function prototypes and struct declarations separate
//from your source code, to keep things cleaner.

//This is an "include guard". It's used to prevent double
//inclusions, which cause compiler errors (it thinks you're
//trying to replace things you're not supposed to).

#ifndef HEADERS_H //if HEADERS_H not defined {
#define HEADERS_H 	//define HEADERS_H

//This is a single node in a linked list-
//if you've taken COMP 151, you'll remember how
//linked lists work. If not, we'll teach you!

struct node {
	int value;
	
	struct node* next;
};

typedef struct node INode;

struct list {
	INode* head;
	INode* tail;
};

typedef struct list IList;

IList* IList_new();
void IList_delete(IList* list);

void IList_add(IList* list, int val);
void IList_remove(IList* list, int val);
INode* IList_find(IList* list, int val);
void IList_print(IList* list);

//You need to end the #ifdef from above, like
//the ending brace on an if block

#endif 		//} //HEADERS_H 

