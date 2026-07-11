#include <iostream>
#include "find_max.h"
using namespace std;

int main() {
    vector<int> data = {3, 5, 1, 9, 2};
    try {
        cout << "Max element: " << findMax(data) << std::endl;
    } catch (const std::exception& e) {
        cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
