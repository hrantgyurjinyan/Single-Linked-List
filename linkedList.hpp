#pragma once

#include <iostream>
#include "node.hpp"

template <typename T>
class LinkedList 
{
private:
    Node<T>* head;

    Node<T>* getTail(Node<T>* cur);
    Node<T>* partition(Node<T>* head, Node<T>* end, Node<T>** newHead, Node<T>** newEnd);
    Node<T>* quickSortRecur(Node<T>* head, Node<T>* end);
    Node<T>* sortedMerge(Node<T>* a, Node<T>* b);
    void split(Node<T>* source, Node<T>** front, Node<T>** back);

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void append(T data);
    void printList() const;

    void quickSort();
    void mergeSort();
    void bubbleSort();
};

template <typename T>
LinkedList<T>::~LinkedList() 
{
    Node<T>* current = head;
    while (current != nullptr) 
    {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::append(T data) 
{
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

template <typename T>
void LinkedList<T>::printList() const 
{
    Node<T>* temp = head;
    while (temp != nullptr) 
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
Node<T>* LinkedList<T>::getTail(Node<T>* cur) 
{
    while (cur != nullptr && cur->next != nullptr) 
    {
        cur = cur->next;
    }
    return cur;
}

template <typename T>
Node<T>* LinkedList<T>::partition(Node<T>* head, Node<T>* end, Node<T>** newHead, Node<T>** newEnd) 
{
    Node<T>* pivot = end;
    Node<T>* prev = nullptr;
    Node<T>* cur = head;
    Node<T>* tail = pivot;

    while (cur != pivot) 
    {
        if (cur->data < pivot->data) 
        {
            if ((*newHead) == nullptr) 
            {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        } else 
        {
            if (prev) 
            {
                prev->next = cur->next;
            }
            Node<T>* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == nullptr) 
    {
        (*newHead) = pivot;
    }

    (*newEnd) = tail;

    return pivot;
}

template <typename T>
Node<T>* LinkedList<T>::quickSortRecur(Node<T>* head, Node<T>* end) 
{
    if (!head || head == end) 
    {
        return head;
    }

    Node<T>* newHead = nullptr;
    Node<T>* newEnd = nullptr;

    Node<T>* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node<T>* tmp = newHead;
        while (tmp->next != pivot) {
            tmp = tmp->next;
        }
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

template <typename T>
void LinkedList<T>::quickSort() 
{
    head = quickSortRecur(head, getTail(head));
}

template <typename T>
Node<T>* LinkedList<T>::sortedMerge(Node<T>* a, Node<T>* b) 
{
    if (!a) 
    {
        return b;
    }
    if (!b) 
    {
        return a;
    }

    if (a->data <= b->data) 
    {
        a->next = sortedMerge(a->next, b);
        a->next->next = nullptr;
        a = a;
    } else 
    {
        b->next = sortedMerge(a, b->next);
        b->next->next = nullptr;
        a = b;
    }

    return a;
}

template <typename T>
void LinkedList<T>::split(Node<T>* source, Node<T>** front, Node<T>** back) 
{
    Node<T>* fast;
    Node<T>* slow;
    slow = source;
    fast = source->next;

    while (fast != nullptr) 
    {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

template <typename T>
void LinkedList<T>::mergeSort() 
{
    Node<T>* headRef = head;
    if ((headRef == nullptr) || (headRef->next == nullptr)) 
    {
        return;
    }

    Node<T>* a;
    Node<T>* b;

    split(headRef, &a, &b);

    LinkedList<T> listA;
    listA.head = a;
    listA.mergeSort();

    LinkedList<T> listB;
    listB.head = b;
    listB.mergeSort();

    head = sortedMerge(listA.head, listB.head);
}

// Bubble Sort

template <typename T>
void LinkedList<T>::bubbleSort() 
{
    if (head == nullptr) {
        return;
    }

    bool swapped;
    Node<T>* ptr1;
    Node<T>* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) 
        {
            if (ptr1->data > ptr1->next->data) {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

