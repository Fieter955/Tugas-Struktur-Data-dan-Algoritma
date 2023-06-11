#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue() {
    front = NULL;
    rear = NULL;
}

bool Queue::isEmpty() {
    return front == NULL;
}

void Queue::enqueue(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty()) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return -1;
    }
    Node* temp = front;
    int dequeuedValue = temp->data;

    if (front == rear) {
        front = NULL;
        rear = NULL;
    } 
    else {
        front = front->next;
    }
    delete temp;
    return dequeuedValue;
}

void Queue::printQueue() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Queue::printElement() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue before dequeue: ";
    printQueue();
    int dequeuedValue = dequeue();
    cout << "Dequeued value: " << dequeuedValue << endl;
    cout << "Queue after dequeue: ";
    printQueue();
}
