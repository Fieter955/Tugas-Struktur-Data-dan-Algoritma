#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node(int value) {
			data = value;
			next = NULL;
		}
};

class LinkedList {
	private:
		Node *head;
		Node *tail;

	public:
		LinkedList() {
			head = tail = NULL;
		}

		void insertToHead(int value){


			Node *newNode = new Node(value);

			if(head == NULL){

				head = newNode;
			}
			else {
				Node *tmp = head;
				while(tmp->next != NULL){

					tmp = tmp->next;
				}
				tmp->next = newNode;
			}
		}

 void insertToTail(int value) {
	 Node* newNode = new Node(value);
	 if(head == NULL) {
    head = newNode;
    tail=newNode;
  } else {
    Node* temp = head;
    while(temp->next != NULL)
      temp = temp->next;
      temp->next = newNode;
  }
}



			void insertAfter(int value, int key) {
    if (head == NULL) {
        cout << "Linked list is empty." << endl;
        return;
    }

    Node *tmp = head;
    while (tmp != NULL && tmp->data != key) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        cout << "Key not found in linked list." << endl;
        return;
    }

    Node *newNode = new Node(value);
    newNode->next = tmp->next;
    tmp->next = newNode;
}


		void display() {
			if(head == NULL){

				cout << "linked list is empty" << endl;
			}
			else {
				Node *tmp = head;
				while(tmp != NULL){

					cout << tmp->data << "->";
					tmp = tmp->next;
				}
				cout << "null" << endl;
			}
		}
};

int main() {
	LinkedList list;

	list.insertToHead(5);
	list.insertToHead(6);
	list.insertToHead(4);
	list.insertToTail(13);


	list.display();

	return 0;
}
 140  
queue.cpp
