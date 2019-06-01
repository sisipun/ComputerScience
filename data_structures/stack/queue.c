#include "queue.h"

struct Queue *newQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->size = 0;
    return queue;
}

void enqueue(struct Queue *queue, void *value) {
    struct QueueElement *element = (struct QueueElement *)malloc(sizeof(struct QueueElement));
    if (!queue->head) {
        element->previous = 0;
        queue->head = element;
        queue->tail = element;
        queue->size = 1;
        return;
    }

    queue->tail->previous = element;
    queue->tail = element;
    queue->size++;
}

void *dequeue(struct Queue * queue) {
    if (!queue->head) {
        return 0;
    }

    struct QueueElement *element = queue->head;
    queue->head = element->previous;
    void *value = element->value;
    free(element);
    queue->size--;
    return value;
}

void *peek(struct Queue * queue) {
    if (!queue->head) {
        return 0;
    }

    return queue->head->value;
}

size_t size(struct Queue *queue) {
    return queue->size;
}

void deleteQueue(struct Queue *queue) {
    while (size(queue)) {
        dequeue(queue);
    }
    free(queue);
}
