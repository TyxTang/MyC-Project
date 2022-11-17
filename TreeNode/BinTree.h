//
// Created by TyxTang on 2022/11/17.
//

#ifndef TREENODE_BINTREE_H
#define TREENODE_BINTREE_H

#endif //TREENODE_BINTREE_H
#include <iostream>
#include <string>
using namespace std;
template<typename T>
struct BTNode
{
    T data;
    BTNode<T>* lchild;
    BTNode<T>* rchild;
};
template<typename T>
class BinTree
{
private:
    BTNode<T>* root;
    void InOrder(BTNode<T>* r, void(*visit)(T));
    void PreOrder(BTNode<T>* r, void(*visit)(T));
    void PostOrder(BTNode<T>* r, void(*visit)(T));
    int NodeCount(BTNode<T>* r);
public:
    BinTree(T e);
    BTNode<T>* Getroot();
    int BT_NodeCount();
    bool GetElem(BTNode<T>* p, T& e);
    void InOrderTraverse(void(*visit)(T));
    void PreOrderTraverse(void(*visit)(T));
    void PostOrderTraverse(void(*visit)(T));
    void InsertLeftChild(BTNode<T>* p, T e);
    void InsertRightChild(BTNode<T>* p, T e);
    BTNode<T>* LchildNode(BTNode<T>* p);
    BTNode<T>* RchildNode(BTNode<T>* p);
    BTNode<T>* ParentNode(BTNode<T>* p);


};
template<typename T>
BinTree<T>::BinTree(T e)
{
    root = new BTNode<T>;
    root->data = e;
    root->lchild = NULL;
    root->rchild = NULL;

}
template<typename T>
BTNode<T>* BinTree<T>::Getroot()
{
    return root;

}
template<typename T>
int BinTree<T>::BT_NodeCount()
{
    return NodeCount(root);

}
template<typename T>
int BinTree<T>::NodeCount(BTNode<T>* r)
{
    if (r == NULL)
        return 0;
    else
        return NodeCount(r->lchild) + NodeCount(r->rchild) + 1;
}
template<typename T>
bool BinTree<T>::GetElem(BTNode<T>* p, T& e)
{
    if (p == NULL)
    {
        return false;
        e = p->data;
        return true;
    }
}
template<typename T>
BTNode<T>* BinTree<T>::LchildNode(BTNode<T>* p)
{
    return p->lchild;
}
template<typename T>
BTNode<T>* BinTree<T>::RchildNode(BTNode<T>* p)
{
    return p->rchild;
}
template<typename T>
BTNode<T>* BinTree<T>::ParentNode(BTNode<T>* p)
{
    return parent(root, p);
}
template<typename T>
void BinTree<T>::InsertLeftChild(BTNode<T>* p, T e)
{
    if (p != NULL)
    {
        BTNode<T>* child = new BTNode<T>;
        child->data = e;
        child->lchild = NULL;
        child->rchild = NULL;
        if (p->lchild != NULL)
            child->lchild = p->lchild;
        p->lchild = child;
    }
}
template<typename T>
void BinTree<T>::InsertRightChild(BTNode<T>* p, T e)
{
    if (p != NULL)
    {
        BTNode<T>* child = new BTNode<T>;
        child->data = e;
        child->lchild = NULL;
        child->rchild = NULL;
        if (p->rchild != NULL)
            child->rchild = p->rchild;
        p->rchild = child;
    }
}
template<typename T>
void BinTree<T>::InOrderTraverse(void(*visit)(T))
{
    InOrder(root, visit);
}
template<typename T>
void BinTree<T>::InOrder(BTNode<T>* r, void(*visit)(T))
{
    if (r != NULL)
    {
        InOrder(r->lchild, visit);
        (*visit)(r->data);
        InOrder(r->rchild, visit);
    }
}
template<typename T>
void BinTree<T>::PreOrderTraverse(void(*visit)(T))
{
    PreOrder(root, visit);
}
template<typename T>
void BinTree<T>::PreOrder(BTNode<T>* r, void(*visit)(T))
{
    if (r != NULL)
    {
        (*visit)(r->data);
        PreOrder(r->lchild, visit);
        PreOrder(r->rchild, visit);
    }
}
template<typename T>
void BinTree<T>::PostOrderTraverse(void(*visit)(T))
{
    PostOrder(root, visit);
}
template<typename T>
void BinTree<T>::PostOrder(BTNode<T>* r, void(*visit)(T))
{
    if (r != NULL)
    {
        PostOrder(r->lchild, visit);
        PostOrder(r->rchild, visit);
        (*visit)(r->data);
    }
}