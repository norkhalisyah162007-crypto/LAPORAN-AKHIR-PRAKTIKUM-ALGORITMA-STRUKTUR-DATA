#include "stack.h"
#include <stdexcept>

void init(Stack* s) {
    s->top = s->data - 1;
}

bool isEmpty(const Stack* s) {
    return s->top < s->data;
}

bool isFull(const Stack* s) {
    return s->top == s->data + MAX - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) throw std::overflow_error("Stack is full");
    *(++s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) throw std::underflow_error("Stack is empty");
    s->top--;
}

int peek(const Stack* s) {
    if (isEmpty(s)) throw std::underflow_error("Stack is empty");
    return *(s->top);
}
