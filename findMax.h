#ifndef FIND_MAX_H
#define FIND_MAX_H

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstddef> // Для size_t

// Основная рекурсивная функция Divide and Conquer
template <typename T>
T findMax(const std::vector<T>& a, std::size_t left, std::size_t right) {
    if (left >= right) {
        throw std::invalid_argument("Некорректный диапазон или пустой массив");
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

// Функция-обертка для запуска без ручного указания индексов
template <typename T>
T findMax(const std::vector<T>& a) {
    if (a.empty()) {
        throw std::invalid_argument("Вектор пуст");
    }
    return findMax(a, 0, a.size());
}

#endif // FIND_MAX_H
