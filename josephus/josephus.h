//
// Created by TyxTang on 2022/10/13.
//

#ifndef JOSEPHUS_JOSEPHUS_H
#define JOSEPHUS_JOSEPHUS_H

#endif //JOSEPHUS_JOSEPHUS_H

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};

class Josephus{
    private:
        Node *first;
    public:
        explicit Josephus(int n);
        void Solve(int m);

};

Josephus::Josephus(int n) {
    first = new Node;
    first->data = 1;
    first->next = NULL;
    Node *p, *pre = first;
    for (int i = 2; i <= n; i++) {
        p = new Node;
        p->data = i;
        p->next = NULL;
        pre->next = p;
        pre = p;
    }
    p->next = first;
}

void Josephus ::Solve(int m) {
    Node *pre = NULL;
    Node *p = first;
    int count = 1;
    cout<<"出列顺序为："<<endl;
    while(p->next != p){
        if(count<m){
            pre = p;
            p = p->next;
            count++;
        }
        else{
            cout<<p->data<<" ";
            pre->next = p->next;
            delete p;
            p = pre->next;
            count = 1;
        }
    }
    cout<<p->data<<endl;
    delete p;
}
