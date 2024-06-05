#include <iostream>
#include "linkedList.hpp"

int main() 
{
    LinkedList<int> list;
    list.append(3);
    list.append(4);
    list.push_front(2);
    list.push_front(1);
    list.printList();  

    list.reverse();
    list.printList();  

    list.pop_front();
    list.printList();  

    list.reverse();
    list.printList();  

    LinkedList<int> list1;
    list1.append(10);
    list1.append(20);
    list1.append(30);
    list1.append(40);
    list1.append(50);
    list1.append(60);
    list1.append(70);
    list1.append(80);
    list1.append(90);
    list1.append(100);
    list1.printList(); 

    int n = 7;
    int res = list1.nFromEnd(n);

    std::cout << res << std::endl;

    return 0;
}
