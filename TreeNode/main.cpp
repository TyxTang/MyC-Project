#include "BinTree.h"

void show(char e)
{
    cout << e << " ";
}
int main()
{
    BTNode<char>* p;
    BinTree<char>bt('A');
    p = bt.Getroot();
    bt.InsertLeftChild(p,'B');
    bt.InsertRightChild(p, 'C');
    p = bt.LchildNode(p);
    bt.InsertLeftChild(p, 'D');
    p = bt.Getroot();
    p = bt.RchildNode(p);
    bt.InsertLeftChild(p, 'E');
    bt.InsertRightChild(p, 'F');
    cout << "先序遍历序列：";
    bt.PreOrderTraverse(show);
    cout << endl;
    cout << "中序遍历序列：";
    bt.InOrderTraverse(show);
    cout << endl;
    cout << "后序遍历序列：";
    bt.PostOrderTraverse(show);
    cout << endl;
    return 0;
}