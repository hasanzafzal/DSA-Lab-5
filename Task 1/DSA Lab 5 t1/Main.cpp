#include "List.h"
#include <iostream>
using namespace std;

int main() 
{
    List<int> l;
    int choice, value;
    while (true) 
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete Item" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Print List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            l.push(value);
            break;
        case 2:
            if (l.emptyList()) 
            {
                cout << "Error: List is empty" << endl;
            }
            else
            {
                cout << "Popped value: " << l.pop() << endl;
            }
            break;
        case 3: 
        {
            int oldvalue, newvalue;
            cout << "Enter old value: ";
            cin >> oldvalue;
            cout << "Enter new value: ";
            cin >> newvalue;
            l.insertafter(oldvalue, newvalue);
            break;
        }
        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            l.deleteItem(value);
            break;
        case 5:
            cout << (l.emptyList() ? "List is empty" : "List is not empty") << endl;
            break;
        case 6:
            cout << "List: ";
            l.printList();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << endl;
    }
}