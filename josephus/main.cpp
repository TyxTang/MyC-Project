#include "josephus.h"
int main(){
    int n,m;
    cout<<"请输入n和m的值"<<endl;
    cin>>n>>m;
    Josephus j(n);
    j.Solve(m);
    cout<<endl;
    return 0;
}
