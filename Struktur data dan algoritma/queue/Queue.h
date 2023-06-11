class Node {
public:
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;
    Node* rear;

public:
    Queue();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void printQueue();
    void printElement();
};
