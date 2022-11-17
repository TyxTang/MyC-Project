//
// Created by TyxTang on 2022/10/20.
//

#ifndef LINKSTACK_LINKSTACK_H
#define LINKSTACK_LINKSTACK_H

#endif //LINKSTACK_LINKSTACK_H

#include <iostream>
using namespace std;

template <typename T>
struct StNode {
    T data;
    StNode<T> *next;
};

template <typename T>
class linkstack {
private:
    StNode<T> *top;
public:
    linkstack();
    linkstack(const linkstack<T> &ls);
    ~linkstack();
    int Length() const;
    bool Empty() const;
    bool Push(T e);
    bool Pop(T &e);
    void Clear();
    bool GetTop(T &e) const;
};

template <typename T>
linkstack<T>::linkstack() {
    top = NULL;
}

template <typename T>
linkstack<T>::linkstack(const linkstack<T> &lst) {
    if (lst.Empty()){
        top = NULL;
    }
    else {
        StNode<T> *p = lst.top;
        StNode<T> *q = top = new StNode<T>;
        while (p->next != NULL){
            q->next = new StNode<T>;
            q = q->next;
            p = p->next;
        }
        q->next = NULL;
    }
}

template <typename T>
linkstack<T>::~linkstack() {
    StNode<T> *p;
    while (top != NULL){
        p = top;
        top = top->next;
        delete p;
    }
}

template <typename T>
int linkstack<T>::Length() const {
    StNode<T> *p = top;
    int len = 0;
    while (p != NULL){
        len++;
        p = p->next;
    }
    return len;
}

template <typename T>
bool linkstack<T>::Empty() const {
    return top == NULL;
}

template <typename T>
void linkstack<T>::Clear() {
    StNode<T> *p;
    while (top != NULL){
        p = top;
        top = top->next;
        delete p;
    }
}

template <typename T>
bool linkstack<T>::Push(T e) {
    StNode<T> *p = new StNode<T>;
    p->data = e;
    p->next = top;
    top = p;
    return true;
}

template <typename T>
bool linkstack<T>::Pop(T &e) {
    if (top == NULL){
        return false;
    }
    StNode<T> *p = top;
    e = p->data;
    top = top->next;
    delete p;
    return true;
}

template <typename T>
bool linkstack<T>::GetTop(T &e) const {
    if (top == NULL){
        return false;
    }
    e = top->data;
    return true;
}

