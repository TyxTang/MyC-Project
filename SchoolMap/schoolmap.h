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
#include "AmundirGraph.h"

using namespace std;

void Introduce();
void Introduce_each();
void Graph();

void cls(){
    system("cls");
}



void menumap(){
    int temp_1 = 1;
    while(temp_1 == 1){
        cls();
        cout<<"\t1.学校地点信息"<<endl;
        cout<<"\t2.查看学校地点介绍"<<endl;
        cout<<"\t3.显示邻接矩阵"<<endl;
        cout<<"\t4.查询地点之间最短的路径"<<endl;
        cout<<"\t5.查询地点之间的可行路径"<<endl;
        cout<<"\t6.返回上一个菜单"<<endl;
        cout<<"\t7.退出程序"<<endl;
        cout<<"****请选择功能序号：\t";

        int menumap_in;
        cin>> menumap_in;
        switch(menumap_in){
            case 1:{
                Introduce();
            }
            case 2:{
                Introduce_each();
            }
            case 3:{
                Graph();
            }
            //case 4:
            //case 5:
            //case 6:
            case 7:
                exit(0);
            default:{
                cout<<endl;
                cout<<endl;
                cout<<"输入有误！请重新输入"<<endl;
                cout<<endl;
                cout<<endl;
            }

        }
    }
}

void Introduce(){
    cls();
    cout<<"****学校地点信息****\t"<<endl;
    for(int i = 0;i<map.vertex;i++){
        cout<<"\t"<<i+1<<".\t"<<map.eachinf[i].name<<endl;
    }
    cout<<"****是否需要查看每个地点的介绍(y/n):";
    string temp_Introduce;
    cin>>temp_Introduce;
    if(temp_Introduce == "y"){
        Introduce_each();
        cout<<endl;
        cout<<endl;
    }
    else if(temp_Introduce == "n"){
        cout<<endl;
        cout<<endl;
        menumap();
    }
    else{
        cout<<"输入有误！请重新输入"<<endl;
        cout<<endl;
        cout<<endl;
        Introduce();
    }
}

void Introduce_each(){
    int ifIntroduce = 1;
    int temp_Introduce_each;
    while(ifIntroduce == 1){
        cls();
        cout << "****学校地点信息****\t" << endl;
        for (int i = 0; i < map.vertex; i++) {
            cout << "\t" << i + 1 << ".\t" << map.eachinf[i].name << endl;
        }
        cout << "\t请输入你想查看的地点序号：\t";
        cin >> temp_Introduce_each;
        cout<<endl;
        cout <<"\t"<< "地点：" << map.eachinf[temp_Introduce_each - 1].name << endl;
        cout <<"\t"<< "地点介绍：" << map.eachinf[temp_Introduce_each - 1].information << endl;
        cout<<endl;
        cout << "****是否需要继续查看(y/n):";
        string temp_Introduce_each_1;
        cin >> temp_Introduce_each_1;
        if (temp_Introduce_each_1 == "n") {
            ifIntroduce = 0;
            cout<<endl;
            cout<<endl;
            menumap();
        }
        else{
            cout<<endl;
            cout<<endl;
        }
    }
}

void Graph(){
    cout<<"****邻接矩阵****"<<endl;   //书P174
    for(int i = 0;i<map.vertex;i++){
        for(int j = 0;j<map.vertex;j++){
            cout<<map.edges[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;


    cout<<"****邻接表****"<<endl;   //书P175
    for(int i = 0;i<map.vertex;i++){
        cout<<i+1<<".\t"<<map.eachinf[i].name<<endl;
        for(int j = 0;j<map.vertex;j++){
            if(map.edges[i][j] != 0){
                cout<<"\t"<<j+1<<".\t"<<map.eachinf[j].name<<endl;
            }
        }
    }
    cout<<endl;
    cout<<endl;
}

