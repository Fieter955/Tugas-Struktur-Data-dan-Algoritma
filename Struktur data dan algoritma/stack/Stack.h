class Node {
public:
    int data;
    Node* next;
};

class Stack {
public:
    Node* top;

public:
    void push(int x);
    bool isEmpty();
    void printStack();
    void printElement();
    int pop();
    
    Stack(){
    	top = 0;
	}
    
    
};
