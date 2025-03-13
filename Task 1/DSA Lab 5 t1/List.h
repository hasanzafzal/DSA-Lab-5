#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <class ItemType>
class List 
{
private:
    struct node
    {
        ItemType info;
        struct node* next;
    };
    typedef struct node* NODEPTR;
    NODEPTR listptr;
public:
    List();
    ~List();
    bool emptyList();
    void insertafter(ItemType oldvalue, ItemType newvalue);
    void deleteItem(ItemType oldvalue);
    void push(ItemType newvalue);
    ItemType pop();
    void printList();
};

#endif