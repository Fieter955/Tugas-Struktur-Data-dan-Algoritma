#include <iostream>
#include "LinkedList.h"
using namespace std;


Node::Node(int value) {
    data = value;
    next = NULL;
}

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::insertToHead(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtTail(int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::insertAfter(int key, int value) {
    Node* newNode = new Node(value);

    if (head == NULL) {
        cout << "LinkedList is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Key not found in the LinkedList!" << endl;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void LinkedList::deleteFromHead() {
    if (head == NULL) {
        cout << "LinkedList is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void LinkedList::deleteFromTail() {
    if (head == NULL) {
        cout << "LinkedList is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void LinkedList::deleteByValue(int value) {
    if (head == NULL) {
        cout << "LinkedList is empty!" << endl;
        return;
    }

    if (head->data == value) {
        deleteFromHead();
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Node not found in the LinkedList!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
	
	void LinkedList::display(){
	if (head == NULL) {
	cout << "LinkedList is empty!" << endl;
	}
	else {
	Node* temp = head;
	while (temp != NULL) {
	cout << temp->data << " ";
	temp = temp->next;
	}
	cout << endl;
	}
	}
