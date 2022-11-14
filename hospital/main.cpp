#include <iostream>
#include "hospital.h"
using namespace std;

int main() {
    int n,e;
    int i,j,k,w;
    cout<<"请输入顶点的个数和边的个数：";
    cin>>n>>e;
    char * vs = new char[n];
    int ** edge = (int **) new int*[n];
    cout<<"请输入顶点的元素：";
    for (i = 0; i < n; i++) {
        cin >> vs[i];
    }
    for (i = 0; i < n; i++) {
        edge[i] = new int[n];
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if(i == j) {
                edge[i][j] = 0;
            } else {
                edge[i][j] = infinity;
            }
        }
    }
    for (k = 0; k < e; k++) {
        cout<<"请输入边依附的顶点编号和边的权值：";
        cin >> i >> j >> w;
        edge[i][j] = w;
        edge[j][i] = w;
    }
    Hospital h(vs,edge,n);
    int center_Point = h.Center();
    cout<<"建立医院的最佳位置是："<<vs[center_Point]<<endl;
    for(int i = 0; i < n; i++) {
        delete [] edge[i];
    }
    delete [] edge;
    delete [] vs;
    return 0;
}
