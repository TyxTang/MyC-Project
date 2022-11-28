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



void cls(){
    system("cls");
}



void menumap(){
    int temp_1 = 1;
    while(temp_1 == 1){
        cls();
        cout<<"\t1.学校地点信息"<<endl;
        cout<<"\t2.查看学校地点介绍"<<endl;
        cout<<"\t3.查询地点之间最短的路径"<<endl;
        cout<<"\t4.查询地点之间的可行路径"<<endl;
        cout<<"\t5.返回上一个菜单"<<endl;
        cout<<"\t6.退出程序"<<endl;
        cout<<"****请选择功能序号：\t";

        int menumap_in;
        cin>> menumap_in;
        switch(menumap_in){
            case 1:{
                cls();
                cout<<"\t****学校地点信息****\t"<<endl;
                for(int i = 0;i<map.vertex;i++){
                    cout<<"\t"<<i+1<<".\t"<<map.eachinf[i].name<<endl;
                }
            }
            //case 2:
            //case 3:
            //case 4:
            //case 5:
            case 6:
                exit(0);
            default:
                cout<<"输入有误！请重新输入"<<endl;
        }
    }
}

void Introduce(){

}