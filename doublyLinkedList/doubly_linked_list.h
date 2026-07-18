#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <initializer_list>
#include <iostream>
#include <cstddef>

template <typename T>
struct Node {
    T value;
    Node* prev;
    Node* next;
};

template <typename T>
struct LinkedList {
    Node<T>* head;
    Node<T>* tail;
    std::size_t size;
    
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    LinkedList(std::initializer_list<T> init) : head(nullptr), tail(nullptr), size(0) {
        for(auto value : init) {
            this->push_back(value);
        }
    }
    
    LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), size(0) {
        Node<T>* current = other.head;
        while(current != nullptr) {
            this->push_back(current->value);
            current = current-> next;
        }
    }
    
    ~LinkedList() {
        clear();
    }
    
    void push_back(const T& value) {

        if(size == 0) {
            Node<T>* newNode = new Node<T>{value, nullptr, nullptr};
            
            head = tail = newNode;
        }
        else {
            Node<T>* newNode = new Node<T>{value, tail, nullptr};
            
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void push_front(const T& value) {
        
        if(size == 0) {
            Node<T>* newNode = new Node<T>{value, nullptr, nullptr};
            
            head = tail = newNode;
        }
        else {
            Node<T>* newNode = new Node<T>{value, nullptr, head};
            
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    
    void pop_back() {
        
        if(size == 0) {
            return;
        }
        
        Node<T>* prevTail = tail;
        
        if(size == 1) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete prevTail;
        size--;
    }
    
    void pop_front() {
        
        if(size == 0) {
            return;
        }
        
        Node<T>* prevHead = head;
        
        if(size == 1) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete prevHead;
        size--;
    }
    
    void clear() {
        Node<T>* current = head;
        while(current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }
    
    size_t getSize() const {
        return size;
    }
    
    bool empty() const {
        return !size;
    }
    
    void print() const {
        Node<T>* current = head;
        while(current != nullptr) {
            std::cout << current->value;
            if(current->next != nullptr) {
                std::cout << ' ';
            }
            current = current->next;
        }
        std::cout << std::endl;
    }
    
};

#endif // DOUBLY_LINKED_LIST_H
