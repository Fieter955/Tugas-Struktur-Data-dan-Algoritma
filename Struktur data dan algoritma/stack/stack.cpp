#include <iostream>
#include "Stack.h"

using namespace std;



void Stack::push(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

bool Stack::isEmpty() {
    return top == NULL;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

void Stack::printStack() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::printElement() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack before pop: ";
    printStack();
    int poppedValue = pop();
    cout << "Popped value: " << poppedValue << endl;
    cout << "Stack after pop: ";
    printStack();
}
