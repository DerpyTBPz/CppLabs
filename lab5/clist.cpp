#include <iostream>
#include "clist.h"

CList::CList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

CList::CList(const CList& other) 
{
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node* current = other.head;
    while (current != nullptr) 
    {
        insertEnd(current->data);
        current = current->next;
    }
}

CList::~CList() 
{
    while (!isEmpty()) 
    {
        popBegin();
    }
}

CList& CList::operator=(const CList& other) 
{
    if (this != &other) 
    {        
        while (!isEmpty()) 
        {
            popBegin();
        }
        
        Node* current = other.head;
        while (current != nullptr) 
        {
            insertEnd(current->data);
            current = current->next;
        }
    }
    return *this;
}

void CList::insertBegin(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (isEmpty()) 
    {
        tail = newNode;
    } 
    else 
    {
        head->prev = newNode;
    }

    head = newNode;
    size++;
}

void CList::insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (isEmpty()) 
    {
        head = newNode;
    } 
    else 
    {
        tail->next = newNode;
    }

    tail = newNode;
    size++;
}

bool CList::insertAfter(int afterValue, int value)
{
    Node* current = head;

    while (current != nullptr) 
    {
        if (current->data == afterValue) 
        {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->prev = current;
            newNode->next = current->next;

            if (current->next != nullptr) 
            {
                current->next->prev = newNode;
            } 
            else 
            {
                tail = newNode;
            }

            current->next = newNode;

            size++;
            return true;
        }

        current = current->next;
    }

    return false;
}

int CList::popBegin()
{
    if (isEmpty()) 
    {
        throw std::runtime_error("Cannot pop from an empty list");
    }

    Node* nodeToRemove = head;
    int value = nodeToRemove->data;

    head = head->next;
    if (head != nullptr) 
    {
        head->prev = nullptr;
    } 
    else 
    {
        tail = nullptr;
    }

    delete nodeToRemove;

    size--;
    return value;
}

int CList::popEnd()
{
    if (isEmpty()) 
    {
        throw std::runtime_error("Cannot pop from an empty list");
    }

    Node* nodeToRemove = tail;
    int value = nodeToRemove->data;

    tail = tail->prev;
    if (tail != nullptr) 
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }

    delete nodeToRemove;

    size--;
    return value;
}

bool CList::deleteElem(int value)
{
    Node* current = head;

    while (current != nullptr) 
    {
        if (current->data == value) 
        {
            if (current->prev != nullptr) 
            {
                current->prev->next = current->next;
            } 
            else 
            {
                head = current->next;
            }

            if (current->next != nullptr) 
            {
                current->next->prev = current->prev;
            } 
            else 
            {
                tail = current->prev;
            }

            delete current;

            size--;
            return true;
        }

        current = current->next;
    }

    return false;
}

bool CList::isEmpty()
{
    return size == 0;
}

void CList::sort()
{
    if (isEmpty()) 
    {
        return;
    }

    bool swapped;
    Node* current;
    Node* lastNode = nullptr;

    do 
    {
        swapped = false;
        current = head;

        while (current->next != lastNode) 
        {
            if (current->data > current->next->data) 
            {
                std::swap(current->data, current->next->data);
                swapped = true;
            }

            current = current->next;
        }

        lastNode = current;
    } 
    while (swapped);
}

void CList::show(bool reverse)
{
    if (isEmpty()) 
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    if (reverse) 
    {
        Node* current = tail;
        while (current != nullptr) 
        {
            std::cout << current->data << " ";
            current = current->prev;
        }
    } 
    else 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
    }

    std::cout << std::endl;
}





