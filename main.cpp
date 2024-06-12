#include <iostream>
#include "linkedList.hpp"

int main() {
    LinkedList<int> list;
    list.append(4);
    list.append(3);
    list.append(7);
    list.append(1);
    list.append(9);
    list.append(2);

    std::cout << "Original List: ";
    list.printList();

    list.quickSort();
    std::cout << "QuickSort List: ";
    list.printList();

    list.append(6);
    list.append(5);

    list.mergeSort();
    std::cout << "MergeSort List: ";
    list.printList();

    list.append(8);
    list.append(0);

    list.bubbleSort();
    std::cout << "BubbleSort List: ";
    list.printList();

    return 0;
}
