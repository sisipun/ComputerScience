#ifndef STACK_H
#define STACK_H

#include <stddef.h>

struct StackElement
{
    struct StackElement *next;
    void *value;
};

struct Stack
{
    struct StackElement *pointer;
    size_t size;
};

struct Stack *newStack();

void push(struct Stack *, void *);

void *pop(struct Stack *);

void *get(struct Stack *);

size_t size(struct Stack *);

void deleteStack(struct Stack *);

#endif