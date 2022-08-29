//
// Created by jorge on 28/08/22.
//
#include "stack.h"

void Stack::push(const int numero) {
    top = new Node(numero,top);
}
bool Stack::isEmpty() {
    return !top;
}
int Stack::pop() {
    int numero{top->numero};
    Node* node{top};
    top = top->next;
    delete node;
    return numero;
}

Stack::Stack() :top{nullptr}{}