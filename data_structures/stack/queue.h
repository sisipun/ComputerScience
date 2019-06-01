#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

struct QueueElement {
    struct QueueElement *previous;
    void *value;
};

struct Queue {
    struct QueueElement *head;
    struct QueueElement *tail;
    size_t size;
};

struct Queue *newQueue();

void enqueue(struct Queue *, void *);

void *dequeue(struct Queue *);

void *peek(struct Queue *);

size_t size(struct Queue *);

void deleteQueue(struct Queue *);

#endif