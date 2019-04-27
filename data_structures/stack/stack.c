#include "stack.h"

struct Stack *newStack()
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = 0;
    return stack;
}

void push(struct Stack *stack, void *value)
{
    struct StackElement *element = (struct StackElement *)malloc(sizeof(struct StackElement));
    element->value = value;
    element->next = stack->pointer;
    stack->pointer = element;
    stack->size++;
}

void *pop(struct Stack *stack)
{
    if (!stack->size) {
        return NULL;
    }
    struct StackElement *popElement = stack->pointer;
    stack->pointer = popElement->next;
    stack->size--;
    void *value = popElement->value;
    free(popElement);
    return value;
}

void *get(struct Stack *stack)
{
    return stack->pointer->value;
}

size_t size(struct Stack *stack)
{
    return stack->size;
}