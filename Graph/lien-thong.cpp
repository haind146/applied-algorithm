//
// Created by haind on 18/04/2019.
//

#include <stdio.h>
#include <list>
#define MAX 100000

int N, M;
using namespace std;
list<int> A[MAX];

int d[MAX];
int f[MAX];
int p[MAX];
char color[MAX];
int t;
int nbCC, idxCC[MAX];


void DFS(int u) {
    idxCC[u] = nbCC;
    t = t + 1;
    d[u] = t;
    color[u] = 'G';
    for (list<int>::iterator it = A[u].begin(); it != A[u].end(); it++) {
        int v = *it;
        if (color[v] == 'W') {
            p[v] = u;
            DFS(v);
        }
    }
    // Da duyet xong
    t=t+1;
    f[u] = t;
    color[u] = 'B';
}

void init() {
    for (int i = 1; i <= N ; ++i) {
        color[i] = 'W';
    }
    t=0;
}

void DFS() {
    init();
    nbCC = 0;
    for (int v = 1; v <=N ; ++v) {
        if(color[v]=='W'){
            nbCC++;
            DFS(v);

        }
    }
    for (int v = 1; v <= N ; ++v) {
        printf("v= %d, d= %d, f= %d, p= %d, color = %c \n", v, d[v], f[v], p[v], color[v]);
    }
}

void input(const char* filename) {
    FILE * f = fopen(filename,"r");
    fscanf(f, "%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u,v;
        fscanf(f, "%d %d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);

    }
    fclose(f);
}

void printGraph() {
    for (int v = 1; v <= N ; ++v) {
        printf("A[%d]: ", v);
        for ( list<int>::iterator it = A[v].begin(); it!=A[v].end(); it++) {
            int x = *it;
            printf("%d ", x);
        }
        printf("\n");

    }
}

void printConnectedComponent() {
    for (int i = 1; i <= nbCC ; ++i) {
        printf("Thanh phan lien thong thu %d: ", i);
        for (int v = 1; v <=N ; ++v) {
            if (idxCC[v] == i) {
                printf("%d ", v);
            }
        }
        printf("\n");
    }
}



int main() {
    input("/home/haind/hust/applied-algorithm/Graph/lien-thong.inp");
    printGraph();
    DFS();
    printConnectedComponent();
}