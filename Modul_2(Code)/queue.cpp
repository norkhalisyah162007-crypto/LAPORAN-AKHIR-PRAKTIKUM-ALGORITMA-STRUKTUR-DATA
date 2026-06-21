#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = q->data;
    q->rear = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->rear < q->front;
}

bool isFull(const Queue* q) {
    return (int)(q->rear - q->data) >= MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) throw std::overflow_error("Queue is full");
    *(++q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) throw std::underflow_error("Queue is empty");
    int count = (int)(q->rear - q->front);
    for (int i = 0; i < count; i++) {
        q->data[i] = q->data[i + (q->front - q->data) + 1];
    }
    q->front = q->data;
    q->rear = q->data + count - 1;
}

int front(const Queue* q) {
    if (isEmpty(q)) throw std::underflow_error("Queue is empty");
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) throw std::underflow_error("Queue is empty");
    return *(q->rear);
}