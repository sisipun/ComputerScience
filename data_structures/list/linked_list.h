#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

struct LinkedListElement
{
    struct LinkedListElement *next;
    struct LinkedListElement *previous;
    void *value;
};

struct LinkedList
{
    struct LinkedListElement *head;
    struct LinkedListElement *tail;
    size_t size;
};

struct LinkedList *newList();

void add(struct LinkedList *, void *);

void addByIndex(struct LinkedList *, void *, size_t);

void *getByIndex(struct LinkedList *, size_t);

void removeByIndex(struct LinkedList *, size_t);

size_t size(struct LinkedList *);

void deleteList(struct LinkedList *);

#endif