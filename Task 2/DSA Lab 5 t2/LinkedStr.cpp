#include "LinkedStr.h"

LinkedStr::LinkedStr()
{
    ptr = nullptr;
}

LinkedStr::~LinkedStr() 
{
    Node* temp;
    while (ptr != nullptr)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

void LinkedStr::makeStr(int len) 
{
    for (int i = len; i < 11; i++) 
    {
        Node* newNode = new Node;
        newNode->info = i;
        newNode->next = ptr;
        ptr = newNode;
    }
}

void LinkedStr::displayStr()
{
    Node* temp = ptr;
    while (temp != nullptr)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedStr::removeFirst()
{
    if (ptr == nullptr)
    {
        return;
    }
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

void LinkedStr::removeLast() 
{
    if (ptr == nullptr)
    {
        return; 
    }
    if (ptr->next == nullptr)
    { 
        delete ptr;
        ptr = nullptr;
        return;
    }
    Node* temp = ptr;
    Node* prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    delete temp;
}

void LinkedStr::remove(int k)
{
    if (ptr == nullptr) 
    {
        return; 
	}
    Node* temp = ptr;
    Node* prev = nullptr;
    if (temp->info == k)
    {
        ptr = temp->next;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->info != k) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr) 
    {
        return;
    }
    prev->next = temp->next;
    delete temp;
}