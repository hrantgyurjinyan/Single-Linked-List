#pragma once

#include <iostream>
#include "node.hpp"

template <typename T>
class LinkedList 
{
private:
    Node<T>* head;

public:
    LinkedList() 
    {
        head = nullptr;
    }

    ~LinkedList();

    void append(T data);
    void push_front(T data);
    void pop_front();
    void printList();
    void reverse();
    T nFromEnd(int n);

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
void LinkedList<T>::push_front(T data) 
{
    Node<T>* newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void LinkedList<T>::pop_front() 
{
    if (head == nullptr) 
    {
        std::cerr << "List is empty, nothing to pop." << std::endl;
        return;
    }
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::reverse() 
{
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;
    while (current != nullptr) 
    {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    head = prev;
}

template <typename T>
T LinkedList<T>::nFromEnd(int n) 
{
    if (head == nullptr || n <= 0) 
    {
        std::cerr << "Invalid argument" << std::endl;
        return 1;
    }

    Node<T>* mainPtr = head;
    Node<T>* refPtr = head;

    for (int i = 0; i < n; ++i) 
    {
        if (refPtr == nullptr) 
        {
            std::cerr << "The list is shorter than n" << std::endl;
            return 2;
        }
        refPtr = refPtr->next;
    }

    while (refPtr != nullptr) 
    {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    if (mainPtr == nullptr) 
    {
        std::cerr << "n is larger than elements count" << std::endl;
        return 3;
    }

    return mainPtr->data;
}


template <typename T>
void LinkedList<T>::printList() 
{
    Node<T>* temp = head;
    while (temp != nullptr) 
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


