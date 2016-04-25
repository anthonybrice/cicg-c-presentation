#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers.h"

int main()
{
	IList* list = IList_new();
	
	printf("Enter any number of integers, then 'd' for 'done'.\n> ");
	
	int number_entered = -1;
	int num;
	
	number_entered = scanf("%d", &num);

	while(number_entered != 0) {
		
		//scanf actually returns something!
		//Its return value is the number of values that
		//it was able to scan from the input in a single
		//call. Since we only enter one thing per call 
		//(the '%d'), it will either be 1 if something is 
		//entered, or 0 if it was an empty line.
		
		IList_add(list, num);
		
		number_entered = scanf("%d", &num);
	}
	
	char c;
	int val;
	
	//This will be leftover from the previous scanf call (like Scanner.nextLine() in Java)
	scanf("%c", &c);
	scanf("%c", &c);
	
	c = '\0';
	
	while(c != 'e') {
		printf("\n\nOptions:\n\ta) add a number\n\tr) remove a number\n\tf) find a number\n\tp) print list\n\te) end\n\n> ");
		
		char extra;
		scanf(" %c", &c);
		//scanf("%c", &extra);
		
		if(c == 'a') {
			
			scanf("%d", &val);
			IList_add(list, val);
			
		} else if(c == 'r') {
			
			scanf("%d", &val);
			IList_remove(list, val);
		
		} else if(c == 'f') {
			
			scanf("%d", &val);
			INode* node = IList_find(list, val);
			
			if(node != NULL) {
				printf("%p => {\n\tvalue: %d\n\tnext: %p\n}", node, node->value, node->next);
			} else {
				printf("%d not found.", val);
			}
			
		} else if(c == 'p') {

			IList_print(list);
			
		} else if(c != 'e') {
			
			printf("Unrecognized command %c.", c);
		
		} else {
			break;
		}
	}

	return 0;
}
