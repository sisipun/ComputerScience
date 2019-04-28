#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

struct LinkedList *newList()
{
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->size = 0;
    return list;
}

void add(struct LinkedList *list, void *value)
{
    struct LinkedListElement *element = (struct LinkedListElement *)malloc(sizeof(struct LinkedListElement));
    element->value = value;
    if (!list->size)
    {
        list->head = element;
        list->tail = element;
        list->size = 1;
    }
    else
    {
        list->tail->next = element;
        element->previous = list->tail;
        list->tail = element;
        list->size++;
    }
}

void *getByIndex(struct LinkedList *list, size_t index)
{
    if (list->size <= index)
    {
        return NULL;
    }

    struct LinkedListElement *element = list->head;
    for (int i = 0; i < index; i++)
    {
        element = element->next;
    }

    return element->value;
}

void removeByIndex(struct LinkedList *list, size_t index)
{
    if (list->size <= index)
    {
        return;
    }

    struct LinkedListElement *element = list->head;
    for (int i = 0; i < index; i++)
    {
        element = element->next;
    }

    if (element == list->head)
    {
        list->head = element->next;
        list->head->previous = 0;
    }
    else if (element == list->tail)
    {
        list->tail = element->previous;
        list->tail->next = 0;
    }
    else
    {
        element->next->previous = element->previous;
        element->previous->next = element->next;
    }

    free(element);
    list->size--;
}

void addByIndex(struct LinkedList *list, void *value, size_t index)
{
    if (list->size < index)
    {
        return;
    }
    else if (list->size == index)
    {
        add(list, value);
    }
    else if (0 == index)
    {
        struct LinkedListElement *element = (struct LinkedListElement *)malloc(sizeof(struct LinkedListElement));
        element->value = value;
        element->next = list->head;
        list->head->previous = element;
        list->head = element;
        list->size++;
    }
    else
    {
        struct LinkedListElement *element = (struct LinkedListElement *)malloc(sizeof(struct LinkedListElement));
        element->value = value;
        struct LinkedListElement *currentElement = list->head;
        for (int i = 0; i < index; i++)
        {
            currentElement = currentElement->next;
        }
        element->previous = currentElement->previous;
        element->previous->next = element;
        element->next = currentElement;
        currentElement->previous = element;
        list->size++;
    }
}

size_t size(struct LinkedList *list)
{
    return list->size;
}

void deleteList(struct LinkedList *list)
{
    while (list->size)
    {
        removeByIndex(list, 0);
    }
    free(list);
}