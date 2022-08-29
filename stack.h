//
// Created by jorge on 28/08/22.
//

#ifndef STACK_H
#define STACK_H

#include <string>

struct Node{
    const int numero;
    Node* next;
    Node(const int num,Node* n): numero{num},next{n}{}
};

class Stack{
private:
    Node* top;
public:
    void push(int);
    int pop();
    bool isEmpty();
    Stack();
};
#endif //STACK_H
