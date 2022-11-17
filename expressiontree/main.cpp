
#include "expressiontree.h"
#include <iostream>
using namespace std;
int main(){
    string str;
    double result;
    cout<<"Please input the expression:"<<endl;
    cin>>str;
    ExpressionTree exp1(str);
    exp1.CreateTree();
    result = exp1.Compute();
    cout<<"The result is:"<<result<<endl;
    return 0;
}
