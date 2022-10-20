//
// Created by TyxTang on 2022/10/20.
//

#ifndef CONVERSION_SQSTACK_H
#define CONVERSION_SQSTACK_H

#endif //CONVERSION_SQSTACK_H

#include<iostream>
using namespace std;

template <typename T>
class SqStack {
    int top;
    int maxSize;
    T *elem;
public:
    SqStack(int size = 10);
    ~SqStack();
    bool Push(T e);
    bool Pop(T &e);
    bool Empty();
    bool Full();
    void Clear();
};

template <typename T>
SqStack<T>::SqStack(int size) {
    maxSize = size;
    elem = new T[maxSize];
    top = -1;
}

template <typename T>
SqStack<T>::~SqStack() {
    delete [] elem;
}

template <typename T>
bool SqStack<T>::Empty() {
    return top == -1;
}

template <typename T>
bool SqStack<T>::Full() {
    return top == maxSize - 1;
}

template <typename T>
void SqStack<T>::Clear() {
    top = -1;
}

template <typename T>
bool SqStack<T>::Push(T e) {
    if (top==maxSize-1) {
        return false;
    }
    elem[++top] = e;
    return true;
}

template <typename T>
bool SqStack<T>::Pop(T &e) {
    if (Empty()) {
        return false;
    }
    e = elem[top--];
    return true;
}






