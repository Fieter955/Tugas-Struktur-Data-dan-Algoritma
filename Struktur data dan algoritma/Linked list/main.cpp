#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(8);
    list.insertAtTail(29);

    cout << "LinkedList before inserting: ";
    list.display();

    list.insertAfter(4, 3);

    cout << "LinkedList after inserting: ";
    list.display();

    list.deleteFromHead();
    list.deleteFromTail();
    list.deleteByValue(2);

    cout << "LinkedList after deletions: ";
    list.display();

    return 0;
}
