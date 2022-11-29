//
// Created by TyxTang on 2022/11/29.
//

#ifndef SCHOOLMAP_AMUNDIRGRAPH_H
#define SCHOOLMAP_AMUNDIRGRAPH_H

#endif //SCHOOLMAP_AMUNDIRGRAPH_H

template <typename T>
class AMUndirGraph
{
private :
    int vertexNum, edgeNum;
    int** matrix;
    T* vexs;
    bool* visited;
public :
    AMUndirGraph(T vs[], int n);
    ~AMUndirGraph();
    void DFSTraverse(void (*visit)(T));
    void BFSTraverse(void (*visit)(T));
    bool GetElem(int i, T& e);
    bool SetElem(int i, T e);
    int GetVexNum();
    int GetEdgeNum();
    int FirstAdjVex(int i);
    int NextAdjVex(int i, int j);
    void InsertEdge(int i, int j);
    void DeleteEdge(int i, int j);
    void Display();
};


#include <iostream>
using namespace std;
template<typename T>
AMUndirGraph<T>::AMUndirGraph(T vs[], int n)
{
    vertexNum = n;
    edgeNum = 0;
    vexs = new T[vertexNum];
    for (int i = 0; i < vertexNum; i++)
        vexs[i] = vs[i];
    visited = new bool[vertexNum];
    for (int i = 0; i < vertexNum; i++)
        visited[i] = false;
    matrix = (int**)new int* [vertexNum];
    for (int i = 0; i < vertexNum; i++)
        matrix[i] = new int[vertexNum];
    for (int i = 0; i < vertexNum; i++)
        for (int j = 0; j < vertexNum; j++)
            matrix[i][j] = 0;
}
template<typename T>
AMUndirGraph<T>::~AMUndirGraph()
{
    delete[]vexs;
    delete[]visited;
    for (int i = 0; i < vertexNum; i++)
        delete[]matrix[i];
    delete[]matrix;
}
template<typename T>
bool AMUndirGraph<T>::GetElem(int i, T& e)
{
    if (i < 0 || i >= vertexNum)
        return false;
    e = vexs[i];
    return true;
}
template<typename T>
bool AMUndirGraph<T>::SetElem(int i, T e)
{
    if (i<0 || i>vertexNum)
        return false;
    vexs[i] = e;
    return true;
}
template<typename T>
int AMUndirGraph<T>::GetVexNum()
{
    return vertexNum;
}
template<typename T>
int AMUndirGraph<T>::GetEdgeNum()
{
    return edgeNum;
}
template<typename T>
int AMUndirGraph<T>::FirstAdjVex(int i)
{
    if (i < 0 || i >= vertexNum)
        throw "参数不合法！";
    for (int j = 0; j < vertexNum; j++)
        if (matrix[i][j] == 1)
            return j;
    return -1;
}
template<typename T>
int AMUndirGraph<T>::NextAdjVex(int i, int j)
{
    if (i < 0 || i >= vertexNum || j < 0 || j >= vertexNum)
        throw "参数不合法！";
    if (i == j)
        throw "i不能等于j！";
    for (int k = j + 1; k < vertexNum; k++)
        if (matrix[i][k] == 1)
            return k;
    return -1;
}
template<typename T>
void AMUndirGraph<T>::InsertEdge(int i, int j)
{
    if (i < 0 || i >= vertexNum || j < 0 || j >= vertexNum)
        throw "参数不合法！";
    if (i == j)
        throw "i不能等于j";
    if (matrix[i][j] == 0 && matrix[j][i] == 0)
    {
        edgeNum++;
        matrix[i][j] = 1;
        matrix[j][i] = 1;
    }
}
template<typename T>
void AMUndirGraph<T>::DeleteEdge(int i, int j)
{
    if (i < 0 || i >= vertexNum || j < 0 || j >= vertexNum)
        throw "参数不合法！";
    if (i == j)
        throw "i不能等于j";
    if (matrix[i][j] == 1 && matrix[j][i] == 1)
    {
        edgeNum--;
        matrix[i][j] = 0;
        matrix[j][i] = 0;
    }
}
template<typename T>
void AMUndirGraph<T>::Display()
{
    for (int i = 0; i < vertexNum; i++)
    {
        cout << vexs[i];
        for (int j = 0; j < vertexNum; j++)
            cout << "\t" << matrix[i][j];
        cout << endl;
    }
}
