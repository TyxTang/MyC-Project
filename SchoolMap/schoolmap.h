//
// Created by TyxTang on 2022/11/28.
//

#ifndef SCHOOLMAP_SCHOOLMAP_H
#define SCHOOLMAP_SCHOOLMAP_H

#endif //SCHOOLMAP_SCHOOLMAP_H

#include<iostream>
#include<windows.h>
#include<cstdlib>
#include "Calculation.h"
using namespace std;

void menumap();
void Introduce_each();
void create();
void Introduce();
void Graph();
void SchoolDijkstra();
void SchoolFloyd();
void changepassword();

void cls() {
    system("cls");
}


void menumap()
{
    int temp_1 = 1;
    while (temp_1 == 1) {
        cls();
        cout << "***********校园导航系统***********" << endl;
        cout << endl << "\t1.学校地点信息" << endl;
        cout << endl << "\t2.查看学校地点介绍" << endl;
        cout << endl << "\t3.显示邻接矩阵" << endl;
        cout << endl << "\t4.查询地点之间最短的路径" << endl;
        cout << endl << "\t5.查询地点之间的可行路径" << endl;
        cout << endl << "\t6.退出程序" << endl;
        cout << endl << "小组:\t唐永翔、徐安" << endl;
        cout << endl << "请选择功能序号：\t";

        int menumap_in;
        cin >> menumap_in;
        switch (menumap_in) {
            case 1: {
                Introduce();
            }
            case 2: {
                Introduce_each();
            }
            case 3: {
                Graph();
            }
            case 4: {
                SchoolFloyd();
            }
            case 5: {
                SchoolDijkstra();
            }
            case 6:
                exit(0);
            default: {
                cout << endl;
                cout << endl;
                cout << "输入有误！请重新输入" << endl;
                cout << endl;
                cout << endl;
            }

        }
    }
}


void Introduce()
{
    cls();
    cout << "****学校地点信息****\t" << endl;
    for (int i = 0; i < map.vertex; i++) {
        cout << "\t" << i + 1 << ".\t" << map.eachinf[i].name << endl;
    }
    cout << "****是否需要查看每个地点的介绍(y/n):";
    string temp_Introduce;
    cin >> temp_Introduce;
    if (temp_Introduce == "y") {
        Introduce_each();
        cout << endl;
        cout << endl;
    }
    else if (temp_Introduce == "n") {
        cout << endl;
        cout << endl;
        menumap();
    }
    else {
        cout << "输入有误！请重新输入" << endl;
        cout << endl;
        cout << endl;
        Introduce();
    }
}

void Introduce_each() {
    int ifIntroduce = 1;
    int temp_Introduce_each;
    while (ifIntroduce == 1) {
        cls();
        cout << "****学校地点信息****\t" << endl;
        for (int i = 0; i < map.vertex; i++) {
            cout << "\t" << i + 1 << ".\t" << map.eachinf[i].name << endl;
        }
        cout << "\t请输入你想查看的地点序号：\t";
        cin >> temp_Introduce_each;
        cout << endl;
        cout << "\t" << "地点：" << map.eachinf[temp_Introduce_each - 1].name << endl;
        cout << "\t" << "地点介绍：" << map.eachinf[temp_Introduce_each - 1].information << endl;
        cout << endl;
        cout << "****是否需要继续查看(y/n):";
        string temp_Introduce_each_1;
        cin >> temp_Introduce_each_1;
        if (temp_Introduce_each_1 == "n") {
            ifIntroduce = 0;
            cout << endl;
            cout << endl;
            menumap();
        }
        else {
            cout << endl;
            cout << endl;
        }
    }
}

