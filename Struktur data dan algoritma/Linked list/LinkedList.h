class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class LinkedList {

public:
	Node* head;
    LinkedList();
    void insertToHead(int value);
    void insertAtTail(int value);
    void insertAfter(int key, int value);
    void deleteFromHead();
    void deleteFromTail();
    void deleteByValue(int value);
    void display();
};

