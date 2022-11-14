//
// Created by TyxTang on 2022/11/14.
//

#ifndef HOSPITAL_HOSPITAL_H
#define HOSPITAL_HOSPITAL_H

#endif //HOSPITAL_HOSPITAL_H

#define infinity 100;
class Hospital {
private:
    int vertexNum;
    char * vexs;
    int ** matrix;
public:
    Hospital(char vs[],int ** edge,int n);
    ~Hospital();
    void Floyd(int ** dist);
    int Center();
};

Hospital::Hospital(char vs[],int ** edge,int n) {
    vertexNum = n;
    vexs = new char[vertexNum];
    for (int i = 0; i < vertexNum; i++) {
        vexs[i] = vs[i];
    }
    matrix = (int **) new int*[vertexNum];
    for (int i = 0; i < vertexNum; i++) {
        matrix[i] = new int[vertexNum];
    }
    for(int i = 0; i < vertexNum; i++) {
        for (int j = 0; j < vertexNum; j++) {
            matrix[i][j] = edge[i][j];
        }
    }
}

Hospital::~Hospital() {
    delete [] vexs;
    for (int i = 0; i < vertexNum; i++) {
        delete [] matrix[i];
    }
    delete [] matrix;
}

void Hospital::Floyd(int **dist) {
    int i,j,k;
    for (i = 0; i < vertexNum; i++) {
        for (j = 0; j < vertexNum; j++) {
            dist[i][j] = matrix[i][j];
        }
    }
    for (k = 0; k < vertexNum; k++) {
        for (i = 0; i < vertexNum; i++) {
            for (j = 0; j < vertexNum; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int Hospital::Center() {
    int i,j,index,min;
    int * maxdist = new int[vertexNum];
    int ** dist = (int **) new int*[vertexNum];
    for(int i = 0; i < vertexNum; i++) {
        dist[i] = new int[vertexNum];
    }
    Floyd(dist);
    for(int i = 0; i < vertexNum; i++) {
        maxdist[i] = 0;
        for (j = 0; j < vertexNum; j++) {
            if (dist[i][j] > maxdist[i]) {
                maxdist[i] = dist[i][j];
            }
        }
    }
    min = maxdist[0];
    index = 0;
    for (i = 1; i < vertexNum; i++) {
        if (maxdist[i] < min) {
            min = maxdist[i];
            index = i;
        }
    }
    delete [] maxdist;
    for (int i = 0; i < vertexNum; i++) {
        delete [] dist[i];
    }
    delete [] dist;
    return index;
}