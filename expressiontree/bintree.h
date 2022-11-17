//
// Created by TyxTang on 2022/11/4.
//

#ifndef EXPRESSIONTREE_BINTREE_H
#define EXPRESSIONTREE_BINTREE_H

#endif //EXPRESSIONTREE_BINTREE_H

#include<iostream>
using namespace std;

template<class Type>class BinTree;

template<class Type>
class TreeNode
{
protected:
    friend class BinTree<Type>;
    TreeNode():lchild(NULL),rchild(NULL){}
    Type data;
    TreeNode *lchild;  //左，右子树
    TreeNode *rchild;
};

template<class Type>
class BinTree
{
    friend void BinTree_PRE(BinTree<Type>& BinTreeOPP);  //友元函数
    friend void BinTree_INO(BinTree<Type>& BinTreeOPP);
    friend void BinTree_POS(BinTree<Type>& BinTreeOPP);
    friend void BinTree_Destroy(BinTree<Type>& BinTreeOPP);
public:
    BinTree():root(NULL){}
    void CreatTree();               //创建二叉树,主过程
    void CreatTree(TreeNode<Type>* child,int k); //子过程
    void PreTree(TreeNode<Type> *point);     //先序遍历二叉树
    void InoTree(TreeNode<Type> *point);  //中序遍历二叉树
    void PosTree(TreeNode<Type> *point);  //后序遍历二叉树
    void Destroy(TreeNode<Type> *point);     //销毁二叉树
    bool ISEmpty();
protected:
    TreeNode<Type>* root;
};


template<class Type>
void BinTree<Type>::CreatTree()
{
    CreatTree(root,1);
}

template<class Type>
void BinTree<Type>::CreatTree(TreeNode<Type>* child,int k)
{
    TreeNode<Type>* point;
    point=new TreeNode<Type>;
    cout<<"输入节点数据项 :";
    cin>>point->data;
    switch(k)
    {
        case 1: root=point; break;
        case 2: child->lchild=point;break;
        case 3: child->rchild=point;break;
    }

    char temp;
    cout<<"该"<<point->data<<"节点是否有左子树 Y / 任意键 :";
    cin>>temp;
    if(temp=='y'||temp=='Y')
    {
        CreatTree(point,2);
    }

    cout<<"该"<<point->data<<"节点是否有右子树 Y / 任意键 :";
    cin>>temp;
    if(temp=='y'||temp=='Y')
    {
        CreatTree(point,3);
    }
}

template<class Type>
void BinTree<Type>::PreTree(TreeNode<Type> *point)
{
    if(point!=NULL)
    {
        cout<<" "<<point->data;
        PreTree(point->lchild);
        PreTree(point->rchild);
    }
}


template<class Type>
void BinTree<Type>::InoTree(TreeNode<Type> *point)
{
    if(point!=NULL)
    {

        InoTree(point->lchild);
        cout<<" "<<point->data;
        InoTree(point->rchild);
    }
}

template<class Type>
void BinTree<Type>::PosTree(TreeNode<Type> *point)
{
    if(point!=NULL)
    {

        PosTree(point->lchild);
        PosTree(point->rchild);
        cout<<" "<<point->data;
    }
}


template<class Type>
bool BinTree<Type>::ISEmpty()
{
    return root==NULL;
}

template<class Type>
void BinTree<Type>::Destroy(TreeNode<Type> *point)
{
    if(point!=NULL)
    {
        Destroy(point->lchild);
        Destroy(point->rchild);
        delete point;
    }
}