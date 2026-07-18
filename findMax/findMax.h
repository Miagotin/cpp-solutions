#ifndef FIND_MAX_H
#define FIND_MAX_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstddef>

template <typename T>
T findMax(const std::vector<T>& a, std::size_t left, std::size_t right) {
    if (left >= right) {
        throw std::invalid_argument("Invalid range or empty array");
    }

    if (right - left == 1) {
        return a[left];
    }

    if (right - left == 2) {
        return std::max(a[left], a[left + 1]);
    }

    std::size_t mid = left + (right - left) / 2;

    T maxLeft = findMax(a, left, mid);
    T maxRight = findMax(a, mid, right);

    return std::max(maxLeft, maxRight);
}

template <typename T>
T findMax(const std::vector<T>& a) {
    if (a.empty()) {
        throw std::invalid_argument("empty vector");
    }
    return findMax(a, 0, a.size());
}

#endif // FIND_MAX_H
