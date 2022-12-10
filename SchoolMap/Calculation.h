//
// Created by TyxTang on 2022/11/28.
//

#ifndef SCHOOLMAP_CALCULATION_H
#define SCHOOLMAP_CALCULATION_H

#endif //SCHOOLMAP_CALCULATION_H


#include <string.h>
#pragma warning(disable:4996)
typedef struct
{
    char name[100];
    char information[1000];
} SchoolInf;

typedef struct
{
    SchoolInf eachinf[100];
    int edges[100][100];
    int vertex, edge;
} MGraph;
static MGraph map;

void create()
{
    map.vertex = 13;
    map.edge = 22;
    int i, j, k;
    for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            map.edges[i][j] = 99999;
        }
    }

    strcpy(map.eachinf[0].name, "大门");
    strcpy(map.eachinf[0].information, "学校的大门");
    strcpy(map.eachinf[1].name, "教学楼");
    strcpy(map.eachinf[1].information, "钟楼");
    strcpy(map.eachinf[2].name, "实验楼A");
    strcpy(map.eachinf[2].information, "平时上课的实验楼");
    strcpy(map.eachinf[3].name, "实验楼B");
    strcpy(map.eachinf[3].information, "以前的艺术楼");
    strcpy(map.eachinf[4].name, "图书馆");
    strcpy(map.eachinf[4].information, "学校的图书馆");
    strcpy(map.eachinf[5].name, "知远楼");
    strcpy(map.eachinf[5].information, "高级的实验楼");
    strcpy(map.eachinf[6].name, "操场");
    strcpy(map.eachinf[6].information, "学校的操场");
    strcpy(map.eachinf[7].name, "厚德楼");
    strcpy(map.eachinf[7].information, "学校的厚德楼");
    strcpy(map.eachinf[8].name, "进德楼");
    strcpy(map.eachinf[8].information, "学校的进德楼");
    strcpy(map.eachinf[9].name, "齐家苑");
    strcpy(map.eachinf[9].information, "学校的齐家苑");
    strcpy(map.eachinf[10].name, "翰林园");
    strcpy(map.eachinf[10].information, "学校的翰林园");
    strcpy(map.eachinf[11].name, "学林楼");
    strcpy(map.eachinf[11].information, "学校的学林楼");
    strcpy(map.eachinf[12].name, "学翰楼");
    strcpy(map.eachinf[12].information, "学校的学翰楼");
    strcpy(map.eachinf[13].name, "怡馨苑");
    strcpy(map.eachinf[13].information, "学校的怡馨苑");
    strcpy(map.eachinf[14].name, "和馨苑");
    strcpy(map.eachinf[14].information, "学校的和馨苑");
    strcpy(map.eachinf[15].name, "桐桦楼");
    strcpy(map.eachinf[15].information, "学校的桐桦楼");
    strcpy(map.eachinf[16].name, "学海楼");
    strcpy(map.eachinf[16].information, "学校的学海楼");

    map.edges[0][1] = map.edges[1][0] = 50;      //大门到教学楼
    map.edges[0][2] = map.edges[2][0] = 60;       //大门到实验楼A
    map.edges[2][3] = map.edges[3][2] = 70;       //实验楼A到实验楼B
    map.edges[3][4] = map.edges[4][3] = 70;       //实验楼B到图书馆
    map.edges[1][4] = map.edges[4][1] = 100;      //教学楼到图书馆
    map.edges[2][5] = map.edges[5][2] = 10;       //实验楼A到知远楼
    map.edges[3][5] = map.edges[5][3] = 10;       //实验楼B到知远楼
    map.edges[4][6] = map.edges[6][4] = 80;       //图书馆到操场
    map.edges[4][7] = map.edges[7][4] = 275;      //图书馆到厚德楼
    map.edges[4][8] = map.edges[8][4] = 275;      //图书馆到进德楼
    map.edges[7][8] = map.edges[8][7] = 50;       //厚德楼到进德楼
    map.edges[8][11] = map.edges[11][8] = 150;    //进德楼到学林楼
    map.edges[11][9] = map.edges[9][11] = 50;     //学林楼到齐家苑
    map.edges[11][10] = map.edges[10][11] = 100;  //学林楼到翰林园
    map.edges[11][13] = map.edges[13][11] = 100;  //学林楼到怡馨苑
    map.edges[11][15] = map.edges[15][11] = 80;   //学林楼到桐桦楼
    map.edges[11][6] = map.edges[6][11] = 30;     //学林楼到操场
    map.edges[6][15] = map.edges[15][6] = 50;     //操场到桐桦楼
    map.edges[6][8] = map.edges[8][6] = 50;       //操场到进德楼
    map.edges[13][15] = map.edges[15][13] = 30;   //怡馨苑到桐桦楼
    map.edges[13][10] = map.edges[10][13] = 40;   //怡馨苑到翰林园
    map.edges[9][10] = map.edges[10][9] = 100;    //齐家苑到翰林园
    map.edges[9][14] = map.edges[14][9] = 100;    //齐家苑到和馨苑
    map.edges[10][12] = map.edges[12][10] = 5;    //翰林园到学翰楼
    map.edges[10][14] = map.edges[14][10] = 20;   //翰林园到和馨苑
    map.edges[12][16] = map.edges[16][12] = 10;   //学翰楼到学海楼
}
