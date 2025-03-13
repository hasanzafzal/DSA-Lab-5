#include "List.h"

template <class ItemType>
List<ItemType>::List() 
{
    listptr = nullptr;
}

template <class ItemType>
List<ItemType>::~List() 
{
    NODEPTR p, q;
    if (emptyList())
    {
        return;
    }
    for (p = listptr, q = p->next; p != nullptr; p = q, q = (p ? p->next : nullptr)) 
    {
        delete p;
    }
}

template <class ItemType>
bool List<ItemType>::emptyList() 
{
    return (listptr == nullptr);
}

template <class ItemType>
void List<ItemType>::insertafter(ItemType oldvalue, ItemType newvalue)
{
    NODEPTR p, q, prev;
    p = listptr;
    prev = nullptr;
    while (p != nullptr && p->info != oldvalue) 
    {
        prev = p;
        p = p->next;
    }
    if (p == nullptr)
    {
        cout << "ERROR: value sought is not in the list." << endl;
        return;
    }
    q = new node;
    q->info = newvalue;
    if (prev == nullptr) 
    {
        q->next = p;
        listptr = q;
    }
    else 
    {
        q->next = p->next;
        p->next = q;
    }
}

template <class ItemType>
void List<ItemType>::push(ItemType newvalue)
{
    NODEPTR p = new node;
    p->info = newvalue;
    if (listptr == nullptr)
    {
        listptr = p;
        p->next = nullptr;
    }
    else 
    {
        NODEPTR q = listptr;
        while (q->next != nullptr) 
        {
            q = q->next;
        }
        q->next = p;
        p->next = nullptr;
    }
}

template <class ItemType>
void List<ItemType>::deleteItem(ItemType oldvalue) 
{
    NODEPTR p, q;
    for (q = nullptr, p = listptr; p != nullptr && p->info != oldvalue; q = p, p = p->next);
    if (p == nullptr) 
    {
        cout << "ERROR: value sought is not in the list." << endl;
        return;
    }
    if (q == nullptr)
    {
        listptr = p->next;
    }
    else
    {
        q->next = p->next;
    }
    delete p;
}

template <class ItemType>
ItemType List<ItemType>::pop() 
{
    if (emptyList()) 
    {
        cout << "ERROR: the list is empty." << endl;
        exit(1);
    }

    NODEPTR p = listptr;
    listptr = p->next;
    ItemType x = p->info;
    delete p;
    return x;
}

template <class ItemType>
void List<ItemType>::printList() 
{
    NODEPTR p = listptr;
    while (p != nullptr) 
    {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

template class List<int>;