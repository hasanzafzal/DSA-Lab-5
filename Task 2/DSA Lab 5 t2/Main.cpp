#include "LinkedStr.h"
#include <iostream>
using namespace std;

int main() 
{
    LinkedStr list;
    list.makeStr(1);
    cout << "Values in the linked list are: ";
    list.displayStr();
    list.removeFirst();
    list.removeLast();
    cout << "After removing first and last element: ";
    list.displayStr();
    list.remove(5);
    cout << "After removing the 5 element: ";
    list.displayStr();
    return 0;
}