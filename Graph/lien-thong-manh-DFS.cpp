//
// Created by haind on 25/04/2019.
//

/*
 * Thuật toán:
 * 1. Áp dụng DFS trên G(Đồ thị đầu vào) ghi nhân thời gian kết thúc thăm f(v) đối với mỗi đỉnh v
 * 2. Xây dựng đồ thị bù Gs của G (tập đỉnh của Gs trùng với tập đỉnh của G, (u,v) thuộc G <=> v=(v,u) thuộc Gs
 * 3. Áp dụng DFS trên Gs thứ tự duyệt các đỉnh  giảm dần theo f(v)
 *    Mỗi lời gọi DFS(u) trên Gs sẽ thu tập các đỉnh của 1 thành phần liên thông mạnh của đồ thị G ban đầu
 */


//
// Created by haind on 18/04/2019.
//

#include <stdio.h>
#include <list>
#define MAX 100000


int N, M;
using namespace std;
list<int> A[MAX];
list<int> As[MAX];

int x[MAX], idx;
int d[MAX];
int f[MAX];
int p[MAX];
char color[MAX];
char colorAs[MAX];
int count;
int t;

void DFS(int u) {
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
    idx++;
    x[idx] = u;
    color[u] = 'B';
}

void init() {
    for (int i = 1; i <= N ; ++i) {
        color[i] = 'W';
        colorAs[i] ='W';
    }
    t=0;
    idx=0;
    count = 0;
}

void DFS() {
    init();
    for (int v = 1; v <=N ; ++v) {
        if(color[v]=='W'){
            DFS(v);
        }
    }
    for (int v = 1; v <= N ; ++v) {
        printf("v= %d, d= %d, f= %d, p= %d, color = %c \n", v, d[v], f[v], p[v], color[v]);
    }
}

void dfsAs(int u) {
    colorAs[u] = 'G';
    printf("%d ", u);
    for (list<int>::iterator it = As[u].begin(); it != As[u].end(); it++) {
        int v = *it;
        if (colorAs[v] == 'W') {
            dfsAs(v);
        }
    }
    // Da duyet xong
    colorAs[u] = 'B';
}

void dfsAs() {
    count = 0;
    for (int v = N; v >= 1 ; --v) {
        if(colorAs[x[v]]=='W'){
            printf("\n");
            count++;
            dfsAs(x[v]);
        }
    }
    printf("\n%d", count);
}

void input(const char* filename) {
    FILE * f = fopen(filename,"r");
    fscanf(f, "%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        int u,v;
        fscanf(f, "%d %d", &u, &v);
        A[u].push_back(v);
    }
    fclose(f);
}

void buildResidualGraph() {
    for (int u = 1; u <=N ; ++u) {
        for (list<int>::iterator it = A[u].begin(); it != A[u].end() ; it++) {
            int v = *it;
            As[v].push_back(u);
        }

    }
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




int main() {
    input("/home/haind/hust/applied-algorithm/Graph/lien-thong-manh-DFS.inp");
    buildResidualGraph();
    printGraph();
    DFS();
//    for (int i = 1; i <= N ; ++i) {
//        printf("%d ", x[i]);
//    }
//    printf("\n");
    dfsAs();
}