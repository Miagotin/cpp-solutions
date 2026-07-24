#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>

class DynamicArray {
private:
    std::size_t arr_size_;
    std::size_t space_;
    int* arr_;

public:
    DynamicArray(std::size_t space = 0) {
        arr_size_ = 0;
        space_ = space;
        if(!space) {
            arr_ = nullptr;
        }
        else {
            arr_ = new int[space_];
        }
    }

    DynamicArray(const DynamicArray& other) {
        space_ = other.space_;
        arr_size_ = other.arr_size_;
        arr_ = new int[space_];
        for(std::size_t i = 0; i < arr_size_; ++i) {
            arr_[i] = other[i];
        }
    }

    ~DynamicArray() {
        delete[] arr_;
    }

    void push_back(int value) {
        if(arr_size_ == space_) {
            if(!space_) {
                space_ = 1;
            }
            else {
                space_ *= 2;
            }
            int* arr_new = new int[space_];
            for(std::size_t i = 0; i < arr_size_; ++i) {
                arr_new[i] = arr_[i];
            }
            delete[] arr_;
            arr_ = arr_new; 
        }
        arr_[arr_size_] = value;
        arr_size_++;
    }

    void pop_back() {
        if(arr_size_) {
            arr_size_--;
        }
    }

    void print() const {
        for(std::size_t i = 0; i < arr_size_; ++i) {
            if(i == 0) {
                std:: cout << arr_[i];
            }
            else {
                std::cout << ' ' << arr_[i];
            }
        }
        std::cout << std::endl;
    }

    std::size_t GetSize() const {
        return arr_size_;
    }

    std::size_t GetCapacity() const {
        return space_;
    }

    int& operator[](std::size_t idx) {
        return arr_[idx];
    }

    const int& operator[](std::size_t idx) const {
        return arr_[idx];
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if(this != &other) {
            delete[] arr_;

            space_ = other.space_;
            arr_size_ = other.arr_size_;

            if(!space_) {
                arr_ = nullptr;
            }
            else {
                arr_ = new int[space_];
            }

            for(std::size_t i = 0; i < arr_size_; ++i) {
                arr_[i] = other[i];
            }
        }
        return *this;
    }

    int& at(std::size_t idx) {
        if(idx >= arr_size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr_[idx];
    }

    const int& at(std::size_t idx) const {
        if(idx >= arr_size_) {
            throw std::out_of_range("Index out of bounds");
        }
        return arr_[idx];
    }

};