#pragma once

template <typename T>
class Node 
{
public:
    T data;
    Node* next;
public:
    Node(T data) 
    {
        this->data = data;
        this->next = nullptr;
    }
    
};