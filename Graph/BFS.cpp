//
// Created by haind on 18/04/2019.
//

/*
 * Cho đồ thị G=(V,E) và 2 điểm s, t. Tìm đường đi ngắn nhất từ s đến t bằng BFS
 */

#include <stdio.h>
#include <queue>
#include <list>
#define MAX 10000
using namespace std;

list<int> A[MAX];
int p[MAX]; //dinh p[a] là đỉnh đi trước đỉnh a
int d[MAX]; // do sau khi duyet cua nut
char color[MAX];
int N, M;
int s, t;

using namespace std;

void input(const char * filename) {
    FILE * f = fopen(filename,"r");
    fscanf(f, "%d %d", &s, &t);
    fscanf(f, "%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u,v;
        fscanf(f, "%d %d", &u, &v);
        A[u].push_back(v);
        A[v].push_back(u);

    }
    fclose(f);
}

void init() {
    for (int i = 1; i <= N ; ++i) {
        p[i] =0;
        d[i] =0;
        color[i] = 'W';
    }
}


void BFS(int u) {
    init();
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    color[u] = 'G';
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (list<int>::iterator it = A[v].begin(); it!= A[v].end(); it++) {
            int x = *it;
            if(color[x] == 'W') {
                Q.push(x);
                color[x] = 'G';
                p[x] = v;
                d[x] = d[v]+1;
            }

        }
    }
}


void printShortestPath(int a,int b) {
    BFS(a);
    if(p[b] == 0) printf("khong co duong di tu s -> t");
    else {
        printf("duong di ngan nhat tu s den t la %d: ", d[b]);
        int iter = b;
        printf("%d ", b);
        while (p[iter] != a) {
            printf("%d ", p[iter]);
            iter = p[iter];
        }
        printf("%d", a);
    }
}

int main() {
    input("/home/haind/hust/applied-algorithm/Graph/shortest-path-BFS.inp");
    printShortestPath(1, 6);
}