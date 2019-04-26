//
// Created by haind on 25/04/2019.
//

/*
 * Cho đồ thị có hướng G=(V,E)
 * Hãy đưa ra thứ tự các đỉnh sao cho với mỗi cung (u,v) thì u đứng trước v
 */


#include <stdio.h>
#include <list>
#define MAX 100000

#include <queue>
using namespace std;

int N, M;
using namespace std;
list<int> A[MAX];
list<int> As[MAX];

bool isRemoved[MAX];

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

void removeVertex(int u) {
    for (list<int>::iterator it = A[u].begin(); it != A[u].end() ; it++) {
        int v = *it;
        As[v].remove(u);
    }
}



void solve() {
    input("/home/haind/hust/applied-algorithm/Graph/TOPO-sort.inp");
    buildResidualGraph();
    queue<int> Q;
    for (int i = 1; i <= N ; ++i) {
        Q.push(i);
    }
    int pivot = Q.back();
    while (!Q.empty()) {
        int v = Q.front();
        if(As[v].empty()) {
            Q.pop();
            removeVertex(v);
            printf("%d ", v);
            pivot = Q.back();
        } else {
            Q.pop();
            Q.push(v);
            if (pivot == v) {
                printf("-1");
                break;
            }
        }
    }
}

int main() {
    solve();
}