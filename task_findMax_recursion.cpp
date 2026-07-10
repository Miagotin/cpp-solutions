#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Основная рекурсивная функция Divide and Conquer
template <typename T>
T findMax(const std::vector<T>& a, size_t left, size_t right) {
    // Защита от некорректных входных данных
    if (left >= right) {
        throw std::invalid_argument("Некорректный диапазон или пустой массив");
    }

    // один элемент
    if (right - left == 1) {
        return a[left];
    }

    // два элемента
    if (right - left == 2) {
        return std::max(a[left], a[left + 1]);
    }

    size_t mid = left + (right - left) / 2;

    T maxLeft = findMax(a, left, mid);
    T maxRight = findMax(a, mid, right);

    return std::max(maxLeft, maxRight);
}

// функция-обертка для запуска без ручного указания индексов
template <typename T>
T findMax(const std::vector<T>& a) {
    if (a.empty()) {
        throw std::invalid_argument("Вектор пуст");
    }
    return findMax(a, 0, a.size());
}

int main() {
    // Тестирование с double
    std::vector<double> dataDouble = {4.5, 12.1, 7.8, 25.4, 9.2, 18.9, 3.1};
    double answerDouble = findMax(dataDouble);
    std::cout << "Max (double) = " << answerDouble << '\n';

    // Тестирование с float
    std::vector<float> dataFloat = {-3.4f, -1.2f, -9.8f, -0.5f};
    float answerFloat = findMax(dataFloat);
    std::cout << "Max (float) = " << answerFloat << '\n';

    return 0;
}