#include "doubly_linked_list.h"

int main()
{
    LinkedList<int> list1;
    LinkedList<int> list2;

    list1.push_back(10);
    list1.push_back(20);
    list1.push_front(5);

    list1.print();

    list2 = list1;
    list1.clear();

    list2.pop_front();
    list2.print();

    list2.pop_back();
    list2.print();

    return 0;
}
