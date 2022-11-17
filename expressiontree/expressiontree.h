//
// Created by TyxTang on 2022/11/3.
//

#ifndef EXPRESSIONTREE_EXPRESSIONTREE_H
#define EXPRESSIONTREE_EXPRESSIONTREE_H

#endif //EXPRESSIONTREE_EXPRESSIONTREE_H

#include <String>
#include "binders.h"
#include "linkstack.h"
using namespace std;
class ExpressionTree{
private:
    string expstr;
    StNode<char> * root;
    int comp(char c1, char c2);
    double ComputeHelp (StNode<char>);
public:
    ExpressTree(string exp);
    CreateTree();
    double Compute();
};
ExpressionTree::ExpressionTree(string exp){
    expstr = exp + "#";
}
ExpressionTree::CreateTree(){
    linkstack<char> optr;
    linkstack<StNode<char>*> expt;
    int i = 0,k;
    char e;
    BTNode<char> * p,* a , * b;
    optr.Push('#');
    while (optr.GetTop() != '#' || expstr[i] != '#'){
        if (expstr[i] >= '0' && expstr[i] <= '9'){
            k = 0;
            while (expstr[i] >= '0' && expstr[i] <= '9'){
                k = k * 10 + expstr[i] - '0';
                i++;
            }
            p = new StNode<char>(k);
            expt.Push(p);
        }
        else{
            switch (comp(optr.GetTop(),expstr[i])){
                case '<':
                    optr.Push(expstr[i]);
                    i++;
                    break;
                case '=':
                    optr.Pop();
                    i++;
                    break;
                case '>':
                    optr.Pop();
                    b = expt.Pop();
                    a = expt.Pop();
                    p = new StNode<char>(optr.GetTop(),a,b);
                    expt.Push(p);
                    break;
            }
        }
    }
    expt.GetTop(root);
}
int ExpressionTree::comp(char c1, char c2){
    switch (c1){
        case '+':
        case '-':
            if (c2 == '*'|| c2 == '/' || c2 == '(' )
                return -1;
            else
                return 1;
            break;
        case '*':
        case '/':
            if (c2 == '(')
                return -1;
            else
                return 1;
            break;
        case '(':
            if (c2 == ')')
                return 0;
            else
                return -1;
            break;
        case ')':
            return 1;
            break;
        case '#':
            if (c2 == '#')
                return 0;
            else
                return -1;
            break;
    }
}
double ExpressionTree::Compute(){
    return ComputeHelp(root);
}
double ExpressionTree::ComputeHelp(BTNode<char> * r){
    if (r->data >= '0' && r->data <= '9')
        return r->data;
    else{
        double a = ComputeHelp(r->lchild);
        double b = ComputeHelp(r->rchild);
        switch (r->data){
            case '+':
                return a + b;
                break;
            case '-':
                return a - b;
                break;
            case '*':
                return a * b;
                break;
            case '/':
                return a / b;
                break;
        }
    }
    return value;
}