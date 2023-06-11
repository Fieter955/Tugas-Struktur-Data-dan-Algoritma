#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack stack;
    stack.push(10);
    stack.push(2);
    stack.push(4);
    stack.push(8);
    stack.printElement();
    
    stack.pop();
    stack.printElement();

    return 0;
}







