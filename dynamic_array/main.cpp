#include "dynamic_array.h"
#include <iostream>

int main() {
    DynamicArray arr;
    arr.push_back(108);
    arr.push_back(210);
    arr.push_back(1137);

    arr.print();

    std::cout << "size: " << arr.GetSize() << std::endl;
    std::cout << "capacity: " << arr.GetCapacity() << std::endl;

    arr.push_back(10138);
    arr.push_back(107);
    arr.push_back(3843);

    arr.print();

    arr.pop_back();
    arr.pop_back();

    arr.print();


    return 0;
}