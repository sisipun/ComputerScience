#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

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

void push(struct Stack *stack, void *value);

void *pop(struct Stack *stack);

void *get(struct Stack *stack);

size_t size(struct Stack *stack);

#endif