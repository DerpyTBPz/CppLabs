#ifndef CLIST_H
#define CLIST_H

struct Node
{
    int data;
    Node* prev;
    Node* next;    
};

class CList
{
private:
    Node* head;
    Node* tail;
    int size;    

public:
    CList();
    CList(const CList& other);
    ~CList();
    CList& operator=(const CList& other);

    void insertBegin(int value);
    void insertEnd(int value);
    bool insertAfter(int afterValue, int value);
    int popBegin();
    int popEnd();
    bool deleteElem(int value);
    bool isEmpty();
    void sort();
    void show(bool reverse = false);



};

#endif