void Graph() {
    cout << "****邻接矩阵****" << endl;   //书P174
    for (int i = 0; i < map.vertex; i++) {
        for (int j = 0; j < map.vertex; j++) {
            cout << map.edges[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    cout << "看完了，";
    system("pause");
    menumap();

}

void SchoolDijkstra()
{
    int ifSchoolDijkstra = 1;
    cls();
    cout << "****学校地点信息****\t" << endl;
    for (int i = 0; i < map.vertex; i++) {
        cout << "\t" << i + 1 << ".\t" << map.eachinf[i].name << endl;
    }
    int now;
    cout << "请输入现在的位置：" ;
    cin >> now;
    cout << endl;
    int edge_now[100];
    int MinRoad[100];
    int last[100];
    int i, j, k, min, pre;
    edge_now[now - 1] = 1;
    for (i = 0; i < map.vertex; i++)
    {
        MinRoad[i] = map.edges[now - 1][i];
        last[i] = now - 1;
        edge_now[i] = 0;
    }
    MinRoad[now - 1] = 0;
    edge_now[now - 1] = 1;
    last[now - 1] = -1;
    for (i = 0; i < map.vertex; i++)
    {
        min = 99999 + 1;
        for (k = 1; k < map.vertex; k++)
        {
            if (edge_now[k] == 0 && MinRoad[k] < min)
            {
                j = k;
                min = MinRoad[k];
            }
        }
        edge_now[j] = 1;
        for (k = 0; k < map.vertex; k++)
        {
            if (edge_now[k] == 0 && (MinRoad[j] + map.edges[j][k] < MinRoad[k]))
            {
                MinRoad[k] = MinRoad[j] + map.edges[j][k];
                last[k] = j;
            }
        }
    }
    int flag = 1;
    int mid;
    for (i = 0; i < map.vertex; i++)
    {
        if (i != now - 1)
        {
            if (MinRoad[i] != 99999)
            {
                flag = 0;
                cout << MinRoad[i] << "米,路径为:  " << map.eachinf[i].name;
                pre = last[i];
                mid = i;
                while (pre >= 0)
                {
                    cout << " ← " << map.eachinf[pre].name;
                    mid = pre;
                    pre = last[pre];
                }
                cout << endl;
            }
        }
    }
    cout << endl;
    cout << "****是否需要继续查看(y/n):";
    string temp_SchoolDijkstra_each_1;
    cin >> temp_SchoolDijkstra_each_1;
    if (temp_SchoolDijkstra_each_1 == "n") {
        ifSchoolDijkstra = 0;
        cout << endl;
        cout << endl;
        menumap();
    }
    else {
        cout << endl;
        cout << endl;
        SchoolDijkstra();
    }
}


void SchoolFloyd()
{
    int ifSchoolFloyd = 1;
    cls();
    cout << "****学校地点信息****\t" << endl;
    for (int i = 0; i < map.vertex; i++) {
        cout << "\t" << i + 1 << ".\t" << map.eachinf[i].name << endl;
    }
    int this_weizhi;
    int that_weizhi;
    cout << "请输入你从哪里出发: ";
    cin >> this_weizhi;
    cout << "请输入你到哪里： ";
    cin >> that_weizhi;
    cout << endl;
    int edge_now[100];
    int MinRoad[100];
    int last[100];
    int i, j, k, min, pre;
    edge_now[this_weizhi - 1] = 1;
    for (i = 0; i < map.vertex; i++)
    {
        MinRoad[i] = map.edges[this_weizhi - 1][i];
        last[i] = this_weizhi - 1;
        edge_now[i] = 0;
    }
    MinRoad[this_weizhi - 1] = 0;
    edge_now[this_weizhi - 1] = 1;
    last[this_weizhi - 1] = -1;
    int K = 0, mid = this_weizhi - 1;
    for (i = 0; i < map.vertex; i++)
    {
        min = 99999 + 1;
        for (k = 1; k < map.vertex; k++)
        {
            if (edge_now[k] == 0 && MinRoad[k] < min)
            {
                j = k;
                min = MinRoad[k];
            }
        }
        edge_now[j] = 1;
        for (k = 0; k < map.vertex; k++)
        {
            if (edge_now[k] == 0 && (MinRoad[j] + map.edges[j][k] < MinRoad[k]))
            {
                MinRoad[k] = MinRoad[j] + map.edges[j][k];
                last[k] = j;
            }
        }
    }
    cout << map.eachinf[that_weizhi - 1].name << " 到 " << map.eachinf[this_weizhi - 1].name << " 最短距离为: " << MinRoad[that_weizhi - 1] << "米" << endl;
    pre = last[that_weizhi - 1];
    int pre1 = pre;

    cout << "路径是：" << map.eachinf[that_weizhi - 1].name;
    while (pre >= 0)
    {
        cout << " ← " << map.eachinf[pre].name;
        mid = pre;
        pre = last[pre];
    }
    cout << endl;
    cout << "****是否需要继续查看(y/n):";
    string temp_SchoolFloyd_each_1;
    cin >> temp_SchoolFloyd_each_1;
    if (temp_SchoolFloyd_each_1 == "n") {
        ifSchoolFloyd = 0;
        cout << endl;
        cout << endl;
        menumap();
    }
    else {
        cout << endl;
        cout << endl;
        SchoolFloyd();
    }

}