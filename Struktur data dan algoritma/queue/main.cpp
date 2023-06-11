#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue q;
    q.enqueue(3);
    q.enqueue(5);
    q.enqueue(7);
    q.printElement();
    
    q.enqueue(7);
    q.printElement();

   

    return 0;
}
