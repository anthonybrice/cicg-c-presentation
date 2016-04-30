// headers.h

#ifndef _HEADERS_H_
#define _HEADERS_H_

struct List* list;

struct List* list_prepend(struct List* list, void* data);

struct List* list_append(struct List* list, void* data);

#endif
